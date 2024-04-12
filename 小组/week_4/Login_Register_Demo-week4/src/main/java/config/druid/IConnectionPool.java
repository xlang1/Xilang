package config.druid;

import java.sql.Connection;

/**
 * 连接池接口
 */
//该类中包含一个数据库连接，一个是否使用的标记以及一个close方法，用来将该连接置为可用状态，
// 从而达到数据库连接的可复用，减少持续创建新连接的资源消耗
public interface IConnectionPool {

    //从连接池中拿一个连接对象
    Connection getConn();

    //把连接池对象归还到连接池
    void releaseConn(Connection connection);
}
