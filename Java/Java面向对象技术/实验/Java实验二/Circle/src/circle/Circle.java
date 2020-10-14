/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package circle;

/**
 *
 * @author Zam90
 */
public class Circle {
    public Circle(){
        
    }
    private double radius;
    private static int numberOfObjects;
    private double area;
    public void setRadius(double radius){
    this.radius=radius;
    }
    public double getRadius(){
    return radius;
    }    
    public Circle(double radius){
        
    }
    public double getArea(double radius){
        area = radius*radius*Math.PI;
        System.out.println("The area of the circle of radius "+radius+" is "+area);
        return area;
    }
    public double getArea(Circle circle1){
        area = circle1.getRadius()*circle1.getRadius()*Math.PI;
        System.out.println("The area of the circle of radius "+this.radius+" is "+this.area);
        return area;
    }
    public static int getNumberOfObjects(){
        return 2;
    }
    
    public static void main(String[] args) {
        Circle circle1 = new Circle(5.0);
        circle1.getArea(5.0);
        Circle circle2 = new Circle(5.5);
        circle2.getArea(5.5);
    }
    
}
