/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vehicle;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class Vehicle {
    float speed;
    float speedup1,speedup2;
    float speeddown1,speeddown2;
    public Vehicle(){
    
}
    public void setSpeed(float speed){
        this.speed = speed;
    }
    public float getSpeed(float speed){
        System.out.println("初始速度是" + speed); 
        return speed;
    }
    public void setSpeedup(float speedup1){
        this.speedup1 = speedup1;
    }
    public float getSpeedup(float speedup1 , float speedup2){
        System.out.println("加速"+speedup1+"后的速度是"+speedup2); 
        return speedup2;
    }
    public void setSpeeddown(float speeddown1){
        this.speeddown1 = speeddown1;
    }
    public float getSpeeddown(float speeddown1 , float speeddown2){
        System.out.println("降速"+speeddown1+"后的速度是"+speeddown2); 
        return speeddown2;
    }
    public float speedUp(float speed , float speedup1){
        speedup2 = speed + speedup1;
        if(speedup2 > 240){
            speedup2 = 240;
            return 240;
        }
        else{
            return speedup2;
        }
    }
    public float speedDown(float speedup2 , float speeddown1){
        speeddown2 = speedup2 - speeddown1;
        if(speeddown2 < 0){
            speeddown2 = 0;
            return 0;
        }
        else{
            return speeddown2;
        }
    }
    public static void main(String[] args) {
        Vehicle vehicle1 = new Vehicle();
        Scanner input = new Scanner(System.in);
        vehicle1.speed = input.nextFloat();
        vehicle1.speedup1 = input.nextFloat();
        vehicle1.speeddown1 = input.nextFloat();
        vehicle1.speedUp(vehicle1.speed , vehicle1.speedup1);
        vehicle1.speedDown(vehicle1.speedup2 , vehicle1.speeddown1);
        vehicle1.getSpeed(vehicle1.speed);
        vehicle1.getSpeedup(vehicle1.speedup1 , vehicle1.speedup2);
        vehicle1.getSpeeddown(vehicle1.speeddown1, vehicle1.speeddown2);
    }
    
}
