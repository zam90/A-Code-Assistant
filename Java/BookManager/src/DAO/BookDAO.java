package DAO;

import Connect.JDBCUtil;
import VO.Book;
import VO.Student;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;

public class BookDAO {

    //借出
    public void bookout(Book book, String stuId) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        String Sql1 = "select bookCount from book where bookId = ?";
        PreparedStatement ps1 = conn.prepareStatement(Sql1);
        ps1.setString(1,book.getBookId());
        ResultSet rs = ps1.executeQuery();
        int number = 0;
        if (rs.next()){
            number = rs.getInt("bookCount");
        }
        number--;
        //更新数量
        String Sql2 = "update book set bookCount = ? where bookId = ?";
        PreparedStatement ps2 = conn.prepareStatement(Sql2);
        ps2.setInt(1,number);
        ps2.setString(2,book.getBookId());
        ps2.executeUpdate();
        //添加记录
        String Sql3 = "insert into bookout(stuId,bookId,timeOut) values(?,?,?)";
        PreparedStatement ps3 = conn.prepareStatement(Sql3);
        ps3.setString(1,stuId);
        ps3.setString(2,book.getBookId());
        ps3.setTimestamp(3, new Timestamp(System.currentTimeMillis()));
        ps3.executeUpdate();
        JDBCUtil.free(null,ps2,conn);
    }

    //还书
    public void bookin(Book book, String stuId) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        String Sql1 = "select bookCount from book where bookId = ?";
        PreparedStatement ps1 = conn.prepareStatement(Sql1);
        ps1.setString(1,book.getBookId());
        ResultSet rs = ps1.executeQuery();
        int number = 0;
        if (rs.next()){
            number = rs.getInt("bookCount");
        }
        number++;
        //更新数量
        String Sql2 = "update book set bookCount = ? where bookId = ?";
        PreparedStatement ps2 = conn.prepareStatement(Sql2);
        ps2.setInt(1,number);
        ps2.setString(2,book.getBookId());
        ps2.executeUpdate();
        //添加记录
        String Sql3 = "insert into bookin(stuId,bookId,timeOut) values(?,?,?)";
        PreparedStatement ps3 = conn.prepareStatement(Sql3);
        ps3.setString(1,stuId);
        ps3.setString(2,book.getBookId());
        ps3.setTimestamp(3, new Timestamp(System.currentTimeMillis()));
        ps3.executeUpdate();
        JDBCUtil.free(null,ps2,conn);
    }

    //查询所有图书
    public List<Book> bookAll() throws Exception{
        Connection conn = JDBCUtil.getConnection();
        List<Book> allBook = new ArrayList<Book>();
        String Sql = "select * from book";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ResultSet rs = ps.executeQuery();
        while (rs.next()){
            Book book = new Book();
            book.setBookId(rs.getString("bookId"));
            book.setBookName(rs.getString("bookName"));
            book.setBookClassify(rs.getString("bookClassify"));
            book.setBookCount(rs.getInt("bookCount"));
            allBook.add(book);
        }
        JDBCUtil.free(rs,ps,conn);
        return allBook;
    }

    //查询
    public Book searchInf(String bookId) throws Exception{
        Connection conn = JDBCUtil.getConnection();
        Book book = null;
        String Sql = "select * from book where bookId = ?";
        PreparedStatement ps = conn.prepareStatement(Sql);
        ps.setString(1,bookId);
        ResultSet rs = ps.executeQuery();
        if (rs.next()){
            book = new Book();
            book.setBookId(rs.getString("bookId"));
            book.setBookName(rs.getString("bookName"));
            book.setBookClassify(rs.getString("bookClassify"));
            book.setBookCount(rs.getInt("bookCount"));
        }
        JDBCUtil.free(rs,ps,conn);
        return book;
    }
}
