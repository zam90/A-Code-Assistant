<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>
<%@ page import="java.io.IOException" %>


<body>
<%
    try {
        String stuId = null;
        try {
            Cookie[] cookies = request.getCookies();
            for (Cookie c : cookies) {
                if (c.getName().equalsIgnoreCase("stuId")) {
                    stuId = c.getValue();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        String stuName = request.getParameter("sname");
        String stuPassword = request.getParameter("password");
        StudentDAO DAO = new StudentDAO();
        Student student = new Student();
        student.setStuId(stuId);
        student.setStuName(stuName);
        student.setStuPassword(stuPassword);
        try {
            DAO.update(student);
            response.sendRedirect("updatesuccess.jsp");
        } catch (Exception e) {
            e.printStackTrace();
            response.sendRedirect("updatefail.jsp");
        }
    } catch (NumberFormatException | IOException e) {
        response.sendRedirect("fail.jsp");
        e.printStackTrace();
    }
%>
</body>