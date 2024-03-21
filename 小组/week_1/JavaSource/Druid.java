package Druid;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.sql.Connection;
import java.util.Properties;

public class Druid {
    public static void main(String[] args) throws Exception {
        //加载配置文件
        Properties prop = new Properties();
        prop.load(new FileInputStream("src/Druid.properties"));
        //获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
        //获取数据库连接Connection
        Connection connection = dataSource.getConnection();

        System.out.println(connection);

        //获取路径
        //System.out.println(System.getProperty("user.dir"));
    }
}
