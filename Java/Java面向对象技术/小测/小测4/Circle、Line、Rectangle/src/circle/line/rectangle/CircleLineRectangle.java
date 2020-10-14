/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package circle.line.rectangle;

import java.awt.Color;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.shape.*;
import javafx.scene.control.Label;


/**
 *
 * @author Zam90
 */
public class CircleLineRectangle extends Application {
        GridPane pane = new GridPane();
        Button btnc = new Button();
        Button btnl = new Button();
        Button btnr = new Button();
    @Override
    public void start(Stage primaryStage) {
        
        pane.setAlignment(Pos.CENTER);
        pane.setPadding(new Insets(11.5,12.5,13.5,14.5));
        pane.setHgap(5.5);
        pane.setVgap(5.5);
        
        btnc.setText("圆");
        btnl.setText("直线");
        btnr.setText("矩形");
        
        pane.add(btnc,1,0);
        pane.add(btnl,0,0);
        pane.add(btnr,2,0);
        btnc.setOnAction(e -> circle());
        btnl.setOnAction(e -> line());
        btnr.setOnAction(e -> rectangle());
        
        pane.add(new Label(""),1,1);
        
        Scene scene = new Scene(pane,200,200);
        primaryStage.setScene(scene);
        primaryStage.show();
        
    }

    private void circle() {
        pane.getChildren().remove(3);
        Circle circle = new Circle();
        circle.setCenterX(100);
        circle.setCenterY(100);
        circle.setRadius(50);
        pane.add(circle,1,2);
    }

    private void line() {
        pane.getChildren().remove(3);
        Line line = new Line(10,10,40,40);
        pane.add(line,1,2);
    }

    private void rectangle() {
        pane.getChildren().remove(3);
        Rectangle rectangle = new Rectangle(25,50,100,100);
        pane.add(rectangle,1,2);
    }
    
    
    
    public static void main(String[] args) {
        launch(args);
    }
}