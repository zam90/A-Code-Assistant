<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>
<%@ page import="java.io.IOException" %>
<html>

<!--标题-->
<head>
    <title>个人信息</title>
    <meta charset="utf-8">
    <script language="JavaScript" src="test.js"></script>
    <!-- 1. 导入CSS的全局样式 -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <!-- 2. jQuery导入，建议使用1.9以上的版本 -->
    <script src="js/jquery-2.1.0.min.js"></script>
    <!-- 3. 导入bootstrap的js文件 -->
    <script src="js/bootstrap.min.js"></script>
    <style type="text/css">
        td, th {
            text-align: center;
        }
    </style>
</head>

<body>
<%
    try{
        Student student = null;
        Cookie[] cookies = request.getCookies();
        String sid = "";
        if(cookies != null) {
            for (Cookie c : cookies) {
                if (c.getName().equalsIgnoreCase("stuId")) {
                    sid = c.getValue();
                }
            }
            StudentDAO DAO = new StudentDAO();

            try {
                student = DAO.searchStuInf(sid);
            } catch (Exception e) {
                e.printStackTrace();
                response.sendRedirect("fail.jsp");
            }
        }
%>
<h3  align="center">个人信息</h3>
<form name="inf" action="updateJDBC.jsp"><!--信息表单-->
    <p>
    <table cellspacing="6" cellpadding="6" align="center">
        <tr><td align="right">学号：</td><td><input type="text" name="sid" class="form-control" value="<%=student.getStuId()%>" readonly></td></tr>
        <tr><td align="right">姓名：</td><td><input type="text" name="sname" class="form-control" value="<%=student.getStuName()%>"></td></tr>
        <tr><td align="right">密码：</td><td><input type="password" name="password" value="<%=student.getStuPassword()%>" class="form-control"></td></tr>
    </table>
    </p>

    <table cellspacing="9" cellpadding="9" align="center">
        <tr>
            <td><input type="Button" value="修改" class="btn btn-primary" onclick=submit()></td>
        </tr>

    </table>
</form>
<% } catch (NumberFormatException | IOException e) {
    response.sendRedirect("fail.jsp");
    e.printStackTrace();
}
%>
</body>
</html>
