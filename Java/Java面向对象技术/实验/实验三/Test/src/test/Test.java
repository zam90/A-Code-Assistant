/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.util.Scanner;
/**
 *
 * @author Zam90
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Rectangle r1 = new Rectangle(input.nextDouble(),input.nextDouble());
        Circle c1 = new Circle(input.nextDouble());
        System.out.print(r1.toString()+"\n\n"+c1.toString());
    }
    
}
class Rectangle
{
    private double width,length;
    public Rectangle()
    {
        width = 0;
        length = 0;
    }
    public Rectangle(double w,double h)
    {
        width = w;
        length = h;
    }
    public double getWidth() 
    {
        return width;
    }
    public void setWidth(double width) 
    {
        this.width = width;
    }
    public double getHeight() 
    {
        return length;
    }
    public void setHeight(double length) 
    {
        this.length = length;
    }
    public double getArea()
    {
        return width * length;
    }
    @Override
    public String toString() 
    {
        return "矩形的宽为 "+width+"\n矩形的高为"+length+"\n矩形的面积为"+getArea();
    }
}

class Circle
{
     private double radius;
     public Circle()
     {
         radius = 0;
     }
     public Circle(double r)
     {
         radius = r;
     }
    public double getRadius() 
    {
        return radius;
    }
    public void setRadius(double radius) 
    {
        this.radius = radius;
    }
     public double getArea()
     {
         return 3.14 * radius * radius;
     }
     @Override
    public String toString() 
    {
        return "圆形的半径为 "+radius+"\n圆形的面积为"+getArea();
    }
}
