<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="jakarta.servlet.http.Cookie" %>

<body>
<%
    //数据库url、用户名和密码
    String DB_URL="jdbc:mysql://localhost:3306/studentwork?serverTimezone=Asia/Shanghai";
    String USER="root";
    String PASS="123456";
    try {
        //1、注册JDBC驱动
        Class.forName("com.mysql.jdbc.Driver");
        //2、获取数据库连接
        Connection connection = DriverManager.getConnection(DB_URL, USER, PASS);
        //3、操作数据库
        Statement statement = connection.createStatement();//获取操作数据库的对象
        //4、设置sql语句和变量
        request.setCharacterEncoding("UTF-8");
        int sid = Integer.parseInt(request.getParameter("sid"));
        String sname = request.getParameter("sname");
        String password = request.getParameter("password");
        String sql="update student set sname=?,password=? where sid=?";
        PreparedStatement pstmt = connection.prepareStatement(sql);
        pstmt.setString(1,sname);
        pstmt.setString(2,password);
        pstmt.setInt(3,sid);
        int n = pstmt.executeUpdate();
        if(n==1){response.sendRedirect("updatesuccess.jsp");}
        else{out.print("修改失败！");}
        //5、关闭数据库操作对象、数据库连接
        statement.close();
        connection.close();
    } catch (ClassNotFoundException e) {
        e.printStackTrace();
    } catch(SQLException e){
        e.printStackTrace();
    } catch(Exception e){
        e.printStackTrace();
    }
%>
</body>