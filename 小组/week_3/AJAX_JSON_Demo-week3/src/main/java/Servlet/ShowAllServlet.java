package Servlet;

import Utils.JDBC_Utils;
import com.alibaba.fastjson.JSON;
import pojo.Dishes;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;

@WebServlet("/ajaxServlet")
public class ShowAllServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1.调用JDBC的查询方法找出数据库中的菜单
        //            查询全部          表名
        String sql = "select * from dishes";//sql语句
        //List 转换成 Dishes
        List<List> lists = JDBC_Utils.queryList(sql);
        int i = 0;
        //List<List>转换成List<Dishes>
        List<Dishes> dishes = lists.stream().map(
                s -> {
                    Dishes dish = new Dishes();
                    dish.setId(Integer.parseInt(s.get(i).toString()));//编号
                    dish.setName(s.get(i + 1).toString());//菜名
                    dish.setPrice(s.get(i + 2).toString());//价格
                    dish.setDescribe(s.get(i + 3).toString());//描述
                    return dish;
                }
        ).collect(Collectors.toList());

        //2.将集合转换成JSON数据---序列化
        String jsonString = JSON.toJSONString(dishes);

        //3.响应数据
        resp.setContentType("text/json;charset=utf-8");//处理中文
        resp.getWriter().write(jsonString);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
