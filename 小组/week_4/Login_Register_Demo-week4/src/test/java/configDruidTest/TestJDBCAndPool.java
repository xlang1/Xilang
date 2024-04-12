package configDruidTest;

import org.junit.Test;
import pojo.User;
import utils.JDBC_Utils;

import java.util.List;
import java.util.stream.Collectors;

public class TestJDBCAndPool {
    public static void main(String[] args) {
        //2.查询的测试
        String sql = "select username,password from tb_user";
        List<List> lists = JDBC_Utils.queryList(sql);
        int i = 0;
        List<User> users = lists.stream().map(
                s -> {
                    User user = new User();
                    user.setUsername(s.get(i).toString());//用户名
                    user.setPassword(s.get(i + 1).toString());//密码
                    return user;
                }
        ).collect(Collectors.toList());
        System.out.println(users);
    }

}
