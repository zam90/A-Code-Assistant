package DAO;

import Connect.JDBCUtil;
import VO.Book;
import VO.BookRecord;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;

public class BookRecorderDAO {

    //查询已归还的图书
    public List<BookRecord> bookInAlready(String stuId) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        List<BookRecord> BookRecords = new ArrayList<BookRecord>();
        String Sql = "select * from bookin where stuId = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setString(1,stuId);
        ResultSet rs = ps.executeQuery();
        while (rs.next()){
            BookRecord bookrecord = new BookRecord();
            bookrecord.setStuId(rs.getString("stuId"));
            bookrecord.setBookId(rs.getString("bookId"));
            bookrecord.setTime(rs.getTimestamp("timeIn"));
            BookRecords.add(bookrecord);
        }
        JDBCUtil.free(rs,ps,conn);
        return BookRecords;
    }

    //查询已归还的图书
    public List<BookRecord> bookOut(String stuId) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        List<BookRecord> BookRecords = new ArrayList<BookRecord>();
        String Sql = "select * from bookout where stuId = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setString(1,stuId);
        ResultSet rs = ps.executeQuery();
        while (rs.next()){
            BookRecord bookrecord = new BookRecord();
            bookrecord.setStuId(rs.getString("stuId"));
            bookrecord.setBookId(rs.getString("bookId"));
            bookrecord.setTime(rs.getTimestamp("timeOut"));
            BookRecords.add(bookrecord);
        }
        JDBCUtil.free(rs,ps,conn);
        return BookRecords;
    }

}
