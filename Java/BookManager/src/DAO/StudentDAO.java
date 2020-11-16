package DAO;

import Connect.JDBCUtil;
import VO.Student;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class StudentDAO {

    //修改
    public void update(Student student) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        String Sql = "update stuinf set stuName = ?, stuPassword = ? where stuId = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setString(1,student.getStuName());
        ps.setString(2,student.getStuPassword());
        ps.setString(3,student.getStuId());
        ps.executeUpdate();
        JDBCUtil.free(null,ps,conn);
    }

    //查询
    public Student searchStuInf(String stuId) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        Student student = null;
        String Sql = "select * from stuinf where stuId = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setString(1,stuId);
        ResultSet rs = ps.executeQuery();
        if (rs.next()){
            student = new Student();
            student.setStuId(rs.getString("stuId"));
            student.setStuName(rs.getString("stuName"));
            student.setStuPassword(rs.getString("stuPassword"));
        }
        JDBCUtil.free(rs,ps,conn);
        return student;
    }
}
