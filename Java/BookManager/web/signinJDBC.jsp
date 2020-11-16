<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>
<%@ page import="java.io.IOException" %>

<body>
<%
    try {
        String stuId = request.getParameter("stuId");
        String stuName = request.getParameter("stuName");
        String stuPassword = request.getParameter("stuPassword");
        StudentDAO DAO = new StudentDAO();
        try {
            Student student = DAO.searchStuInf(stuId);
            if (Objects.equals(stuPassword, student.getStuPassword())) {
                //设置Cookie
                Cookie logininf = new Cookie("stuId", stuId);
                response.addCookie(logininf);
                response.sendRedirect("signinsuccess.jsp");
            } else {
                response.sendRedirect("signinfail.jsp");
            }
        } catch (Exception e) {
            e.printStackTrace();
            response.sendRedirect("signinfail.jsp");
        }
    } catch (NumberFormatException | IOException e) {
        response.sendRedirect("signinfail.jsp");
        e.printStackTrace();
    }
%>
</body>