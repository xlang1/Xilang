package config.druid;

import java.sql.Connection;

public class ConnectionEntity {
    private Connection connection;//连接对象
    private Long userStartTime;//开始使用时间（时间戳）

    public ConnectionEntity(Connection connection, Long userStartTime) {
        this.connection = connection;
        this.userStartTime = userStartTime;
    }

    public ConnectionEntity() {
    }

    public Connection getConnection() {
        return connection;
    }

    public void setConnection(Connection connection) {
        this.connection = connection;
    }

    public Long getUserStartTime() {
        return userStartTime;
    }

    public void setUserStartTime(Long userStartTime) {
        this.userStartTime = userStartTime;
    }
}
