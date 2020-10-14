/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package huiwen;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class Huiwen {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        jhuiwen n = new jhuiwen(input.nextLine());
        n.j();
        n.re();
    }
    
}

class jhuiwen{
    String huiwen;
    String a;
    int i;

    public jhuiwen(String huiwen) {
        this.huiwen = huiwen;
    }
    
    public void j(){
        for(i=0;i<huiwen.length()-1;i++){
            if(huiwen.charAt(i)!=huiwen.charAt(huiwen.length()-1-i))
            {
                a="不是一个回文";
            }
            else{
                a="是一个回文";
            }
        }
    }
    public void re(){
        System.out.println(huiwen+a);
    }
}