/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rectanglebigger;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

/**
 *
 * @author Zam90
 */
public class Rectanglebigger extends Application {
    
    BorderPane root = new BorderPane();
    
    @Override
    public void start(Stage primaryStage) {
        rectangle r = new rectangle(10,10,100,100,1,1);
        
        Button btn = new Button();
        btn.setText("Bigger it!");
        btn.setOnAction(e->r.bigger());
        
        
        root.setCenter(r);
        root.setBottom(btn);
        
        Scene scene = new Scene(root, 300, 250);
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}

class rectangle extends BorderPane{
    Rectangle r = new Rectangle();
    double x,y,h,w,ah,aw;
    public rectangle(double x, double y, double h, double w, double ah, double aw) {
        getChildren().add(r);
        this.x = x;
        this.y = y;
        this.h = h;
        this.w = w;
        this.ah = ah;
        this.aw = aw;
        r.setX(x);
        r.setY(y);
        r.setHeight(h);
        r.setWidth(w);
        r.setArcHeight(ah);
        r.setArcWidth(aw);
    }
    public void bigger(){
        r.setHeight(r.getHeight()+10);
        r.setWidth(r.getWidth()+10);
    }
}