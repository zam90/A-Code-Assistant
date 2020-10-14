/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testgeometricobjectcirclerectangle;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;

public class TestGeometricObjectCircleRectangle {

public static void main(String[] a){

Scanner input = new Scanner(System.in);

Circle c = new Circle(input.nextDouble(), input.next(), input.nextBoolean());

c.printCircle();

System.out.println();

System.out.println();




Rectangle r = new Rectangle();

r.setWidth(input.nextDouble());

r.setHeight(input.nextDouble());

r.setColor(input.next());

r.setFilled(input.nextBoolean());

System.out.println(r.toString());

System.out.println("矩形的宽为" + r.getWidth() + "\n矩形的长为" + r.getHeight() + "\n矩形的周长为" + r.getPerimeter() + "\n矩形的面积为" + r.getArea());

}

}

class GeometricObject{
    String color;
    boolean filled;
    String fill;
    public GeometricObject(){
    
    }
    public GeometricObject(String color,boolean filled){
    this.color=color;
    this.filled=filled;
    }
    public String getColor(){
        System.out.println("颜色为"+this.color);
        return color;
    }
    public void setColor(String color){
        this.color = color;
    }
    public boolean getFilled(){
        if(filled==true){
            fill="填充";
        }
        else{
            fill="未填充";
        }
        return filled;
    }
    public void setFilled(boolean filled){
        this.filled = filled;
    }
    @Override
    public String toString(){
        if(filled==true){
            fill="填充";
        }
        else{
            fill="未填充";
        }
        return ("颜色为"+color+fill);
    }
}
class Circle extends GeometricObject{
    private double radius;
    public Circle(){
    
    }
    public Circle(double radius){
    this.radius = radius;
    }
    public Circle(double radius,String color,boolean filled){
    this.radius = radius;
    this.color = color;
    this.filled = filled;
    }
    public double getRadius(){
        return radius;
    }
    public void setRadius(double radius){
        this.radius = radius;
    }
    public double getArea(){
        return this.radius*this.radius*Math.PI;
    }
    public double getPerimeter(){
        return this.radius*2*Math.PI;
    }
    public double getDiameter(){
        return this.radius*2;
    }
    public String printCircle(){
        if(filled==true){
            fill="填充";
        }
        else{
            fill="未填充";
        }
        System.out.println("颜色为"+color+fill+
                "\n圆的半径为"+this.radius+
                "\n圆的直径为"+this.radius*2+
                "\n圆的周长为"+this.radius*2*Math.PI+
                "\n圆的面积为"+this.radius*this.radius*Math.PI
                );
        return ("颜色为"+color+fill+
                "\n圆的半径为"+this.radius+
                "\n圆的直径为"+this.radius*2+
                "\n圆的周长为"+this.radius*2*Math.PI+
                "\n圆的面积为"+this.radius*this.radius*Math.PI
                );
    }
}
class Rectangle extends GeometricObject{
    private double width;
    private double height;
    public Rectangle(){
    
}
    public Rectangle(double width,double height){
    this.width = width;
    this.height = height;
}
    public Rectangle(double width,double height,String color,boolean filled){
    this.width = width;
    this.height = height;
    this.color = color;
    this.filled = filled;
}
    public double getWidth(){
        return width;
    }
    public void setWidth(double width){
        this.width = width;
    }
    public double getHeight(){
        return height;
    }
    public void setHeight(double height){
        this.height = height;
    }
    public double getArea(){
        return this.height*this.width;
    }
    public double getPerimeter(){
        return (this.height+this.width)*2;
    }
}
