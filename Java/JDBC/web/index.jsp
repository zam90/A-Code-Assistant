<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="java.sql.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<!--标题-->
<head>
  <title>个人信息</title>
  <meta charset="utf-8">
  <script language="JavaScript" src="test.js"></script>
</head>

<body>
<%
  Cookie[] cookies = request.getCookies();
  if(cookies != null)
    for(Cookie c : cookies){
      String access = c.getName();//获取Cookie名称
      if("Accessinid".equals(access)){
        int sid = Integer.parseInt(c.getValue());//获取Cookie的值
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
          request.setCharacterEncoding("UTF-8");
          String sql="select * from student where sid=?";
          PreparedStatement pstmt = connection.prepareStatement(sql);
          pstmt.setInt(1,sid);
          ResultSet result = pstmt.executeQuery();
          while(result.next()){ //遍历结果集，取出数据
            String sname = result.getString("sname");
            String sex = result.getString("sex");
            String password = result.getString("password");
            %>
<h2  align="center">登录</h2>
<form name="inf" action="signinJDBC.jsp"><!--信息表单-->
  <p>
  <table cellspacing="6" cellpadding="6" align="center">
    <tr><td align="right">学号：</td><td><input type="text" name="sid" value="<%=sid%>"></td></tr>
    <tr><td align="right">姓名：</td><td><input type="text" name="sid" value="<%=sname%>"></td></tr>
    <tr><td align="right">密码：</td><td><input type="password" name="password"></td></tr>
  </table>
  </p>

  <table cellspacing="9" cellpadding="9" align="center">
    <tr>
      <td><input type="Button" value="修改" onclick=submit()></td>
    </tr>
  </table>
</form>
            <%
          }
          //4、关闭结果集、数据库操作对象、数据库连接
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
      }
    }
            %>
</body>
</html>
