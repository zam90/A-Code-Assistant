/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testleapyear;

import  java.util.Scanner;
class  LeapYear {
    public static  boolean isLeapYear(int year) {
	 return  (year%4==0 && year%100!=0)||(year%100==0 && year%400==0) ;
    }
}
public class TestLeapYear{
	public static void main(String args[]) {
		System.out.println("请输入年：");
		Scanner  sc = new Scanner(System.in);
		int year = sc.nextInt();
		if ( LeapYear.isLeapYear(year)){
		    System.out.println(year+"年是闰年");
		}
		else{
		      System.out.println(year+"年不是闰年");
		}
	}
}
