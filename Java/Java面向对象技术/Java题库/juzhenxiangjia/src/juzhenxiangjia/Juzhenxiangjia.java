/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package juzhenxiangjia;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class Juzhenxiangjia {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double[][] j1 = {{1,2,3},{4,5,6},{7,8,9}};
        double[][] j2 = {{0,2,4},{1,4.5,2.2},{1.1,4.3,5.2}};
        double[][] j4 = Juzhenxiangjia.addMatrix(j1, j2);
        for(int i=0;i<3;i++){
            System.out.println(j4[i][0]+" "+j4[i][1]+" "+j4[i][2]+" ");
        }
        
    }
    public static double[][] addMatrix(double[][] a, double[][] b){
        double[][] j3 = new double[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
            j3[i][j]=a[i][j]+b[i][j];
            }
        }
        return j3;
    }
}
