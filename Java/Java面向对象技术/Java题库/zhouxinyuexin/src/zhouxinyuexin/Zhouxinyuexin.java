/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package zhouxinyuexin;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class Zhouxinyuexin {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Company company = new Company();
        MonthWorker zs = new MonthWorker();
        WeekWorker ls = new WeekWorker();
        company.addEmployee(zs);
        company.addEmployee(ls);
        zs.setName(input.next());
        zs.setMonthSal(input.nextDouble());
        ls.setName(input.next());
        ls.setWeekSal(input.nextDouble());
        System.out.println(zs.toString());
        System.out.println(ls.toString());
        System.out.println("\n公司年工资总额 "+(zs.earnings()+ls.earnings()));
    }
    
}

abstract class Employee{
    protected String name;

    public Employee() {
    }

    public Employee(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public abstract double earnings();
    
    @Override
    public abstract String toString();
}

class MonthWorker extends Employee{
    private double monthSal;

    public MonthWorker() {
    }
    
    public MonthWorker(double monthSal, String name) {
        super(name);
        this.monthSal = monthSal;
    }

    public double getMonthSal() {
        return monthSal;
    }

    public void setMonthSal(double monthSal) {
        this.monthSal = monthSal;
    }
    @Override
    public double earnings(){
        return monthSal*12;
    }
    
    @Override
    public String toString(){
        return "姓名 "+getName()+"\n月薪为 "+monthSal+"\n年薪为 "+earnings();
    }
}

class WeekWorker extends Employee{
    private double weekSal;

    public WeekWorker() {
    }
    
    public WeekWorker(double weekSal, String name) {
        super(name);
        this.weekSal = weekSal;
    }

    public double getWeekSal() {
        return weekSal;
    }

    public void setWeekSal(double weekSal) {
        this.weekSal = weekSal;
    }
    @Override
    public double earnings(){
        return weekSal*52;
    }
    
    @Override
    public String toString(){
        return "姓名 "+getName()+"\n周薪为 "+weekSal+"\n年薪为 "+earnings();
    }
}

class Company{
    private int numberOfWorkers=0;
    MonthWorker zs = new MonthWorker();
    WeekWorker ls = new WeekWorker();
    public Company() {
    }
    
    public double computeTotalSal(){
        return zs.earnings()+ls.earnings();
    }
    
    public void addEmployee(Employee e){
        
    }
    
    @Override
    public String toString(){
        return "\n\n公司年工资总额 "+computeTotalSal();
    }
}