package VO;

public class Student {
    private int sid;
    private String sname,sex,password;
    public Student(){}
    public Student(int sid,String sname,String sex,String password){
        this.sid = sid;
        this.sname = sname;
        this.sex = sex;
        this.password = password;
    }

    public int getSid() {
        return sid;
    }

    public void setSid(int sid) {
        this.sid = sid;
    }

    public String getSname() {
        return sname;
    }

    public void setSname(String sname) {
        this.sname = sname;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
