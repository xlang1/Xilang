package config.druid;

import java.sql.Connection;

/**
 * 数据源管理器，对外公开可调用
 */
public class DataSourceManger {
    static DataSourceConfig dataSourceConfig = new DataSourceConfig();
    static ConnectionPool connectionPool=new ConnectionPool(dataSourceConfig);

    /**
     * 从连接池中获取一个连接
     */
    public static Connection getConn(){
        return connectionPool.getConn();
    }

    /**
     * 关闭一个数据库连接（伪关闭，实则回收）
     */
    public static void close(Connection connection){
        connectionPool.releaseConn(connection);
    }
}
