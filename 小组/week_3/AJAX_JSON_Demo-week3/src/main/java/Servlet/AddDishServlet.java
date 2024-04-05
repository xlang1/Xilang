package Servlet;

import Utils.JDBC_Utils;
import com.alibaba.fastjson2.JSON;
import pojo.Dishes;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/addDishServlet")
public class AddDishServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1.获取请求体
        BufferedReader br = req.getReader();
        String param = br.readLine();
        System.out.println(param);

        //2.将JSON字符串转换成Java对象
        Dishes dish = JSON.parseObject(param, Dishes.class);

        //3.添加数据到数据库                        id自增
        String sql = "insert into dishes values (null,?,?,?)";
        Object[] objs = {dish.getName(), dish.getPrice(), dish.getDescribe()};
        int i = JDBC_Utils.update(sql, objs);
        if (i > 0) resp.getWriter().write("success");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req,resp);
    }
}
