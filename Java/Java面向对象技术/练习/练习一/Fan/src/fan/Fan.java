/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fan;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class Fan {
    private String color;
    private int speed=3;
    private double radius;
    static private boolean on;
    public Fan(){
    
    }
    public void setRadius( double radius ){
       this.radius = radius;
    } 
    public void setSpeed( int speed ){
       this.speed = speed;
    }
    public void setColor( String color ){
       this.color = color;
    }
    public void setOn( boolean on ){
       this.on = on;
    }
    public double getRadius(  ){
       System.out.println("半径是" + radius ); 
       return radius;
    } 
    public int getSpeed(  ){
       System.out.println("该风扇的速度为" + speed ); 
       return speed;
    }
    public String getColor(  ){
       System.out.println("该风扇的颜色是" + color ); 
       return color;
    }
    
 
public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    Fan fan1 = new Fan();
    fan1.radius = input.nextDouble();
    fan1.color=input.next();
    Fan.on=input.nextBoolean();
    {
    if(on==true){
    fan1.getSpeed();
    System.out.println("颜色是" + fan1.color);
    fan1.getRadius();
       }
    else if (on==false){
           System.out.println("风扇没有开启"); 
           System.out.println("该风扇的颜色是" + fan1.color);
        fan1.getRadius();
        System.out.println("");
       }
    }
    Fan fan2 = new Fan();
    fan2.radius = input.nextDouble();
    fan2.color=input.next();
    Fan.on=input.nextBoolean();
    {
    if(on==true){
    System.out.println("该风扇的速度为2");
    System.out.println("颜色是" + fan2.color);
    fan2.getRadius();
       }
    else if(on==false){
           System.out.println("风扇没有开启"); 
           System.out.println("该风扇的颜色是" + fan2.color);
        fan2.getRadius();
       }
    }
    
    
    }
}