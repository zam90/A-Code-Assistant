package VO;

import java.sql.Timestamp;

public class BookRecord {
    private String stuId,bookId;
    private Timestamp time;
    public BookRecord(){}
    public BookRecord(String stuId,String bookId,Timestamp time){
        this.stuId = stuId;
        this.bookId = bookId;
        this.time = time;
    }

    public String getStuId() {
        return stuId;
    }

    public void setStuId(String stuId) {
        this.stuId = stuId;
    }

    public String getBookId() {
        return bookId;
    }

    public void setBookId(String bookId) {
        this.bookId = bookId;
    }

    public Timestamp getTime() {
        return time;
    }

    public void setTime(Timestamp time) {
        this.time = time;
    }
}
