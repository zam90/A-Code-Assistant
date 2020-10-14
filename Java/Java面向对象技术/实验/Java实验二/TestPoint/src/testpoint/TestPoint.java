/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testpoint;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
class Point{
double x,y;
double distance;
public Point(){

}
public Point(double x,double y){
this.x=x;
this.y=y;
}
public void setX(double x){
this.x=x;
}
public double getX(){
return x;
} 
public void setY(double y){
this.y=y;
}
public double getY(){
return y;
} 
public double distance(double a , double b){
    distance = Math.sqrt((a-x)*(a-x)+(b-y)*(b-y));
    return distance;
}
public double distance(Point p2){
    return this.distance(p2.getX(),p2.getY());
}

}

public class TestPoint {

  public static void main(String[] a){

  Scanner in = new Scanner(System.in);

  Point p1 = new Point();

  p1.setX(in.nextDouble());

  p1.setY(in.nextDouble());

  Point p2 = new Point(in.nextDouble(),in.nextDouble());

  System.out.printf("\n两点距离为%.2f" , p1.distance(p2));

  System.out.printf("\n两点距离为%.2f" , p1.distance(20,30));

}

}
