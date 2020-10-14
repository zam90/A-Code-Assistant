/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teststar;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class TestStar {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Position p = new Position();
        Star s = new Star();
        s.setType(input.nextInt());
        p.setRow(input.nextInt());
        p.setColumn(input.nextInt());
        s.Jcolor();
        System.out.println("颜色 "+s.getColor()+"\n 行 "+p.getRow()+"\n 列 "+p.getColumn());
    }
    
}

class Position{
    private int row;
    private int column;
    
    public Position() {
    }
    
    public Position(int row, int column) {
        this.row = row;
        this.column = column;
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getColumn() {
        return column;
    }

    public void setColumn(int column) {
        this.column = column;
    }
    @Override
    public String toString(){
        return "";
    }
}

class Star{
    private int type;
    String color;
    Position p = new Position();

    public Star() {
    }

    public Star(Position p,int type) {
        this.type = type;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Position getP() {
        return p;
    }

    public void setP(Position p) {
        this.p = p;
    }
    public void Jcolor(){
    if(type==0)
    {
        color="红色";
    }
    if(type==1)
    {
        color="蓝色";
    }
    if(type==2)
    {
        color="黄色";
    }
    if(type==3)
    {
        color="绿色";
    }
    }
    @Override
    public String toString(){
        System.out.println("颜色 "+color+"\n 行 "+p.getRow()+"\n 列 "+p.getColumn());
        return "颜色 "+color+"\n 行 "+p.getRow()+"\n 列 "+p.getColumn();
    }
}