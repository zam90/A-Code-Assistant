<%@ page import="java.sql.*" %>
<%@ page import="java.sql.*" %>
<%--
  Created by IntelliJ IDEA.
  User: Zam90
  Date: 2020/10/18
  Time: 17:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    String driverName = "com.mysql.jdbc.Driver";         //驱动程序名
    String userName = "root";                            //数据库用户名
    String userPwd = "123456";                           //密码
    String dbName = "students";                          //数据库名
    String  url="jdbc:mysql://localhost:3306/"+dbName+ "?useSSL=false&serverTimezone=UTC&allowPublicKeyRetrieval=true";
    Class.forName(driverName);
    Connection conn= DriverManager.getConnection(url,"root","123456");
    String sql="Insert into stu_info(id,name,sex,age,weight,hight) values(?,?,?,?,?,?)";
    PreparedStatement pstmt= conn.prepareStatement(sql);

    request.setCharacterEncoding("UTF-8");//设置字符编码，避免出现乱码

    int id=Integer.parseInt(request.getParameter("id"));
    String name=request.getParameter("name").trim();
    String sex=request.getParameter("sex").trim();
    int age=Integer.parseInt(request.getParameter("age"));
    float weight=Float.parseFloat(request.getParameter("weight"));
    float hight=Float.parseFloat(request.getParameter("hight"));

    pstmt.setInt(1,id);
    pstmt.setString(2,name);
    pstmt.setString(3,sex);
    pstmt.setInt(4,age);
    pstmt.setFloat(5,weight);
    pstmt.setFloat(6,hight);

    try{
        int n=pstmt.executeUpdate();
        if(n==1){%>
数据插入操作成功！<br>
<%}
else{%>
数据插入操作失败！<br>
<%}
}catch(Exception e){%>
更新过程出现异常错误！<br>
<%=e.getMessage()%>
<%;
}
    if(pstmt!=null){ pstmt.close(); }
    if(conn!=null){ conn.close(); }
%>

</body>
</html>
