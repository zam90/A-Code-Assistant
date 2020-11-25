<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="jakarta.servlet.http.Cookie" %>
<%@ page import="DAO.StudentDAO" %>
<%@ page import="VO.Student" %>
<%@ page import="java.io.IOException" %>

<body>
<%
    try {
        String ssid = "";
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie c : cookies) {
                if (c.getName().equalsIgnoreCase("sid")) {
                    ssid = c.getValue();
                }
            }
            int sid = Integer.parseInt(ssid);
            StudentDAO DAO = new StudentDAO();
            try {
                DAO.delete(sid);
                response.sendRedirect("deletesuccess.jsp");
            } catch (Exception e) {
                e.printStackTrace();
                response.sendRedirect("deletefail.jsp");
            }
        }
    } catch (NumberFormatException | IOException e) {
        response.sendRedirect("fail.jsp");
        e.printStackTrace();
    }
%>
</body>