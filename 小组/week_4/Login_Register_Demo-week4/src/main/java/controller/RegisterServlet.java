package controller;

import pojo.User;
import utils.JDBC_Utils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

@WebServlet("/registerServlet")
public class RegisterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //接收用户数据
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        //解决get方式乱码：tomcat进行URL解码时，默认的字符集是ISO-8859-1
        //1.先对乱码数据进行编码：转为字节数组
        byte[] bytes = username.getBytes(StandardCharsets.ISO_8859_1);
        //2.字节数组解码
        username = new String(bytes, StandardCharsets.UTF_8);

        //封装user对象
        User user = new User();
        user.setUsername(username);
        user.setPassword(password);

        //调用工具类查询，检查是否有重名
        //1.sql语句
        String sql = "select * from tb_user";
        //2.调用查询方法
        List<List> lists = JDBC_Utils.queryList(sql);
        //3.List<List>转换成List<User>
        int i = 0;
        List<User> users = lists.stream().map(
                s -> {
                    User u = new User();
                    u.setId(Integer.parseInt(s.get(i).toString()));//编号
                    u.setUsername(s.get(i + 1).toString());//用户名
                    u.setPassword(s.get(i + 2).toString());//密码
                    return u;
                }
        ).collect(Collectors.toList());
        //获取字符串输出流，设置type
        resp.setContentType("text/html;charset=utf-8");
        PrintWriter writer = resp.getWriter();
        for (int j = 0; j < users.size(); j++) {
            if (Objects.equals(users.get(j).getUsername(), user.getUsername())) {
                //用户重名
                writer.write("用户已存在！");
                return;
            }
        }
        //用户没有重名，调用utils工具添加数据
        //sql语句                               id自增
        String sql1 = "insert into tb_user values (null,?,?)";
        Object[] objs = {user.getUsername(), user.getPassword()};
        System.out.println(Arrays.toString(objs));
        JDBC_Utils.update(sql1, objs);//添加方法
        writer.write("注册成功！");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    }
}
