<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>
<html>

<!--标题-->
<head>
  <title>个人信息</title>
  <meta charset="utf-8">
  <script language="JavaScript" src="test.js"></script>
</head>

<body>
<%
    Student student = null;
    Cookie[] cookies = request.getCookies();
    String ssid = "";
    if(cookies != null) {
        for (Cookie c : cookies) {
            if (c.getName().equalsIgnoreCase("sid")) {
                ssid = c.getValue();
            }
        }
        int sid = Integer.parseInt(ssid);
        StudentDAO DAO = new StudentDAO();

        try {
            student = DAO.searchStuInf(sid);
        } catch (Exception e) {
            e.printStackTrace();
            response.sendRedirect("fail.jsp");
        }
    }
%>
<h2  align="center">个人信息</h2>
<form name="inf" action="updateJDBC.jsp"><!--信息表单-->
  <p>
  <table cellspacing="6" cellpadding="6" align="center">
    <tr><td align="right">学号：</td><td><input type="text" name="sid" value="<%=student.getSid()%>"></td></tr>
    <tr><td align="right">姓名：</td><td><input type="text" name="sname" value="<%=student.getSname()%>"></td></tr>
    <tr><td align="right">密码：</td><td><input type="password" name="password"></td></tr>
  </table>
  </p>

  <table cellspacing="9" cellpadding="9" align="center">
    <tr>
      <td><input type="Button" value="修改" onclick=submit()></td>
    </tr>
      <tr>
          <td><a href="deleteJDBC.jsp"><input type="Button" value="删除"></a></td>
      </tr>
  </table>
</form>
</body>
</html>
