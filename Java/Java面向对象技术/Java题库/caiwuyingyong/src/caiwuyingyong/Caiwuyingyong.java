/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package caiwuyingyong;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
import java.lang.Math;
public class Caiwuyingyong {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        a a = new a();
        a.setMoney(input.nextDouble());
        a.setYrate(input.nextDouble());
        a.setMrate(a.getYrate());
        a.setYear(input.nextDouble());
        a.show();
    }
    
}
class a{
    double mrate=0,yrate=0,money=0,year=0;

    public a() {
    }

    public double getMrate() {
        return mrate;
    }

    public void setMrate(double yrate) {
        this.mrate = yrate/1200;
    }

    public double getYrate() {
        return yrate;
    }

    public void setYrate(double yrate) {
        this.yrate = yrate;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(double money) {
        this.money = money;
    }

    public double getYear() {
        return year;
    }

    public void setYear(double year) {
        this.year = year;
    }
    public void show(){
        double x=0;
        x=money*Math.pow(1+mrate,year*12);
        System.out.println("未来投资额为"+x);
    }
}