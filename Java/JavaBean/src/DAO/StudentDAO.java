package DAO;

import Connect.JDBCUtil;
import VO.Student;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class StudentDAO {
    //插入
    public void add(Student student) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        String Sql = "insert into student(sid,sname,sex,password) values(?,?,?,?)";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setInt(1,student.getSid());
        ps.setString(2,student.getSname());
        ps.setString(3,student.getSex());
        ps.setString(4,student.getPassword());
        ps.executeUpdate();
        JDBCUtil.free(null,ps,conn);
    }

    //修改
    public void update(Student student) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        String Sql = "update student set sname = ?, password = ? where sid = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setString(1,student.getSname());
        ps.setString(2,student.getPassword());
        ps.setInt(3,student.getSid());
        ps.executeUpdate();
        JDBCUtil.free(null,ps,conn);
    }

    //删除
    public void delete(int sid) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        String Sql = "delete from student where sid = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setInt(1,sid);
        ps.executeUpdate();
        JDBCUtil.free(null,ps,conn);
    }

    //查询
    public Student searchStuInf(int sid) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        Student student = null;
        String Sql = "select * from student where sid = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setInt(1,sid);
        ResultSet rs = ps.executeQuery();
        if (rs.next()){
            student = new Student();
            student.setSid(rs.getInt("sid"));
            student.setSname(rs.getString("sname"));
            student.setSex(rs.getString("sex"));
            student.setPassword(rs.getString("password"));
        }
        JDBCUtil.free(rs,ps,conn);
        return student;
    }
}
