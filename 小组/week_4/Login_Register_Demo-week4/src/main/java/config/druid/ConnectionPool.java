package config.druid;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Timer;
import java.util.TimerTask;
import java.util.Vector;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * 连接池实现类
 */
public class ConnectionPool implements IConnectionPool {

    //记录连接总数(计数器)
    AtomicInteger connectionCount = new AtomicInteger(0);

    //连接池配置信息
    private DataSourceConfig dataSourceConfig;

    /**
     * 声明一个线程安全的集合list集合，存储空闲的连接
     * ArrayList线程不安全
     * Vector线程安全
     */
    Vector<Connection> freePools = new Vector<Connection>();

    /**
     * 声明一个线程安全的集合list集合，存储正在使用的连接
     * ArrayList线程不安全
     * Vector线程安全
     * ConnectionEntity 存有连接和时间
     * 方便之后超时操作：开始使用时间-当前时间  与waitTime比较看是否超时
     */
    Vector<ConnectionEntity> usePools = new Vector<ConnectionEntity>();

    //拿到连接池配置信息
    public ConnectionPool(DataSourceConfig dataSourceConfig) {
        this.dataSourceConfig = dataSourceConfig;
        //初始化连接池
        init();
    }

    //连接池的连接初始化
    private void init() {
        //按照配置的初始化连接数创建
        for (int i = 0; i < Integer.valueOf(dataSourceConfig.getInitialSize()); i++) {
            Connection connection = createConnection();
            //测试语句
            //System.out.println("连接池初始化，连接对象：" + connection);
            freePools.add(connection);
        }
        if (Boolean.valueOf(dataSourceConfig.getHealth()) == true) {
            checkConnectionTimeOut();
        }
    }

    /**
     * 定时检查占用时间超长的连接，并关闭
     * 企业级计时器：Quartz、Spring Task、xxlJob
     */
    private void checkConnectionTimeOut() {
        Worker worker = new Worker();
        //调度任务   启动完毕后2秒开始后台检测，每间隔2秒检测一次
        new Timer().schedule(worker, Long.valueOf(dataSourceConfig.getDelay()), Long.valueOf(dataSourceConfig.getPeriod()));
    }

    /**
     * 局部内部内-任务类
     * TimerTask jdk自带的工具类
     */
    class Worker extends TimerTask {
        public void run() {
            //测试语句
            //会在后台检查，两秒一次
            //System.out.println("定时检查占用时间超长的连接，并关闭");
            try {
                //遍历正在使用的连接池，判断是否有超时的操作
                for (int i = 0; i < usePools.size(); i++) {
                    ConnectionEntity connectionEntity = usePools.get(i);
                    if (System.currentTimeMillis() - connectionEntity.getUserStartTime() > Long.valueOf(dataSourceConfig.getMaxWait())) {
                        //有conn对象使用超过了设置的超时时间
                        //拿到该连接
                        Connection connection = connectionEntity.getConnection();
                        //判断是否可用
                        if (isAvailable(connection)) {
                            connection.close();
                            //根据索引直接关闭删除
                            usePools.remove(i);
                            connectionCount.decrementAndGet();//总数减一
                            //测试语句
                            //System.out.println(Thread.currentThread().getName() + "定时检查占用时间超长的连接connection：" + connection + "直接关闭删除,空闲连接池的大小是：" + freePools.size() + "，正在使用的连接池大小是：" + usePools.size() + "总连接是：" + connectionCount);
                        }
                    }

                }
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }

    //创建连接池
    private synchronized Connection createConnection() {
        Connection connection = null;
        try {
            //加载驱动
            Class.forName(dataSourceConfig.getDriver());
            //创建连接
            connection = DriverManager.getConnection(dataSourceConfig.getUrl(), dataSourceConfig.getUsername(), dataSourceConfig.getPassword());
            connectionCount.incrementAndGet();//连接总数加一，累加一
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return connection;
    }

    /**
     * 从连接池中获取一个对象
     */
    @Override
    public synchronized Connection getConn() {
        Connection connection = null;
        try {
            //判断空闲的连接池中是否还有连接
            if (!freePools.isEmpty()) {
                //空闲连接池非空
                connection = freePools.get(0);
                if (isAvailable(connection)) {
                    freePools.remove(connection);
                    //加入到正在使用的连接集合中                                           当前系统时间--userStartTime开始使用时间
                    ConnectionEntity connectionEntity = new ConnectionEntity(connection, System.currentTimeMillis());
                    usePools.add(connectionEntity);
                }
                //测试语句
                //System.out.println(Thread.currentThread().getName() + "从空闲连接池获取了一个连接：" + connection + ",空闲连接池的大小是：" + freePools.size() + "，正在使用的连接池大小是：" + usePools.size() + "总连接是：" + connectionCount);
            } else {
                //空闲的连接池中没有连接可以用了，要新创建，但是不能超过最大数
                if (connectionCount.get() < Integer.valueOf(dataSourceConfig.getMaxSize())) {
                    connection = createConnection();
                    //创建连接给要使用的连接集合中直接拿来用                                当前系统时间--userStartTime开始使用时间
                    ConnectionEntity connectionEntity = new ConnectionEntity(connection, System.currentTimeMillis());
                    usePools.add(connectionEntity);
                    //测试语句
                    //System.out.println(Thread.currentThread().getName() + "连接池没有连接了：" + connection + ",空闲连接池的大小是：" + freePools.size() + "，正在使用的连接池大小是：" + usePools.size() + "总连接是：" + connectionCount);
                } else {
                    //测试语句
                    //System.out.println(Thread.currentThread().getName() + "连接数已经超过了总大小，请进行等待，空闲池大小：" + connection + ",空闲连接池的大小是：" + freePools.size() + "，正在使用的连接池大小是：" + usePools.size() + "总连接是：" + connectionCount);
                    //等待空闲的连接
                    //在线程获取到锁后，调用锁对象的本方法，线程释放锁并且把该线程放置到与锁对象关联的等待队列（等待线程池）
                    //指定的毫秒数，如果超过指定时间则自动把该线程从等待队列中移出
                    this.wait(Integer.valueOf(dataSourceConfig.getWaitTime()));//this和synchronized有关（同步代码，同步方法）
                    //获取连接重试（递归唤醒等待）
                    connection = getConn();
                }
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return connection;
    }

    //判断当前连接是否可用
    private boolean isAvailable(Connection connection) {
        try {
            //连接不为空            连接没有关闭
            if (connection != null && !connection.isClosed()) {
                return true;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return false;
    }

    @Override
    public synchronized void releaseConn(Connection connection) {
        //判断连接可不可以用
        if (isAvailable(connection)) {
            //连接可用，放入空闲连接集合
            freePools.add(connection);
            //遍历正在使用连接集合，找到并移除其中的那个连接
            for (int i = 0; i < usePools.size(); i++) {
                //获取集合中ConnectionEntity对象不是Connection了
                Connection conn = usePools.get(i).getConnection();
                if (conn == connection) {
                    usePools.remove(i);//根据索引移除
                    //usePools.remove(connection);//直接除
                }
            }
            //测试语句
            //System.out.println(Thread.currentThread().getName() + "归还了一个连接：" + connection + ",空闲连接池的大小是：" + freePools.size() + "，正在使用的连接池大小是：" + usePools.size() + "总连接是：" + connectionCount);
        }
        this.notifyAll();//可以将线程池中的所有wait() 线程都唤醒
    }
}
