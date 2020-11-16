<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>

<body>
<%
    int sid = Integer.parseInt(request.getParameter("sid"));
    String sname = request.getParameter("sname");
    String sex = request.getParameter("sex");
    String password = request.getParameter("password1");
    Student student = new Student(sid,sname,sex,password);
    StudentDAO DAO = new StudentDAO();
    try {
        DAO.add(student);
        response.sendRedirect("signupsuccess.jsp");
    } catch (Exception e) {
        e.printStackTrace();
        response.sendRedirect("signupfail.jsp");
    }
%>
</body>