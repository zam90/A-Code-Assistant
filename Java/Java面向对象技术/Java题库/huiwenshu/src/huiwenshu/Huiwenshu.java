/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package huiwenshu;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class Huiwenshu {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x=input.nextInt();
        int ge,bai;
        ge=x/100;
        bai=(x%100)%10;
        if(ge==bai){
            System.out.println(x+"是一个回文数");
        }
        else{
            System.out.println(x+"不是一个回文数");
        }
    }
    
}
