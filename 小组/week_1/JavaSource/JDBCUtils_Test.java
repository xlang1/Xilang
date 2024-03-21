package JDBC_Utils;

import java.util.List;

/*
目标：学习使用JDBC操作数据库，重点在于工具类的封装
设置通用的增删改查功能类，再Test中可以设置数据进行测试
 */

public class JDBCUtils_Test {
    public static void main(String[] args) {
        //1.添加数据的测试
//        String sql = "insert into student values (3,?,?)";
//        Object[] objs = {"王五", "20"};
//        int i = JDBC_Utils.update(sql, objs);
//        System.out.println("被影响的行数：" + i);
        //2.查询的测试
        String sql = "select * from student";
        List<List> lists = JDBC_Utils.queryList(sql);
        System.out.println(lists);
    }
}
