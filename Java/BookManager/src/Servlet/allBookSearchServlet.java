package Servlet;
import DAO.BookDAO;
import DAO.StudentDAO;
import VO.Book;
import VO.Student;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.util.List;

@WebServlet("/allBookSearchServlet")
public class allBookSearchServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String bookName = request.getParameter("bookName");
        String bookClassify = request.getParameter("bookClassify");
        BookDAO DAO = new BookDAO();
        List<Book> books = null;
        try {
            books = DAO.search(bookName, bookClassify);
        } catch (Exception e) {
            e.printStackTrace();
        }
        request.setAttribute("books",books);
        try {
            request.getRequestDispatcher("/searchallbook.jsp").forward(request,response);
        } catch (ServletException e) {
            e.printStackTrace();
        }
    }
}
