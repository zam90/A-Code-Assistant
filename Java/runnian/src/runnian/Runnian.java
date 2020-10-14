/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package runnian;

/**
 *
 * @author Zam90
 */
public class Runnian {

    /**
     * @param args the command line arguments
     */
    public static  boolean isLeapYear(int year) {
	return  (year%4==0 && year%100!=0)||(year%100==0 && year%400==0) ;
}

    
}
