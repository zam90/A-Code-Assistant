
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<!--标题-->
<head>
    <title>登录</title>
    <meta charset="utf-8">
</head>

<body>

<h2  align="center">登录</h2>
<form name="inf" action="signinJDBC.jsp"><!--信息表单-->
    <p>
    <table cellspacing="6" cellpadding="6" align="center">
        <tr><td align="right">学号：</td><td><input type="text" name="sid"></td></tr>
        <tr><td align="right">密码：</td><td><input type="password" name="password"></td></tr>
    </table>
    </p>

    <table cellspacing="9" cellpadding="9" align="center">
        <tr>
            <td><input type="Button" value="登录" onclick=submit()></td>
        </tr>
    </table>
</form>
</body>
</html>
