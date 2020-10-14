/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calsoldiery;

/**
 *
 * @author Zam90
 */
public class CalSoldiery {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
               for (int i=3; i<100;i++) {
		if (i%3 == 1&& i%7==5&&i%5==0)
			System.out.println(i);
		}	
    }
    
}
