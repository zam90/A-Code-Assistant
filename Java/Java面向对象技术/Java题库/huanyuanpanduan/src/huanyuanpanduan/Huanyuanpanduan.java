/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package huanyuanpanduan;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.shape.Circle;
import javafx.scene.paint.Color;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import java.util.Random;

/**
 *
 * @author Zam90
 */
public class Huanyuanpanduan extends Application {
    
    private final Button makeCircle = new Button("随机生成圆");
    private final Button makePoint = new Button("随机生成点");
    private final Button clearAll = new Button("清除");
    private final Label result = new Label("");
    private final Pane pane = new Pane();
    private final Circle c1 = new Circle();
    private final Scene scene = new Scene(pane, 600, 500);
    private final VBox v1 = new VBox(10);
    @Override
    public void start(Stage primaryStage)
    {
        c1.setStroke(Color.RED);
        c1.setFill(null);
        v1.getChildren().add(makeCircle);
        v1.getChildren().add(makePoint);
        v1.getChildren().add(clearAll);
        v1.getChildren().add(result);
        pane.setPadding(new Insets(10));
        pane.getChildren().add(v1);
        pane.getChildren().add(c1);
        
        pane.setOnMousePressed(e -> {
            c1.setCenterX(e.getSceneX());
            c1.setCenterY(e.getSceneY());
            c1.setRadius(0);
        });
        
        pane.setOnMouseDragged(e -> {
            c1.setRadius(Math.pow((c1.getCenterX() - e.getSceneX())*(c1.getCenterX() - e.getSceneX()) + (c1.getCenterY() - e.getSceneY())*(c1.getCenterY() - e.getSceneY()), 0.5));
        });
        
        makeCircle.setOnAction(e -> drawCircle());
        makePoint.setOnAction(e -> drawPoint());
        clearAll.setOnAction(e -> clear());
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    private void drawCircle()
    {
        clear();
        double height = scene.getHeight();
        double width = scene.getWidth();
        int randomRadius = (int)(Math.random() * ((height + width) / 4));
        int randomX = (int)(Math.random() * width);
        int randomY = (int)(Math.random() * height);
        Circle c2 = new Circle(randomX, randomY, randomRadius);
        c2.setStroke(Color.BLUE);
        c2.setFill(null);
        pane.getChildren().add(c2);
        double distance;
        distance = Math.sqrt((c2.getCenterX() - c1.getCenterX()) * (c2.getCenterX() - c1.getCenterX()) + (c2.getCenterY() - c1.getCenterY()) * (c2.getCenterY() - c1.getCenterY()));
        if(c2.getRadius() + distance < c1.getRadius())
        {
            result.setText("一个圆在另一个圆之内");
        }
        else if(c1.getRadius() + c2.getRadius() <= distance)
        {
            result.setText("一个圆在另一个圆之外");
        }
        else
        {
            result.setText("两个圆重叠");
        }
    }
    
    private void drawPoint()
    {
        clear();
        double height = scene.getHeight();
        double width = scene.getWidth();
        int randomX = (int)(Math.random() * width);
        int randomY = (int)(Math.random() * height);
        Circle c2 = new Circle(randomX, randomY, 0.1);
        c2.setStroke(Color.BLACK);
        c2.setFill(null);
        pane.getChildren().add(c2);
        double distance;
        distance = Math.sqrt((c2.getCenterX() - c1.getCenterX()) * (c2.getCenterX() - c1.getCenterX()) + (c2.getCenterY() - c1.getCenterY()) * (c2.getCenterY() - c1.getCenterY()));
        if(c2.getRadius() + distance < c1.getRadius())
        {
            result.setText("点在圆之内");
        }
        else
        {
            result.setText("点在圆之外");
        }
    }
    
    private void clear()
    {
        pane.getChildren().clear();
        pane.getChildren().add(v1);
        pane.getChildren().add(c1);
    }

    public static void main(String[] args)
    {
        launch(args);
    }
    
}
