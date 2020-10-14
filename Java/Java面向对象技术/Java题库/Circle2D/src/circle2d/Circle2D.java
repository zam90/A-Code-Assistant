/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package circle2d;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

/**
 *
 * @author Zam90
 */
public class Circle2D extends Application {
        Label x11 = new Label("X");
        Label x12 = new Label("X");
        Label y11 = new Label("Y");
        Label y12 = new Label("Y");
        Label r11 = new Label("R");
        Label r12 = new Label("R");
        private final static Label result = new Label("");
        
        TextField x1 = new TextField();
        double x1r = Double.parseDouble(x1.getText());
        TextField x2 = new TextField();
        double x2r = Double.parseDouble(x2.getText());
        TextField y1 = new TextField();
        double y1r = Double.parseDouble(y1.getText());
        TextField y2 = new TextField();
        double y2r = Double.parseDouble(y2.getText());
        TextField r1 = new TextField();
        double r1r = Double.parseDouble(r1.getText());
        TextField r2 = new TextField();
        double r2r = Double.parseDouble(r2.getText());
        
        Button ok = new Button("OK");

    
    @Override
    public void start(Stage primaryStage) {
        
        Button ok = new Button("OK");
        ok.setOnAction(e->Compare(x1r,x2r,y1r,y2r,r1r,r2r));
        
        BorderPane root2 = new BorderPane();
        CirclePane c1 = new CirclePane(x1r,y1r,r1r);
        CirclePane c2 = new CirclePane(x2r,y2r,r2r);
        root2.getChildren().add(c1);
        root2.getChildren().add(c2);
        
        GridPane root = new GridPane();
        root.add(x11,1,1);root.add(x1,2,1);root.add(y11,3,1);root.add(y1,4,1);root.add(r11,5,1);root.add(r1,6,1);
        root.add(x12,1,2);root.add(x2,2,2);root.add(y12,3,2);root.add(y2,4,2);root.add(r12,5,2);root.add(r2,6,2);
        root.add(ok,1,3);
        root.add(result,1,4);
        
        root2.setBottom(root);
        root2.setCenter(c1);root2.setCenter(c2);
        
        Scene scene = new Scene(root2, 300, 250);
        
        primaryStage.setTitle("Circle-2D");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    public static void Compare(double x1r,double x2r,double y1r,double y2r,double r1r,double r2r){
        double distance = Math.sqrt((x1r - x1r) * (x2r - x1r) + (y2r - y1r) * (y2r - y1r));
        if(r2r + distance < r1r)
        {
            result.setText("一个圆在另一个圆之内");
        }
        else if(r1r + r2r <= distance)
        {
            result.setText("一个圆在另一个圆之外");
        }
        else
        {
            result.setText("两个圆重叠");
        }
    }
    
    public static void main(String[] args) {
        launch(args);
    }
    
}

class CirclePane extends BorderPane{
    double x=0,y=0,r=0;
    Circle c = new Circle();
    public CirclePane() {
        
    }

    public CirclePane(double x, double y, double r) {
        getChildren().add(c);
        this.x = x;
        this.y = y;
        this.r = r;
        c.setCenterX(x);
        c.setCenterY(y);
        c.setRadius(r);
        c.setStroke(Color.BLUE);
    }

}
