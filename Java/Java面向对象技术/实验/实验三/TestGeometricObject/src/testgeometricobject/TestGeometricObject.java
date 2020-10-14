/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testgeometricobject;

import java.util.Scanner;
import java.util.Date;
import java.util.Arrays;
/**
 *
 * @author Zam90
 */
public class TestGeometricObject {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double sum = 0;
        GeometricObject[] object = new GeometricObject[4];
        Circle c1 = new Circle(input.nextDouble());
        Circle c2 = new Circle(input.nextDouble());
        Triangle t1 = new Triangle(input.nextDouble(),input.nextDouble(),input.nextDouble());
        Triangle t2 = new Triangle(input.nextDouble(),input.nextDouble(),input.nextDouble());
        object[0] = c1;
        object[1] = c2;
        object[2] = t1;
        object[3] = t2;
        for(int i = 0;i<object.length;i++)
        {
            sum += object[i].getPerimeter();
        }
        System.out.printf("所有图形的总周长是%.2f\n",sum);
        for(int i = 0;i<object.length;i++)
        {
            System.out.println(object[i].toString());
        }
        double perimeter[] = {c1.getPerimeter(),c2.getPerimeter(),t1.getPerimeter(),t2.getPerimeter()};
        java.util.Arrays.sort(perimeter);
        for(int i = 0;i<perimeter.length;i++)
        {
            System.out.printf("第%d个图形的周长是%.2f\n",i,perimeter[i]);
        }
    }
    }
    
abstract class GeometricObject implements Comparable<GeometricObject>
{
    private String color;
    private Date dateCreated = new Date();
    protected GeometricObject()
    {
        color = "white";
    }
    protected GeometricObject(String c)
    {
        color = c;
    }
    public abstract int compareTo(GeometricObject o);
    public String getColor() 
    {
        return color;
    }
    public void setColor(String color) 
    {
        this.color = color;
    }
    public Date getDateCreated() 
    {
        return dateCreated;
    }
    @Override
    public String toString()
    {
        return "颜色是"+color;
    }
    public abstract double getPerimeter();
}

class Circle extends GeometricObject
{
    private double radius;
    public Circle()
    {
        radius = 10;
        setColor("white");
    }
    public Circle(double r)
    {
        radius = r;
        setColor("white");
    }
    public Circle(double r,String c)
    {
        radius = r;
        setColor(c);
    }
    public double getRadius() 
    {
        return radius;
    }
    public void setRadius(double radius) 
    {
        this.radius = radius;
    }
    @Override
    public double getPerimeter()
    {
        return 2 * Math.PI * radius;
    }
    @Override
    public String toString()
    {
        return "颜色是"+getColor()+"\n圆的半径是"+radius+"\n";
    }
    @Override
    public int compareTo(GeometricObject o)
    {
        if(getPerimeter()>o.getPerimeter())
            return 1;
        else if(getPerimeter()>o.getPerimeter())
            return -1;
        else
            return 0;
    }
}

class Triangle extends GeometricObject
{
    private double a,b,c;
    public Triangle()
    {
        a = 3;
        b = 4;
        c = 5;
        setColor("white");
    }
    public Triangle(double a,double b,double c)
    {
        this.a = a;
        this.b = b;
        this.c = c;
        setColor("white");
    }
    public double getA() 
    {
        return a;
    }
    public void setA(double a) 
    {
        this.a = a;
    }
    @Override
    public double getPerimeter()
    {
        return a + b + c;
    }
    @Override
    public String toString()
    {
        return "颜色是"+getColor()+"\n三角形的三条边是"+a+" "+b+" "+c+"\n";
    }
    @Override
    public int compareTo(GeometricObject o)
    {
        if(getPerimeter()>o.getPerimeter())
            return 1;
        else if(getPerimeter()>o.getPerimeter())
            return -1;
        else
            return 0;
    }
}

