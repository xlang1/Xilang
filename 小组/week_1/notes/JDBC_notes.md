# JDBC简介

概念：

- 全称：（Java DataBase Connectivity）Java数据库连接
- JDBC就是使用Java语言操作关系型数据库的一套API

本质：

- 官方（sun公司）定义的一套错做所有关系型数据库的规则，即接口
- 各个数据库厂商去实现这套接口，提高数据库驱动jar包
- 我们可以使用这套接口（JDBC）编程，真正执行的代码是驱动jar包中的实现类

好处：

- 各个数据库厂商使用相同的接口，Java代码不需要针对不同的数据库分别开发
- 可随时替换底层数据库，访问数据库的Java代码基本不变



# JDBC API

## DriverManager

**DriverManager（驱动管理类）作用：**

1. **注册驱动**

`Class.forName("com.mysql.jdbc.Driver");`(可查看Driver类源码了解)

- 注意：
  - MySQL5之后的驱动包，可以省略注册驱动的步骤
  - 自动加载jar包中META-INF/services/java.sql.Driver文件中的驱动类

2. **获取连接**

`Connection conn = DriverManager.getConnection(url,username,password);`

- 参数：
  - url：连接路径
    - 语法：jdbc:mysql://ip地址（域名）:端口号/数据库名称？参数键值对1&参数键值对2...
    - 示例：jdbc:mysql://127.0.0.1:3306/db1
    - 细节：
      - 如果链接的是本机mysql服务器且服务默认端口是3306，则url可以简写为jdbc:mysql:///数据库名称？参数键值对
      - 配置useSSL=false参数，禁用安全连接方式，解决警告提示
  - user：用户名
  - password：密码

## Connection

**Connection(数据库连接对象)**作用：

1. 获取执行SQL的对象
   - 普通执行SQL对象：`Statement stmt = conn.createStatement();`
   - 预编译SQL的执行SQL对象（防止SQL注入）：`PreparedStatement pstmt = conn.prepareStatement(sql);`
   - //执行存储过程的对象：`CallableStatement prepareCall(sql);`

2. 事务管理
   - MySQL事务管理
     - 开启事务：`BEGIN;/START TRANSACTION;`
     - 提交事务：`COMMIT;`
     - 回滚事务：`ROLLBACK;`
     - MySQL默认自动提交事务
   - JDBC事务管理：Connection接口中定义了3个对应的方法
     - 开启事务：`setAutoCommit(boolen autoCommit)`:true为自动提交事务，false为手动提交事务，即开启事务
     - 提交事务：`commit()`
     - 回滚事务：`rollback()`

## Statement

**Statement作用：**提供方法执行SQL语句

1. `int executeUpdate(sql)`：执行更新操作执行DML，DDL语句
   - 返回值：
     - DML语句影响的行数
     - DDL语句执行后，执行成功也可能返回0
2. `ResultSet executeQuery(sql)`：执行查询操作，执行DQL语句
   - 返回值：ResultSet结果集对象

## ResultSet

ResultSet(结果集对象)作用：

1. 封装了DQL查询语句的结果
   - `ResultSet stmt.executeQuery(sql)`：执行DQL语句返回ResultSet对象
2. 获取查询结果，使用步骤：
   1. 游标向下移动一行，并判断改行是否有数据：boolean next()
   2. 获取数据，int列的编号从1开始，String列的名称：xxx(int/String)  getXXX(参数)
      - while(rs.next()){rs.getXXX(参数);}

## PreparedStatement

作用：

1. 预编译SQL语句并执行，且性能更高

```
// SQL语句中的参数值用？占位符替代
String sql = "select * from user where username = ? and password = ?";

//通过Connection对象获取，并传入对应的sql语句
PreparedStatement pstmt = conn.prepareStatement(sql);

// 设置参数值，对应占位符出现顺序
pstmt.setString(1,name);
pstmt.setString(2,pwd);

//执行SQL,不需要再传递sql，有set了
ResultSet rs = pstmt.executeUpdate();
```



2. 且能防止SQL注入问题：原理是将敏感字符进行转义

> SQL注入：通过操作输入来修改实现定义好的SQL语句，用以达到执行代码对服务器进行攻击的方法

操作：

1. PreparedStatement预编译功能开启：useServerPreStmts=true

2. 配置MySQL执行日志my.ini(重启mysql服务后生效)

   ```
   log-output=FILE
   general-log=1
   general_log_file="D:\mysql.log"
   slow-query-log=1
   slow_query_log_file="D:\mysql_slow.log"
   long_query_time=2
   ```

注意：

1. 在获取PreparedStatement对象时，将sql语句发送给mysql服务器进行见检查，编译（这些步骤很耗时）
2. 执行时不需要在进行这些步骤了，速度更快
3. 如果sql模板意义，则只需要进行一次检查、编译

# 使用步骤

0. 创建工程，导入驱动jar包
1. 注册驱动

`Class.forName("com.mysql.jdbc.Driver");`

2. 获取连接

`Connection conn = DriverManager.getConnection(url,username,password);`

3. 定义SQL语句

`String sql = "update...";`

4. 获取执行SQL对象

`Statement stmt = conn.createStatement();`

5. 执行SQL

`stmt.executeUpdate(sql);`

6. 处理返回结果
7. 释放资源

`stmt.close();`

`conn.close();`

# 数据库连接池

**简介：**

- 数据库连接池是个容器，负责分配、管理数据库连接（Connection）
- 它允许应用程序重复使用一个现有的数据库连接，而不是再重新建立一个
- 释放空闲时间超过最大空闲时间的数据库连接来因为没有释放数据库连接而引起的数据库连接遗漏
- 好处：
  - 资源重用
  - 提升系统响应速度
  - 避免数据库连接遗漏

**实现：**

- 标准接口：DataSource
  - 官方（SUN）提供的数据库连接池标准接口，有第三方组织实现
  - 功能：获取连接，`Connection getConnection()`
- 常见连接池：DBCP，C3P0，Druid
- Druid
  - 强大
  - 阿里巴巴开源项目
  - 使用步骤：
    - 导入jar包
    - 定义配置文件
    - 加载配置文件
    - 获取数据库连接池对象
    - 获取连接