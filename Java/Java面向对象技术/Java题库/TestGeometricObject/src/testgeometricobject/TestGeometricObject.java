/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testgeometricobject;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class TestGeometricObject {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Circle c1 = new Circle();
        Circle c2 = new Circle();
        c1.setRadius(input.nextDouble());
        c1.setColor(input.next());
        c2.setRadius(input.nextDouble());
        c2.setColor(input.next());
        String c = "";
        if(c1.getRadius()==c2.getRadius()){
            System.out.println("两个圆相等");
        }
        else if(c1.getRadius()>=c2.getRadius()){
            System.out.println("大圆的属性" + c1.toString());
        }
        else{
            System.out.println("大圆的属性" + c2.toString());
        }
    }
    
}

abstract class GeometricObject {
    private String color;
    String a="public static GeometricObject max(GeometricObject o1, GeometricObject o2)";
    public GeometricObject() {
    }

    public GeometricObject(String color) {
        this.color = color;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
    
    abstract double getArea();
    
}

class Circle extends GeometricObject{
    protected double radius;
    String b ="public boolean equals(Circle circle) ";
    public Circle() {
    }

    public Circle(double radius, String color) {
        super(color);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
    
    @Override
    public double getArea(){
        return 0;
    }
    
    @Override
    public String toString(){
        return "\n颜色是 "+getColor()+"\n半径是 "+getRadius();
    }
}