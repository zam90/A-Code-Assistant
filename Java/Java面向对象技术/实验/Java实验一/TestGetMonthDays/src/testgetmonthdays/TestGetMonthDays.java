/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testgetmonthdays;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
class GetMonthDays{
    public static int getMonthDays(int year,int month){
        int days;
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            days=31;
        }else if(month==2){
            if((year%4==0&&year%100!=0)||(year%400==0&&year%100==0)){
                days=29;
            }else{
                days=28;
            }
        }else{
            days=30;
        }
        return days;
    }
}
public class TestGetMonthDays {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int year = input.nextInt();
        int month = input.nextInt();
        int days;
        days = GetMonthDays.getMonthDays(year, month);
        System.out.println(days);
    }
}