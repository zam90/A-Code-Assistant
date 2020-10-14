/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package touzijisuanqi;

import java.awt.Insets;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;
import java.lang.Math;

/**
 *
 * @author Zam90
 */
public class Touzijisuanqi extends Application {
    private final GridPane root1 = new GridPane();
    private final Scene scene1 = new Scene(root1);
    
    private final Label title = new Label("登录窗体");
    private final Label yhm = new Label("用户名：");
    private final TextField userName = new TextField();
    private final Label mm = new Label("密码：");
    private final PasswordField password = new PasswordField();
    private final Button confirm = new Button("确定");
    private final Button cancel = new Button("取消");
    private final Label error = new Label("");
    
    private final GridPane root2 = new GridPane();
    private final Scene scene2 = new Scene(root2);
    
    private final Label tzze = new Label("投资总额");
    private final TextField allAmount = new TextField();
    private final Label tzns = new Label("投资年数");
    private final TextField numOfYears = new TextField();
    private final Label nll = new Label("年利率");
    private final TextField rateOfYear = new TextField();
    private final Label wlz = new Label("未来值");
    private final TextField result = new TextField();
    private final Button calculate = new Button("计算");
    
    
    @Override
    public void start(Stage primaryStage) {
        
        
        root1.add(yhm, 1, 1);
        root1.add(userName, 1, 2);
        root1.add(mm, 2, 1);
        root1.add(password, 2, 2);
        root1.add(confirm, 1, 3);
        root1.add(cancel, 2, 3);
        root1.add(error, 1, 4);
        
        confirm.setOnAction(e -> dl());
        cancel.setOnAction(e -> primaryStage.close());
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene1);
        primaryStage.show();
    }
    public void dl(){
        if("zam".equals(userName.getText()) && "123456".equals(password.getText())){
            Stage stage = new Stage();
            root2.add(tzze, 1, 1);
            root2.add(allAmount, 2, 1);
            root2.add(tzns, 1, 2);
            root2.add(numOfYears, 2, 2);
            root2.add(nll, 1, 3);
            root2.add(rateOfYear, 2, 3);
            root2.add(wlz, 1, 4);
            root2.add(result, 2, 4);
            root2.add(calculate, 1, 5);
            calculate.setOnAction(e -> js());
            stage.setTitle("Hello World!!");
            stage.setScene(scene2);
            stage.show();
        }
        else{
            error.setText("密码错误!");
            
        }
    
    
}
    public void js(){
        double a = Double.parseDouble(allAmount.getText());
        double n = Double.parseDouble(numOfYears.getText());
        double r =Double.parseDouble(rateOfYear.getText());
        double f;
        f = a * Math.pow((1 + (r * 0.01)), n);
        result.setText(String.valueOf(f));
        
    }
    public static void main(String[] args) {
        launch(args);
    }
    
}
