package com.zamcenter.app.helloworld;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class newCreateActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.newlayout);
        Log.d("HelloWorldActivity", "程序已启动！");
        Button button1 = (Button) findViewById(R.id.button1);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(newCreateActivity.this, "Toast测试成功！你点击了按钮", Toast.LENGTH_SHORT).show();
                Log.d("HelloWorldActivity","onClick:成功 ");
                Intent intent2 = new Intent(Intent.ACTION_VIEW);
                intent2.setData(Uri.parse("https://www.baidu.com"));
                startActivity(intent2);
                Log.d("HelloWorldActivity","onClick:activity start成功 ");
            }
        });
        Button button2 = (Button) findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View vi) {
                Toast.makeText(newCreateActivity.this, "新activity启动成功", Toast.LENGTH_SHORT).show();
                Intent intent = new Intent(newCreateActivity.this,MainActivity.class);
                startActivity(intent);
            }
        });
        Button button3 = (Button) findViewById(R.id.button3);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View vie) {
                Toast.makeText(newCreateActivity.this, "新activity启动成功", Toast.LENGTH_SHORT).show();
                Intent intent3 = new Intent("com.zamcenter.app.helloworld.ACTION_START");
                startActivity(intent3);
            }
        });
    }
}