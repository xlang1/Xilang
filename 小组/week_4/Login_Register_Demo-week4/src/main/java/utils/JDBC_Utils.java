package utils;

import config.druid.DataSourceManger;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;


public class JDBC_Utils {
    //连接路径，用户名，密码，设置为常量，方便使用
//    public static final String URL = "jdbc:mysql://localhost:3306/db";
//    public static final String USERNAME = "root";
//    public static final String PASSWORD = "43816729lxlLXL!";
//    public static final String driver = "com.mysql.cj.jdbc.Driver";

    //1.加载驱动

    // 加载驱动只需要一次，则放在静态代码块中
//    static {
//        try {
//            Class.forName(driver);
//        } catch (Exception e) {
//            e.printStackTrace();
//            /*e.printStackTrace()将错误信息全部打印至控制台上展示*/
//        }
//    }

    //2.创建连接

    public static Connection getConn() {
        Connection conn = null;
        // try {
        //conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);
        //利用数据库连接池获取连接，创建连接在数据库中已经创建
        conn = DataSourceManger.getConn();
        // } catch (SQLException e) {
        //  e.printStackTrace();
        //}
        return conn;
    }

    //3.增加数据方法

    //参数    sql语句为参数，使其变得通用，sql语句中 ？ 是占位符，所代表的参数用数组表示，Object可以存任意类型
    //返回值  executeUpdate 返回的是受影响行数，要成功至少是1，失败返回-1，返回也可以是Boolean类型
    public static int update(String sql, Object[] params) {
        //调用方法获取conn连接对象
        Connection conn = getConn();
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement(sql);
            //向sql语句中设置参数
            setParam(ps, params);
            //执行sql语句
            return ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //调用关闭方法，释放资源
            closeAll(null, ps, conn);
        }
        return -1;
    }

    //4.设置参数的方法。

    public static void setParam(PreparedStatement ps, Object[] params) {
        try {
            if (params != null) {
                for (int i = 0; i < params.length; i++) {
                    ps.setObject(i + 1, params[i]);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }


    //5.通用的关闭，释放资源的方法
    //参数   有返回结果集对象功能的ResultSet，有预编译功能的PreparedStatement，有创建连接的Connection
    //无返回值
    public static void closeAll(ResultSet set, PreparedStatement ps, Connection conn) {
        try {
            if (set != null) {
                set.close();
            }
            if (ps != null) {
                ps.close();
            }
            if (conn != null) {
                //conn.close();
                //调用数据库连接池的方法回收连接
                DataSourceManger.close(conn);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    //6.查询数据，做传储
    //List<List>   list嵌套
    //参数   sql,Object...
    //Object...  表示不定个数的参数  相当于数组，此参数在传递时，不传也不会报错，上面的方法也可以改成如此

    public static List<List> queryList(String sql, Object... params) {
        //创建连接
        Connection conn = getConn();
        //获取执行sql语句的对象，有预编译
        PreparedStatement ps = null;
        //结果集
        ResultSet set = null;
        try {
            //连接
            ps = conn.prepareStatement(sql);
            //设置参数
            setParam(ps, params);
            //执行sql
            //executeQuery：使用 SELECT 语句查询，返回单个结果集 ResultSet
            set = ps.executeQuery();
            //获取表的元数据信息
            ResultSetMetaData metaData = set.getMetaData();
            //创建大List，用于储存所有数据
            ArrayList<List> lists = new ArrayList<>();
            while (set.next()) {
                //Object可以存任意类型数据
                //创建小的List用于存放每一行数据，在循环中每次都可更新
                ArrayList<Object> list = new ArrayList<>();
                //通过循环把每一行中每一个数据都存如List中
                for (int i = 0; i < metaData.getColumnCount(); i++) {
                    list.add(set.getObject(i + 1));
                }
                //把小的list添加到大的中
                lists.add(list);
            }
            return lists;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        //有问题时
        return null;
    }


}
