
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>个人信息</title>
</head>
<body>
<%
    request.setCharacterEncoding("utf-8");
    String UserName=request.getParameter("Username");//用户名
    String UserTrueName=request.getParameter("UserTrueName");//用户真实姓名
    String UserSex=request.getParameter("Sex");//用户性别
    String ID=request.getParameter("UserID");//用户身份证
    String UserEmail=request.getParameter("Email");//邮件地址
%>
<table align="center">
    <tr><td colspan="3" align="center" height="40" id="title">个人信息</td></tr>
    <tr><td>用户名：</td><td><%=UserName%></td></tr>
    <tr><td>姓名：</td><td><%=UserTrueName%></td></tr>
    <tr><td>身份证：</td><td><%=ID%></td></tr>
    <tr><td>性别：</td><td><%=UserSex%></td></tr>
    <tr><td>邮箱：</td><td><%=UserEmail%></td></tr>
</table>
</body>
</html>
