/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package addran;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.util.Random;


/**
 *
 * @author Zam90
 */


public class Addran extends Application {
    GridPane pane = new GridPane();
    private TextField text1 = new TextField();
    private TextField text2 = new TextField();
    private TextField text3 = new TextField();
    
    private Button btn1 = new Button("获取题目");
    private Button btn2 = new Button("确认答案");
    @Override
    
    public void start(Stage primaryStage) {
    
    
    pane.setAlignment(Pos.CENTER);
    pane.setPadding(new Insets(11.5,12.5,13.5,14.5));
    pane.setHgap(5.5);
    pane.setVgap(5.5);
    
    pane.add(btn1,0,0);
    pane.add(text1,1,0);
    pane.add(new Label("+"),2,0);
    pane.add(text2,3,0);
    pane.add(new Label("="),4,0);
    pane.add(text3,5,0);
    pane.add(btn2,3,1);
    
    btn1.setOnAction(e -> rand());
    btn2.setOnAction(e -> jud());
    Scene scene = new Scene(pane);
    primaryStage.setTitle("加法计算器");
    primaryStage.setScene(scene);
    primaryStage.show();
    
    }
    private void rand(){
        Random ran = new Random();
        String a= ran.nextInt(100) + " ";
        String b= ran.nextInt(100) + " ";
        text1.setText(a);
        text2.setText(b);

    }
    private void jud(){
        double c=Double.parseDouble(text1.getText().trim());
        double d=Double.parseDouble(text2.getText().trim());
        double e=Double.parseDouble(text3.getText().trim());
        double f=c+d;
        if(e==f)
        {
            System.out.println(f);
            pane.add(new Label("答案正确"),5,1);
        }
        else{
            pane.add(new Label("答案错误"),5,1);
        }
     }
    public static void main(String[] args) {
        launch(args);
    }
    }
