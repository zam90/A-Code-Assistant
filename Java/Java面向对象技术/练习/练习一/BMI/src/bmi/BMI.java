/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bmi;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class BMI {
    private String name;
    private int age;
    private double weight;
    private double height;
    private double BMI;
    public BMI(){
    
    }
    public void setAge( int age ){
       this.age = age;
    } 
    public void setName( String name ){
       this.name = name;
    }
    public void setWeight( double weight ){
       this.weight = weight;
    }
    public void setHeight( double height ){
       this.height = height;
    }
    public int getAge(  ){
       System.out.println("年龄" + age ); 
       return age;
    } 
    public String getName(  ){
       System.out.println("姓名" + name ); 
       return name;
    }
    public double getWeight(  ){
       System.out.println("体重" + weight ); 
       return weight;
    }
    public double getHeight(  ){
       System.out.println("身高" + height ); 
       return height;
    }
    public double getBMI(  ){
       System.out.println("体重指数" + BMI ); 
       return BMI;
    }
       public double BMI( double weight , double height ){
       BMI = weight/(height*height);
       return BMI;
    }
    public void getStatus(  ){
       
        if( 18.5>=BMI ){
           System.out.println("体重状况低重"); 
       }
       else if( (BMI>=18.5)&&(BMI<25.0) ){
           System.out.println("体重状况正常"); 
       }
       else if( (BMI>=25.0)&&(BMI<30.0) ){
           System.out.println("体重状况超重"); 
       }
       else if ( BMI>=30.0 ){
           System.out.println("体重状况肥胖");
       }
       
    }
 
    public static void main(String[] args) {
    BMI BMI = new BMI();
    Scanner input = new Scanner(System.in);
    BMI.name=input.next();
    BMI.age = input.nextInt();
    BMI.weight = input.nextDouble();
    BMI.height = input.nextDouble();
    BMI.getName();
    BMI.BMI(BMI.weight, BMI.height);
    BMI.getAge();
    BMI.getBMI();
    BMI.getStatus();
    
    }
}
