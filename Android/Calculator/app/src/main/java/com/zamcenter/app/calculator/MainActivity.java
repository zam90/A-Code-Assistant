package com.zamcenter.app.calculator;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    //    结果集
    private TextView editText;

    //数字1-9
    private Button btn1;
    private Button btn2;
    private Button btn3;
    private Button btn4;
    private Button btn5;
    private Button btn6;
    private Button btn7;
    private Button btn8;
    private Button btn9;
    private Button btn0;

    //运算符
    private  Button btnadd  ;// +
    private  Button btnsub;  // -
    private  Button btncheng;  // *
    private  Button btnchu;  // /
    private  Button btndot;  //小数点
    private  Button btnequ;  //=
    private  Button btnjc;  //阶乘
    private  Button btnfu;  //负数

    //清除
    private  Button btndel;

    boolean clear_flag;//清空标识

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //数字1-9
        View btn1 = findViewById(R.id.btn1);
        View btn2 = findViewById(R.id.btn2);
        View btn3= findViewById(R.id.btn3);
        View btn4 = findViewById(R.id.btn4);
        View btn5 = findViewById(R.id.btn5);
        View btn6 = findViewById(R.id.btn6);
        View btn7 = findViewById(R.id.btn7);
        View btn8 = findViewById(R.id.btn8);
        View btn9 = findViewById(R.id.btn9);
        View btn0 = findViewById(R.id.btn0);
        //运算符
        View btnadd = findViewById(R.id.btnadd);// +
        View btnsub = findViewById(R.id.btnsub);// -
        View btncheng = findViewById(R.id.btncheng);// *
        View btnchu = findViewById(R.id.btnchu); // /
        View btndot = findViewById(R.id.btndot);//小数点
        View btnequ = findViewById(R.id.btnequ);//=
        View btnjc = findViewById(R.id.btnjc);//阶乘
        View btndel = findViewById(R.id.btndel);//清空
        View btnfu = findViewById(R.id.btnfu);//负数


        editText = (TextView) findViewById(R.id.result);//结果集


        //添加点击事件
        btn0.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {

            }
        });
        btn0.setOnClickListener(listener);
        btn1.setOnClickListener(listener);
        btn2.setOnClickListener(listener);
        btn3.setOnClickListener(listener);
        btn4.setOnClickListener(listener);
        btn5.setOnClickListener(listener);
        btn6.setOnClickListener(listener);
        btn7.setOnClickListener(listener);
        btn8.setOnClickListener(listener);
        btn9.setOnClickListener(listener);

        btndot.setOnClickListener(listener);
        btndel.setOnClickListener(listener);

        btnadd.setOnClickListener(listener);
        btnsub.setOnClickListener(listener);
        btncheng.setOnClickListener(listener);
        btnchu.setOnClickListener(listener);
        btnequ.setOnClickListener(listener);
        btnjc.setOnClickListener(listener);
        btnfu.setOnClickListener(listener);
    }

    View.OnClickListener listener= new View.OnClickListener() {
        //读取每个按钮的点击的内容
        public void onClick(View view) {
            //获取文本内容
            String input = editText.getText().toString();
            switch (view.getId()) {
                case R.id.btn0:
                case R.id.btn1:
                case R.id.btn2:
                case R.id.btn3:
                case R.id.btn4:
                case R.id.btn5:
                case R.id.btn6:
                case R.id.btn7:
                case R.id.btn8:
                case R.id.btn9:
                case R.id.btndot:
                    if (clear_flag) {
                        clear_flag = false;
                        editText.setText("");//赋值为空
                    }
                    editText.setText(input + ((Button) view).getText());//结果集就为本身
                    break;

                case R.id.btnadd:
                case R.id.btnsub:
                case R.id.btncheng:
                case R.id.btnchu:
                    if (clear_flag) {
                        clear_flag = false;
                        input = "";
                        editText.setText("");
                    }
                    editText.setText(input + " " + ((Button) view).getText() + " ");
                    break;

                case R.id.btnjc:
                    if (clear_flag) {
                        clear_flag = false;
                        input = "";
                        editText.setText("");
                    }
                    editText.setText(input + " " + ((Button) view).getText() + " ");
                    getResult();//调用处理结果集的方法
                    break;

                case R.id.btnfu:
                    if (clear_flag) {
                        clear_flag = false;
                        input = "";
                        editText.setText("");
                    }
                    if(!input.contains("(") && !input.contains(")")){
                        String linshi = input;
                        String last = input.substring( 0 , linshi.length());
                        editText.setText("(-" +last +") ");
                    }
                    else if(input.contains("(") &&input.contains(")")){
                        String linshi = input;
                        String number = input.substring(linshi.length() -2 , linshi.length() - 1 );
                        editText.setText(input.substring(0 , linshi.length() -4) + number);
                    } else{
                        Toast ts = Toast.makeText(getBaseContext(),"表达式有误！",Toast.LENGTH_SHORT);
                        ts.show();
                    }
                    break;

                case R.id.btndel:
                    if (clear_flag) {
                        clear_flag = false;
                        input = "";
                        editText.setText("");
                    } else if (input != null || !input.equals("")) {//如果获取到的内容为空
                        if(input.length() - 1 < 0){
                            editText.setText(input.substring(0, 0));//结果集为空
                        } else{
                            editText.setText(input.substring(0, input.length() - 1));//结果集为空
                        }
                    }
                    break;

                case R.id.btnequ://运算结果  =
                    getResult();//调用处理结果集的方法
                    break;
            }
        }
    };

    //运算结果的方法
    private void getResult(){
        String exp = editText.getText().toString();//获取文本框的内容
        if(exp==null||exp.equals("")){
            return;
        }
        if(!exp.contains(" ")){
            return;
        }
        if(clear_flag){
            clear_flag = false;
            return;
        }
        clear_flag = true;
        double result = 0;

        //进行截取
        //运算符前的数字
        String s1 = exp.substring(0,exp.indexOf(" "));
        //运算符
        String op = exp.substring(exp.indexOf(" ")+1,exp.indexOf(" ")+2);
        //运算符后的数字
        String s2 = exp.substring(exp.indexOf(" ")+3);

        if(op.equals("!")){
            if(s1.contains(".")){
                Toast ts = Toast.makeText(getBaseContext(),"阶乘必须为整数！",Toast.LENGTH_SHORT);
                ts.show();
                result = 0; //则结果是0
            }
        }

        if(!s1.equals("")&&!s2.equals("")&&!op.equals("!")) {//如果包含小数点的运算
            //判断是否为纯符号、多符号
            boolean isNums1d = s2.matches("[0-9]+");
            boolean isNums2d = s2.matches("[0-9]+");
            if( isNums1d == false){
                Toast ts = Toast.makeText(getBaseContext(),"表达式有误！",Toast.LENGTH_SHORT);
                ts.show();
            }
            if(isNums2d == false){
                Toast ts = Toast.makeText(getBaseContext(),"暂不支持多符号运算！",Toast.LENGTH_SHORT);
                ts.show();
            }
            else {
                double d1 = Double.parseDouble(s1);//则数字都是double类型
                double d2 = Double.parseDouble(s2);
                if (op.equals("+")) {//如果是 +
                    result = d1 + d2;
                } else if (op.equals("-")) {
                    result = d1 - d2;
                } else if (op.equals("X")) {
                    result = d1 * d2;
                } else if (op.equals("/")) {
                    if (d2 == 0) { //如果被除数是0
                        Toast ts = Toast.makeText(getBaseContext(), "除数不能为0！", Toast.LENGTH_SHORT);
                        ts.show();
                        result = 0; //则结果是0
                    } else {//否则执行正常是除法运算
                        result = d1 / d2;
                    }
                }
            }

            if (!s1.contains(".") && !s2.contains(".") && !op.equals("/")&& !op.equals("!")) {//如果是整数类型
                //判断是否为纯符号、多符号
                boolean isNums1i = s2.matches("[0-9]+");
                boolean isNums2i = s2.matches("[0-9]+");
                if( isNums1i == false){
                    Toast ts = Toast.makeText(getBaseContext(),"表达式有误！",Toast.LENGTH_SHORT);
                    ts.show();
                }
                if(isNums2i == false){
                    Toast ts = Toast.makeText(getBaseContext(),"暂不支持多符号运算！",Toast.LENGTH_SHORT);
                    ts.show();
                }
                else{
                int r = (int) result; //都是整形
                editText.setText(r + "");
            } }else{
                editText.setText(result + "");
            }
        }else if(!s1.equals("") && s2.equals("")){//如果是只输入运算符前的数
            if(!op.equals("!")) {
                editText.setText(exp);//直接返回当前文本框的内容
                Toast ts = Toast.makeText(getBaseContext(), "表达式不完整！", Toast.LENGTH_SHORT);
                ts.show();
            }
            else if(s1.contains(".") && op.equals("!") ){
                Toast ts = Toast.makeText(getBaseContext(),"阶乘必须为整数！",Toast.LENGTH_SHORT);
                ts.show();
                result = 0; //则结果是0
                editText.setText(result + "");
            }
            //阶乘计算
            else{
                int d1=Integer.parseInt(s1);
                result=1;
                for(int i = d1; i>0 ; i--){
                    result = result * i;
                };
                editText.setText(result + "");
            }
        }else if(s1.equals("") && !s2.equals("")){//如果是只输入运算符后面的数
            //判断是否为纯符号、多符号
            boolean isNums1i = s2.matches("[0-9]+");
            boolean isNums2i = s2.matches("[0-9]+");
            if( isNums1i == false){
                Toast ts = Toast.makeText(getBaseContext(),"表达式有误！",Toast.LENGTH_SHORT);
                ts.show();
            }
            if(isNums2i == false){
                Toast ts = Toast.makeText(getBaseContext(),"暂不支持多符号运算！",Toast.LENGTH_SHORT);
                ts.show();
            }
            else{
            double d2 = Double.parseDouble(s2);

            //运算符前没有输入数字
            if (op.equals("+")) {
                result = 0 + d2;
            } else if (op.equals("-")) {
                result = 0 - d2;
            } else if (op.equals("*")) {
                result = 0;
            } else if (op.equals("/")) {
                result = 0;
            }

            if (!s1.contains(".") && !s2.contains(".")) {
                int r = (int) result;
                editText.setText(r + "");
            } else{
                editText.setText(result + "");
            }
        } }else {
            editText.setText("");
        }

    }

}