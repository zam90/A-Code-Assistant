/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafirst;

/**
 *
 * @author Zam90
 */
public class Javafirst {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("HelloJava!");
        int i,c,sum;
	printf("1到n连续求和\n请输入数值n：");
	sum=0;
	scanf("%d",&c);
	for(i=1;i<=c;i++)
	sum=sum+i;
	printf("结果为:%d\n",sum);
	return 0;
    }
    
}
