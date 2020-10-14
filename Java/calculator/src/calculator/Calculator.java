/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/**
 *
 * @author Zam90
 */
public class Calculator extends Application {
    
    //创建计算按钮
    Button sure = new Button();
    //创建清除按钮
    Button clear = new Button();
    //创建x输入框
    TextField x = new TextField();
    //创建运算符输入框
    TextField ff = new TextField();
    //创建y输入框
    TextField y = new TextField();
    //创建=符号标签
    Label ref = new Label("=");
    //创建结果标签
    Label result = new Label();
    //符号输入错误提示
    Label notice = new Label("");
    
    //创建布局格式
    GridPane root = new GridPane();
    //创建场景
    Scene scene = new Scene(root, 900, 100);
    
    @Override
    public void start(Stage primaryStage) {
        //计算按钮属性
        sure.setText("计算");
        sure.setOnAction(e->ca());
        //清除按钮属性
        clear.setText("清除");
        clear.setOnAction(e->clear());
        
        //向布局中添加结点
        root.add(x,1,1);
        root.add(ff,2,1);
        root.add(y,3,1);
        root.add(ref,4,1);
        root.add(result,5,1);
        root.add(sure,2,2);
        root.add(clear,3,2);
        root.add(notice,3,3);
        
        //将布局应用于场景
        primaryStage.setTitle("计算器");
        primaryStage.setScene(scene);
        primaryStage.show();
        
    }
    //启动计算器
    public static void main(String[] args) {
        launch(args);
    }
    //计算按钮方法
    public void ca(){
        //获取符号并判断符号
        if(("张京宇".equals(x.getText())&&"石一兰".equals(y.getText()))||("张京宇".equals(y.getText())&&"石一兰".equals(x.getText())))
        {
            if(("+".equals(ff.getText()))){
            result.setText("一生一世");
            notice.setText("恭喜你发现了隐藏彩蛋，祝福他们吧！");
            }
            else if(("-".equals(ff.getText()))){
            result.setText("没你可不行啊");
            notice.setText("分不开的两个人呀");
            }
            else if(("*".equals(ff.getText()))){
            result.setText("海枯石烂");
            notice.setText("长长的路我们慢慢的走");
            }
            else if(("/".equals(ff.getText()))){
            result.setText(y.getText());
            notice.setText("除了你，还是你");
            }
            else if(("%".equals(ff.getText()))){
            result.setText("往后余生");
            notice.setText("余生都是你");
            }
        }
        else if(("+".equals(ff.getText()))){
            result.setText(String.valueOf(Double.valueOf(x.getText())+Double.valueOf(y.getText())));
        }
        else if("-".equals(ff.getText())){
            result.setText(String.valueOf(Double.valueOf(x.getText())-Double.valueOf(y.getText())));
        }
        else if("*".equals(ff.getText())){
            result.setText(String.valueOf(Double.valueOf(x.getText())*Double.valueOf(y.getText())));
        }
        else if("/".equals(ff.getText())){
            result.setText(String.valueOf(Double.valueOf(x.getText())/Double.valueOf(y.getText())));
        }
        else if("%".equals(ff.getText())){
            result.setText(String.valueOf(Double.valueOf(x.getText())%Double.valueOf(y.getText())));
        }
        else{
            //符号输入错误提示
            notice.setText("请在第二个输入框内输入正确的符号！ 目前支持+ - * / %");
            result.setText("");
        }
    }
    //清除按钮方法
    public void clear(){
        x.setText("");
        ff.setText("");
        y.setText("");
        result.setText("");
        notice.setText("");
    }
}