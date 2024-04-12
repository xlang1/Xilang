package configDruidTest;

import config.druid.ConnectionPool;
import config.druid.DataSourceConfig;
import config.druid.DataSourceManger;
import org.junit.Test;

import java.sql.Connection;

public class TestDataSourceConfig {

    public static void main(String[] args) {
        Thead1 t = new Thead1();
        for (int i = 0; i < 8; i++) {
            new Thread(t, "线程" + i).start();
        }
    }

}

class Thead1 implements Runnable {

    public void run() {
        try {
            //获取连接
            Connection conn = DataSourceManger.getConn();
            //模拟正在拿到连接执行数据库操作
            Thread.sleep(1000);//测试超时的时候可以调大点，让它超过设置时间
            //关闭连接
            DataSourceManger.close(conn);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
