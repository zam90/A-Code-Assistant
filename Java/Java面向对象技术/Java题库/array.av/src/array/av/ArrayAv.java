/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package array.av;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class ArrayAv {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double[] x = new double[7];
        for(int i =0;i<6;i++){
            x[i]=input.nextDouble();
        }
        System.out.println(ArrayAv.average(x));
    }
    public static double average(double[] array){
        double sum=0,aver=0;
        
        for(int i =0;i<6;i++){
            sum = sum + array[i];
        }
        aver=sum/6;
        return aver;
    }
}
