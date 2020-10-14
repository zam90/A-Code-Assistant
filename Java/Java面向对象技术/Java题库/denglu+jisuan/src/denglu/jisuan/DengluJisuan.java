package denglu.jisuan;

import javafx.scene.control.PasswordField;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.GridPane;
import javafx.application.Application;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

public class DengluJisuan extends Application
{
    private final GridPane w1 = new GridPane();
    private final Scene scene1 = new Scene(w1);
    
    private final Label title = new Label("登录窗体");
    private final Label yhm = new Label("用户名：");
    private final TextField userName = new TextField();
    private final Label mm = new Label("密码：");
    private final PasswordField password = new PasswordField();
    private final Button confirm = new Button("确定");
    private final Button cancel = new Button("取消");
    
    private final GridPane w2 = new GridPane();
    private final Scene scene2 = new Scene(w2);
    
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
    public void start(Stage primaryStage)
    {
        title.setFont(Font.font("Arial",FontWeight.BOLD,20));
        HBox h1 = new HBox(10);
        
        primaryStage.setScene(scene1);
        primaryStage.show();
        w1.setHgap(10);
        w1.setVgap(10);
        w1.add(title,2,1,3,1);
        w1.setPadding(new Insets(0,10,0,10));
        w1.add(yhm, 1, 2);
        w1.add(userName,2,2);
        w1.add(mm,1,3);
        w1.add(password,2,3);
        w1.add(h1,2,6,3,6);
        
        h1.getChildren().add(confirm);
        h1.getChildren().add(cancel);
        confirm.setOnAction(e -> yes());
        cancel.setOnAction(e -> primaryStage.close());
        
        primaryStage.setTitle("投资计算器");
        w2.setHgap(10);
        w2.setVgap(10);
        w2.setPadding(new Insets(10));
        w2.add(tzze, 0, 0);
        w2.add(tzns,0,1);
        w2.add(nll, 0, 2);
        w2.add(wlz,0,3);
        w2.add(allAmount, 1, 0);
        w2.add(numOfYears, 1, 1);
        w2.add(rateOfYear, 1, 2);
        w2.add(result, 1, 3);
        w2.add(calculate, 1, 4);
        GridPane.setHalignment(calculate,HPos.RIGHT);
        calculate.setOnAction(e -> getResult());
        
        
    }
    
    private void yes()
    {
        if(userName.getText().equals("Zam") && password.getText().equals("123456"))
        {
            Stage stage = new Stage();
            stage.setTitle("投资计算器");
            stage.setScene(scene2);
            stage.show();
        }
    }
    
    private void getResult()
    {
        double a = Double.parseDouble(allAmount.getText());
        double n = Double.parseDouble(numOfYears.getText());
        double r =Double.parseDouble(rateOfYear.getText());
        double f;
        f = a * Math.pow((1 + (r * 0.01)), n);
        result.setText(String.valueOf(f));
    }

    public static void main(String[] args)
    {
        launch(args);
    }
    
}
