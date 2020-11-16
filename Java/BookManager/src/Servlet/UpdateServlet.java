package Servlet;
import DAO.StudentDAO;
import VO.Student;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/UpdateServlet")
public class UpdateServlet extends HttpServlet {
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
    }
}
