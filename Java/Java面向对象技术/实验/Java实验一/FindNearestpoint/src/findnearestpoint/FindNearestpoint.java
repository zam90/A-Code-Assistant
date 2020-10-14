/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package findnearestpoint;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
class Distance{
    public static double distance(double x1,double y1,double z1,double x2,double y2,double z2){
        double d;
        double sum;
        sum = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1);
        d = Math.sqrt(sum);
        return d;
    }
}
public class FindNearestpoint {
    public static double[][] getArray(double[][] x){
        double[][] matrix;
        matrix = new double[6][3];
        Scanner input = new Scanner(System.in);
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                matrix[i][j] = input.nextDouble();
            }
        }
        return matrix;
    }
    public static void main(String[] args){
        double[][] matrix;
        matrix = new double[6][3];
        double[][] array = getArray(matrix);
        double[] myList;
        myList = new double[15];
        int x;
        x=0;
        for(int i=0;i<6;i++){
            for(int j=i+1;j<6;j++,x++){
                myList[x] = Distance.distance(array[i][0],array[i][1],array[i][2],array[j][0],array[j][1],array[j][2]);
            }
        }
        double min;
        min = myList[0];
        for(int t=1;t<15;t++){
            if(min>myList[t]){
                min = myList[t];
            }
        }
        for(int p=0;p<6;p++){
            for(int q=p+1;q<6;q++){
                if(min == Distance.distance(array[p][0],array[p][1],array[p][2],array[q][0],array[q][1],array[q][2])){
                   System.out.println("最近的两个点是("+array[p][0]+","+array[p][1]+","+array[p][2]+")和("+array[q][0]+","+array[q][1]+","+array[q][2]+")");
                   break;
            }
            }
        }   
    }    
}