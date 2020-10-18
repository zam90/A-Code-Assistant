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
        String sql="insert into student(sid,sname,sex,password) values(?,?,?,?)";
        PreparedStatement pstmt = connection.prepareStatement(sql);
        request.setCharacterEncoding("UTF-8");
        int sid = Integer.parseInt(request.getParameter("sid"));
        String sname = request.getParameter("sname");
        String sex = request.getParameter("sex");
        String password = request.getParameter("password1");
        pstmt.setInt(1,sid);
        pstmt.setString(2,sname);
        pstmt.setString(3,sex);
        pstmt.setString(4,password);
        int n = pstmt.executeUpdate();
        if(n==1){out.print("数据插入成功！");}
        else{out.print("数据插入失败！");}
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