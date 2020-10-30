<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>


<body>
<%
    String ssid = "";
    try{
        Cookie[] cookies = request.getCookies();
        for (Cookie c : cookies) {
            if (c.getName().equalsIgnoreCase("sid")) {
                ssid = c.getValue();
            }
        }
    } catch (Exception e) {
        e.printStackTrace();
    }
    int sid = Integer.parseInt(ssid);
    String sname = request.getParameter("sname");
    String password = request.getParameter("password");
    StudentDAO DAO = new StudentDAO();
    Student student = new Student();
    student.setSid(sid);
    student.setSname(sname);
    student.setPassword(password);
    try {
        DAO.update(student);
        response.sendRedirect("updatesuccess.jsp");
    } catch (Exception e) {
        e.printStackTrace();
        response.sendRedirect("updatefail.jsp");
    }
%>
</body>