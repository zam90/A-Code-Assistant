/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testcourse;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class TestCourse {

    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Course course1 = new Course(input.next());
        course1.no=input.nextInt();
        course1.addStudent(input.next());
        course1.no=input.nextInt();
        course1.addStudent(input.next());
        course1.toString();
    }
    
}

class Course{
    private String name;
    int numberOfStudent=0;
    int no;
    Student[] student = new Student[99];
    public Course(){
        
    }
    public Course(String name){
        this.name=name;
    }
    public Course(String name,String Student[],int numberOfStudent){
        
    }
    public void addStudent(String name){
        student[numberOfStudent] = new Student(no,name);
        student[numberOfStudent].stuNo=no;
        student[numberOfStudent].name=name;
        numberOfStudent++;
    }
    @Override
    public String toString(){
        int i;
        System.out.println("课程名称 "+name);
        System.out.println("选课学生名单");
        for(i=0;i<numberOfStudent;i++){
            student[i].toString();
        }
        return "";
    }
}

class Student{
    int stuNo;
    String name;
    public Student(){
        
    }
    public Student(int stuNo,String name){
        
    }
    @Override
    public String toString(){
        System.out.println("学号"+stuNo+" 姓名"+name);
        return ("学号"+stuNo+" 姓名"+name);
    }
}