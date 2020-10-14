/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package circle2d.pkg2pir;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
import java.lang.Math;
public class Circle2d2pir {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        circle circle1 = new circle();
        circle1.setR(input.nextDouble());
        circle1.ac();
        circle1.area();
    }
    
}
class circle{
    double r;
    double pi=3.14;
    double area,ac;
    public circle() {
    }

    public circle(double r) {
        this.r = r;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }
    public void area(){
        area=pi*r*r;
        System.out.println("面积是"+area);
    }
    public void ac(){
        ac=pi*2*r;
        System.out.println("周长是"+ac);
    }
}