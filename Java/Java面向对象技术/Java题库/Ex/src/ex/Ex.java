/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ex;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;

abstract class Figure{
    abstract double getArea();
}

class Rectangle extends Figure{
    double a,b;

    public Rectangle(double a, double b) {
        this.a = a;
        this.b = b;
    }
    
    public double getArea(){
        return a*b;
    }
}

class Circle extends Figure{
    double a;

    public Circle(double a) {
        this.a = a;
    }
    
    public double getArea(){
        return a*a*3.14;
    }
}

public class Ex {

    public static void main(String[] args){

        Scanner input=new Scanner(System.in);

        double a=input.nextDouble();

        double b=input.nextDouble();

        double c=input.nextDouble();

        double d=input.nextDouble();

        double e=input.nextDouble();

        double f=input.nextDouble();

        Figure g[]={new Rectangle(a,b),new Circle(c),new Circle(d),new Rectangle(e,f)};

        System.out.println("the total area is "+ sum(g));

    }

    static double sum(Figure[] g){
        double sum = 0;
        for(int i=0;i<4;i++){
            sum = sum + g[i].getArea();
        }
        return sum;
    }

}
