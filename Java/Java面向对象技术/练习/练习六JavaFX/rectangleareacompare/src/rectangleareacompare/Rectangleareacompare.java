/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rectangleareacompare;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.Scene;
import javafx.stage.Stage;
/**
 *
 * @author Zam90
 */
public class Rectangleareacompare extends Application 
{
    private TextField text1 = new TextField();
    private TextField text2 = new TextField();
    private TextField text3 = new TextField();
    private TextField text4 = new TextField();
    private TextField text5 = new TextField();
    private Button btn = new Button("开始比较");
    @Override
    public void start(Stage primaryStage) {
    GridPane pane = new GridPane();
    pane.setAlignment(Pos.CENTER);
    pane.setPadding(new Insets(11.5,12.5,13.5,14.5));
    pane.setHgap(5.5);
    pane.setVgap(5.5);
    
    
    pane.add(new Label("第一个矩形"),0,0);
    pane.add(text1,1,0);
    pane.add(new Label("宽度"),0,1);
    pane.add(text2,1,1);
    pane.add(new Label("第二个矩形 宽度"),0,2);
    pane.add(text3,1,2);
    pane.add(new Label("高度"),0,3);
    pane.add(text4,1,3);
    pane.add(new Label("比较结果"), 0, 5);
    pane.add(text5,1,5);
    pane.add(btn,1,6);
    
    btn.setOnAction(e -> Compare());
    Scene scene = new Scene(pane);
    primaryStage.setTitle("比较矩形面积");
    primaryStage.setScene(scene);
    primaryStage.show();
    
    
    
    }
    
    private void Compare()
    {
        double width1 = Double.parseDouble(text1.getText().trim()); 
        double high1 = Double.parseDouble(text2.getText().trim());
        double width2 = Double.parseDouble(text3.getText().trim());
        double high2 = Double.parseDouble(text4.getText().trim());
        double area1 = width1 * high1;
        double area2 = width2 * high2;
        if(area1 == area2)
        {
            text5.setText("两个矩形面积相等");
        }
        else
        {
            text5.setText("两个矩形面积不等");
        }
    }
    public static void main(String[] args) {
        launch(args);
    }
}
