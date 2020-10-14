/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testcompany;

import java.util.Scanner;
/**
 *
 * @author Zam90
 */
public class Testcompany {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); 
        MonthWorker m = new MonthWorker(input.next(),input.nextDouble());
        WeekWorker w = new WeekWorker(input.next(),input.nextDouble());
        m.getNearning();
        m.Print();
        w.getEarning();
        w.Printl();
        System.out.println("");
        Company c = new Company();
         double z;
        z = m.getNearning()+w.getEarning();
        System.out.println("公司年工资总额"+z);

    }
}

abstract class Employee{
    Employee(){
        
    }
    protected String name;

    public Employee(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public abstract Double earning ();

    
    
}

class MonthWorker extends Employee{

    private double monthSal;
    double nearning;

    public double getNearning() {
        nearning = monthSal*12;
        return nearning;
    }

    public void setNearning(double earning) {
        this.nearning = earning;
    }

    public MonthWorker() {
    }

    public MonthWorker(double monthSal) {
        this.monthSal = monthSal;
    }

    public MonthWorker( String name,double monthSal) {
        super(name);
        this.monthSal = monthSal;
    }

    public double getMonthSal() {
        return monthSal;
    }

    public void setMonthSal(double monthSal) {
        this.monthSal = monthSal;
    }
    
    public void Print() {
        System.out.println("姓名 "+getName());
        System.out.println("月薪为 "+getMonthSal());
        System.out.println("年薪为 "+getNearning());
                
    }
    @Override
    public Double earning() {
        double earning;
        earning = monthSal*12;
        return earning;
    }
    
}
    class WeekWorker extends Employee{
        private double weekSal;
        double earning;

    public WeekWorker() {
    }

   

    public WeekWorker(String name,double weekSal ) {
        super(name);
        this.weekSal = weekSal;
        
    }

    public double getWeekSal() {
        return weekSal;
    }

    public void setWeekSal(double weekSal) {
        this.weekSal = weekSal;
    }

    public double getEarning() {
        earning = weekSal*52;
        return earning;
    }

    public void setEarning(double earing) {
        this.earning = weekSal*52;
    }
    
    

    @Override
    public Double earning() {
        double earning ;
        earning = weekSal*52;
        return earning;
        
    }
    public void Printl(){
        System.out.println("姓名 "+getName());
        System.out.println("周薪为 "+getWeekSal());
        System.out.println("年薪为 "+getEarning());
    }
        
}
class Company{
    private int n = 0;
    Employee[] a = new Employee[10];
    MonthWorker m = new MonthWorker();
    WeekWorker w = new WeekWorker();
    public Company() {
    }
    public void addEmployee(Employee e)
    {
        Employee a = new Employee() {
            int i =0;
            @Override
            public Double earning() {
                throw new UnsupportedOperationException("Not supported yet."); 
            }
        };
        
    }
    
}