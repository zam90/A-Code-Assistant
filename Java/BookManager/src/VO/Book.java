package VO;

public class Book {
    private String bookId,bookName,bookClassify;
    private int bookCount;
    public Book(){}
    public Book(String bookId,String bookName,String bookClassify,int bookCount){
        this.bookId = bookId;
        this.bookName = bookName;
        this.bookClassify = bookClassify;
        this.bookCount = bookCount;
    }

    public Book(String bookId) {
        this.bookId = bookId;
    }

    public String getBookId() {
        return bookId;
    }

    public void setBookId(String bookId) {
        this.bookId = bookId;
    }

    public String getBookName() {
        return bookName;
    }

    public void setBookName(String bookName) {
        this.bookName = bookName;
    }

    public String getBookClassify() {
        return bookClassify;
    }

    public void setBookClassify(String bookClassify) {
        this.bookClassify = bookClassify;
    }

    public int getBookCount() {
        return bookCount;
    }

    public void setBookCount(int bookCount) {
        this.bookCount = bookCount;
    }
}
