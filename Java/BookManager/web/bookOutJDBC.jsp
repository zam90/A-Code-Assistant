<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="jakarta.servlet.http.Cookie" %>

<%@ page import="java.io.IOException" %>
<%@ page import="DAO.BookDAO" %>
<%@ page import="VO.Book" %>


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
        String bookId = request.getParameter("bookId");
        BookDAO DAO = new BookDAO();
        Book book = new Book(bookId);
        try {
            DAO.bookout(book,stuId);
            response.sendRedirect("success.jsp");//用于跳出框架跳转页面
        } catch (Exception e) {
            e.printStackTrace();
            response.sendRedirect("fail.jsp");//用于跳出框架跳转页面
        }
    } catch (NumberFormatException | IOException e) {
        response.sendRedirect("fail.jsp");//用于跳出框架跳转页面
        e.printStackTrace();
    }
%>
</body>