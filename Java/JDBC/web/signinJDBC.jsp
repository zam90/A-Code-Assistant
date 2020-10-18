<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>

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
        String password = request.getParameter("password");
        String sql="select password from student where sid=?";
        PreparedStatement pstmt = connection.prepareStatement(sql);
        pstmt.setInt(1,sid);
        ResultSet result = pstmt.executeQuery(sql);
        String password1 = result.getString("password");

        if(Objects.equals(password, password1)){
            response.sendRedirect("signinsuccess.jsp");
        }
        else{
            response.sendRedirect("signinfail.jsp");
        }
        //5、关闭数据库操作对象、数据库连接
        result.close();
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