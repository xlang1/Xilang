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
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req,resp);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //接收用户名和密码
        //post 解决乱码
        req.setCharacterEncoding("UTF-8");
        String username = req.getParameter("username");
        String password = req.getParameter("password");

//        //解决get方式乱码：tomcat进行URL解码时，默认的字符集是ISO-8859-1
//        //1.先对乱码数据进行编码：转为字节数组
//        byte[] bytes = username.getBytes(StandardCharsets.ISO_8859_1);
//        //2.字节数组解码
//        username = new String(bytes, StandardCharsets.UTF_8);
        //调用工具类查询
        //1.sql语句
        String sql = "select * from tb_user";
        //2.调用查询方法
        List<List> lists = JDBC_Utils.queryList(sql);
        //3.List<List>转换成List<User>
        int i = 0;
        List<User> users = lists.stream().map(
                s -> {
                    User user = new User();
                    user.setId(Integer.parseInt(s.get(i).toString()));//编号
                    user.setUsername(s.get(i + 1).toString());//用户名
                    user.setPassword(s.get(i + 2).toString());//密码
                    return user;
                }
        ).collect(Collectors.toList());
        //获取字符串输出流，设置type
        resp.setContentType("text/html;charset=utf-8");
        PrintWriter writer = resp.getWriter();
        for (User user : users) {
            if (Objects.equals(user.getUsername(), username) && Objects.equals(user.getPassword(), password)) {
                writer.write("登录成功！");
                return;
            }
        }
        writer.write("登录失败");
    }
}
