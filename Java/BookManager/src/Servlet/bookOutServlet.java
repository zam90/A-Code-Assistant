package Servlet;
import DAO.BookDAO;
import DAO.StudentDAO;
import VO.Book;
import VO.Student;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/bookOutServlet")
public class bookOutServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
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
    }
}
