
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<!--标题-->
<head>
    <title>信息注册</title>
    <meta charset="utf-8">
    <script language="JavaScript" src="test.js"></script>
</head>

<body>

<h2  align="center">注册信息</h2>
<form name="inf" action="show.jsp"><!--信息表单-->
    <p>
    <table cellspacing="6" cellpadding="6" align="center">
        <tr><td align="right">用户名：</td><td><input type="text" name="Username"></td></tr>
        <tr><td align="right">昵称：</td><td><input type="text" name="UserTrueName"></td></tr>
        <tr><td align="right">身份证号：</td><td><input type="text" name="UserID"></td></tr>
        <tr>
            <td align="right">性别：</td>
            <td><input type="radio" name="Sex" value="male" checked="checked">male<input type="radio" name="Sex" value="female">female</td>
        </tr>
        <tr>
            <td align="right">邮箱：</td><td><input type="text" name="Email" value=""></td>
        </tr>
        <tr><td align="right">密码：</td><td><input type="password" name="Userpassword"></td></tr>
        <tr><td align="right">确认密码：</td><td><input type="password" name="Userpassword1"></td></tr>
    </table>
    </p>

    <div style="text-align: center;"><input type="checkbox" name="read">接受<a href="http://www.baidu.com" target="_blank">用户使用协议</a></div>
    <table cellspacing="9" cellpadding="9" align="center">
        <tr>
            <td><input type="Button" value="注册" onclick="Test()"></td>
        </tr>
    </table>
</form>
</body>
</html>
