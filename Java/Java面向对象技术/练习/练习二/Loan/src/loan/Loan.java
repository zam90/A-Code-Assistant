/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package loan;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class Loan {
    public Loan(){
    }
    private double annualInterestRate;
    private int numberOfYears;
    double loanAmount;
    double yly,yhk,zhk; 

    public double getAnnualInterestRate() {
        System.out.println("贷款年利率是"+annualInterestRate);
        return annualInterestRate;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public int getNumberOfYears() {
        System.out.println("贷款年限是"+numberOfYears);
        return numberOfYears;      
    }

    public void setNumberOfYears(int numberOfYears) {
        this.numberOfYears = numberOfYears;
    }

    public double getLoanAmount() {
         System.out.println("贷款总额是"+loanAmount);
        return loanAmount;
    }

    public void setLoanAmount(double loanAmount) {
        this.loanAmount = loanAmount;
    }
    
    public double getMonthlyPayment(){
        yly = annualInterestRate/1200;
        yhk = loanAmount*yly/(1-(1/Math.pow(1+yly,numberOfYears*12)));
        System.out.println("月还款额是"+yhk);
        return yhk;
    }
    
    public double getTotalPayment(){
        zhk = yhk*numberOfYears*12;
         System.out.println("还款总额是"+zhk);
        return zhk;
    }
    
    public static void main(String[] args) {
       Loan loan = new Loan();
       Scanner input = new Scanner(System.in);
       loan.annualInterestRate = input.nextDouble();
       loan.numberOfYears = input.nextInt();
       loan.loanAmount = input.nextDouble();
       loan.getAnnualInterestRate();
       loan.getLoanAmount();
       loan.getNumberOfYears();
       loan.getMonthlyPayment();
       loan.getTotalPayment();
       
    }
    
}