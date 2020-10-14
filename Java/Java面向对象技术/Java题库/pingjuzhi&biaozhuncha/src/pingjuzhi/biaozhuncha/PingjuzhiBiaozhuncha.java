/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pingjuzhi.biaozhuncha;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
import java.lang.Math;
public class PingjuzhiBiaozhuncha {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ca ca = new ca();
        double[] x = new double[6];
        int i;
        for(i=0;i<6;i++)
        {
            x[i]=input.nextDouble();
        }
        for(double element: x){
            ca.x=x;
        }
        double p=ca.mean(x);
        System.out.println("平均值是"+p);
        System.out.println("标准差是"+ca.deviation(x,p));
    }
    
}
class ca{
    double[] x = new double[6];
    
    public ca() {
    }
    public ca(double[] x){
        this.x=x;
    }
    public static double mean(double[] x){
        int i;double re=0;
        for(i=0;i<6;i++)
        {
            re=re+x[i];
        }
        return re/6;
    }
    
    public static double deviation(double[] x, double re){
        int i;double ree=0;
        for(i=0;i<6;i++)
        {
            ree=ree+(x[i]-re)*(x[i]-re);
        }
        return Math.sqrt(ree/5);
    }
}