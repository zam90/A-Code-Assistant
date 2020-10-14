/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package textgeometricobjectinterface;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
import java.lang.Math;
public class TextGeometricObjectInterface {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Rectangle r = new Rectangle(input.nextDouble(),input.nextDouble());
        Circle c = new Circle(input.nextDouble());
        r.displayZc();
        r.displayMj();
        c.displayZc();
        c.displayMj();
        
    }
    
}

interface GeometricObject{
    abstract void displayZc();
    abstract void displayMj();
}

class Rectangle implements GeometricObject{
    double a,b;

    public Rectangle(double a, double b) {
        this.a = a;
        this.b = b;
    }
    
    @Override
    public void displayZc(){
        System.out.println("图形的周长"+(2*(a+b)));
    }
    
    @Override
    public void displayMj(){
        System.out.println("图形的面积"+(a*b));
    }
}

class Circle implements GeometricObject{
    double r;

    public Circle(double r) {
        this.r = r;
    }
    
    @Override
    public void displayZc(){
        System.out.println("图形的周长"+(2*Math.PI*r));
    }
    
    @Override
    public void displayMj(){
        System.out.println("图形的面积"+(Math.PI*r*r));
    }
}