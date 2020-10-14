/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testbill;

import java.util.Scanner;
/**
 *
 * @author Zam90
 */
public class Testbill {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        WaterBill w = new WaterBill(input.nextDouble());
        GasBill g = new GasBill(input.nextDouble());
        double sum = g.getBill() + w.getBill();
        System.out.print("该居民缴费总额为"+sum);
    }
    
}

abstract class Bill
{
    protected double volume;
    public Bill()
    {
        volume = 0;
    }
    public Bill(double volume)
    {
        this.volume = volume;
    }
    public double getVolume() 
    {
        return volume;
    }
    public abstract double getBill();
}

class GasBill extends Bill
{
    private double rate = 2.28;
    public GasBill()
    {
        volume = 0;
    }
    public GasBill(double volume)
    {
        this.volume = volume;
    }
    @Override
    public double getBill()
    {
        return volume * rate;
    }
}

class WaterBill extends Bill
{
    private double[] rate = {5,7,9};
    public WaterBill()
    {
        volume = 0;
    }
    public WaterBill(double volume)
    {
        this.volume = volume;
    }
    @Override
    public double getBill()
    {
        if(volume<=180&&volume>0)
            return rate[0] * volume;
        else if(volume<=260)
            return 900 + rate[1] * (volume-180);
        else
            return 1460 + rate[2] * (volume-260);
    }
}