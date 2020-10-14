/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rectangle.mianji.zhouchang;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class RectangleMianjiZhouchang {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Rectangle rectangle = new Rectangle();
        rectangle.setChang(input.nextDouble());
        rectangle.setKuan(input.nextDouble());
        rectangle.ac();
        rectangle.area();
    }
    
}
class Rectangle{
    double chang=0,kuan=0;
    public Rectangle() {
    }
    public Rectangle(double chang,double kuan) {
        this.chang=chang;
        this.kuan=kuan;
    }

    public double getChang() {
        return chang;
    }

    public void setChang(double chang) {
        this.chang = chang;
    }

    public double getKuan() {
        return kuan;
    }

    public void setKuan(double kuan) {
        this.kuan = kuan;
    }
    public void area(){
        double area=chang*kuan;
        System.out.println("面积是"+area);
    }
    public void ac(){
        double ac=(chang+kuan)*2;
        System.out.println("周长是"+ac);
    }
}