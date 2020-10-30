<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>

<body>
<%
    int sid = Integer.parseInt(request.getParameter("sid"));
    String ssid = request.getParameter("sid");
    String password = request.getParameter("password");
    StudentDAO DAO = new StudentDAO();
    try {
        Student student = DAO.searchStuInf(sid);
        if(Objects.equals(password, student.getPassword())){
            //设置Cookie
            Cookie logininf = new Cookie("sid",ssid);
            response.addCookie(logininf);
            response.sendRedirect("signinsuccess.jsp");
        }
        else{
            response.sendRedirect("signinfail.jsp");
        }
    } catch (Exception e) {
        e.printStackTrace();
        response.sendRedirect("signinfail.jsp");
    }
%>
</body>