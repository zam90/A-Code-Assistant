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
import java.util.Objects;

@WebServlet("/studentsigninServlet")
public class studentsigninServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        try {
            String stuId = request.getParameter("stuId");
            String stuPassword = request.getParameter("stuPassword");
            StudentDAO DAO = new StudentDAO();
            try {
                Student student = DAO.searchStuInf(stuId);
                if (Objects.equals(stuPassword, student.getStuPassword())) {
                    //设置Cookie
                    Cookie logininf = new Cookie("stuId", stuId);
                    response.addCookie(logininf);
                    response.sendRedirect("index.jsp");
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
    }
}
