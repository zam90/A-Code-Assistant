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
import java.sql.Timestamp;

@WebServlet("/bookInServlet")
public class bookInServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
            String stuId = request.getParameter("stuId");
            String bookId = request.getParameter("bookId");
            Timestamp time = Timestamp.valueOf(request.getParameter("time"));
            BookDAO DAO = new BookDAO();
            Book book = new Book(bookId);
            try {
                DAO.bookin(book,stuId,time);
                response.sendRedirect("success.jsp");//用于跳出框架跳转页面
            } catch (Exception e) {
                e.printStackTrace();
                response.sendRedirect("fail.jsp");//用于跳出框架跳转页面
            }
        }
}
