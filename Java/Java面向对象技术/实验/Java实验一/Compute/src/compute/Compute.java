/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package compute;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
class Mean{
    public static double mean(double[] x){
        double sum=0;
        for(int i=0;i<6;i++){
            sum=sum+x[i];
        }
        return sum/6;
    }
}
class Deviation{
        public static double deviation(double[] x){
        double sum1=0,sum2=0;
        for(int i=0;i<6;i++){
            sum2=sum2+x[i];
        }
        for(int i=0;i<6;i++){
            sum1=sum1+Math.pow((x[i]-sum2/6),2);
        }
        return Math.sqrt(sum1/5);
    }
}
public class Compute{
    public static void main(String[] args){
        double[] myList = new double[6];
        Scanner input = new Scanner(System.in);
        for(int i=0;i<6;i++){
            myList[i] = input.nextDouble();
        }
        double result1;
        double result2;
        result1 = Mean.mean(myList);
        result2 = Deviation.deviation(myList);
        System.out.println("平均值是 " + result1);
        System.out.println("标准差是 " + result2);
    }
}