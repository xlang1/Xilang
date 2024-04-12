package config.druid;

import java.lang.reflect.Field;
import java.util.Properties;
import java.util.Set;

/**
 * 读取数据库配置文件后，封装一个配置类
 */
public class DataSourceConfig {
    private String driverClassName;
    private String url;
    private String username;
    private String password;
    private String initialSize;
    private String maxSize;
    private String maxWait;
    private String health;
    private String delay;
    private String period;
    private String waitTime;

    public DataSourceConfig() {
        try {
            //加载配置文件
            Properties properties = new Properties();
            properties.load(DataSourceConfig.class.getClassLoader().getResourceAsStream("druid.properties"));
            //读取配置文件中的key
            Set<Object> keyset = properties.keySet();
            //遍历给key赋值value
            for (Object key : keyset) {
                //获取名称
                String filedName = key.toString();
                //获取值
                String filedValue = properties.getProperty(key.toString());
                //利用反射暴力赋值
                //获取类的一个成员变量（存在就可以拿到）
                Field field = this.getClass().getDeclaredField(filedName);
                //禁止检查访问控制
                field.setAccessible(true);
                //赋值
                field.set(this, filedValue);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public String getDriver() {
        return driverClassName;
    }

    public void setDriver(String driver) {
        this.driverClassName = driverClassName;
    }

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getInitialSize() {
        return initialSize;
    }

    public void setInitialSize(String initialSize) {
        this.initialSize = initialSize;
    }

    public String getMaxSize() {
        return maxSize;
    }

    public void setMaxSize(String maxSize) {
        this.maxSize = maxSize;
    }

    public String getMaxWait() {
        return maxWait;
    }

    public void setMaxWait(String maxWait) {
        this.maxWait = maxWait;
    }

    public String getHealth() {
        return health;
    }

    public void setHealth(String health) {
        this.health = health;
    }

    public String getDelay() {
        return delay;
    }

    public void setDelay(String delay) {
        this.delay = delay;
    }

    public String getPeriod() {
        return period;
    }

    public void setPeriod(String period) {
        this.period = period;
    }

    public String getWaitTime() {
        return waitTime;
    }

    public void setWaitTime(String waitTime) {
        this.waitTime = waitTime;
    }

    @Override
    public String toString() {
        return "DataSourceConfig{" +
                "driverClassName='" + driverClassName + '\'' +
                ", url='" + url + '\'' +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", initialSize='" + initialSize + '\'' +
                ", maxSize='" + maxSize + '\'' +
                ", maxWait='" + maxWait + '\'' +
                ", health='" + health + '\'' +
                ", delay='" + delay + '\'' +
                ", period='" + period + '\'' +
                ", waitTime='" + waitTime + '\'' +
                '}';
    }
}
