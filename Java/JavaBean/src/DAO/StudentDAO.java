package DAO;

import Connect.JDBCUtil;
import VO.Student;

import java.sql.Connection;
import java.sql.PreparedStatement;

public class StudentDAO {
    //插入
    public void add(Student student) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        String Sql = "insert into student(sid,sname,sex,password) values(?,?,?,?)";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setString(1,student.getSid());
        ps.setString(2,student.getSname());
        ps.setString(3,student.getSex());
        ps.setString(4,student.getPassword());
        ps.executeUpdate();
        JDBCUtil.free(null,ps,conn);
    }

    //修改

}
