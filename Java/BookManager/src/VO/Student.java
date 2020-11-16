package VO;

public class Student {
    private String stuId,stuName,stuPassword;
    public Student(){}
    public Student(String stuId,String stuName,String stuPassword){
        this.stuId = stuId;
        this.stuName = stuName;
        this.stuPassword = stuPassword;
    }

    public String getStuId() {
        return stuId;
    }

    public void setStuId(String stuId) {
        this.stuId = stuId;
    }

    public String getStuName() {
        return stuName;
    }

    public void setStuName(String stuName) {
        this.stuName = stuName;
    }

    public String getStuPassword() {
        return stuPassword;
    }

    public void setStuPassword(String stuPassword) {
        this.stuPassword = stuPassword;
    }
}
