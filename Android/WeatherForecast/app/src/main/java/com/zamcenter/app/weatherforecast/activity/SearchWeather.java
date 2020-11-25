package com.zamcenter.app.weatherforecast.activity;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import com.zamcenter.app.weatherforecast.R;
import com.zamcenter.app.weatherforecast.bean.Casts;
import com.zamcenter.app.weatherforecast.bean.Weather;
import com.zamcenter.app.weatherforecast.util.WeatherUtil;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class SearchWeather extends AppCompatActivity {
    private EditText edit_city;
    private Button search_btn;
    private ListView listView;
    private Button guanzhu_btn;
    private TextView city_text;
    private TextView weather_text;
    private TextView tem_text;

    //请求的API，详细参考https://lbs.amap.com/api/webservice/guide/api/weatherinfo/
    private String url = "https://restapi.amap.com/v3/weather/weatherInfo?key=6d29a580912e6f4b7ffb3b057d1f9ab2&extensions=all&out=json";
    //使用OkHttpClient进行网络请求
    private OkHttpClient httpClient = new OkHttpClient();
    //使用Gson解析json字符串
    private Gson gson = new Gson();

    @SuppressLint("HandlerLeak")
    private Handler handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    //Toast.makeText(SearchWeather.this, (String) msg.obj, Toast.LENGTH_SHORT).show();
                    Toast.makeText(SearchWeather.this, "城市输入有误！", Toast.LENGTH_SHORT).show();
                    listView.setAdapter(null);
                    tem_text.setText("");
                    weather_text.setText("");
                    break;
                case 1:
                    //Toast.makeText(SearchWeather.this, (String) msg.obj, Toast.LENGTH_SHORT).show();
                    Toast.makeText(SearchWeather.this, "服务器无响应！", Toast.LENGTH_SHORT).show();
                    tem_text.setText("");
                    weather_text.setText("");
                    break;
                case 2:
                    //Toast.makeText(SearchWeather.this, "该城市adcode为" + (String) msg.obj, Toast.LENGTH_SHORT).show();
                    tem_text.setText("");
                    weather_text.setText("");
                    break;
                case 3:
                    List<Map<String, String>> list = (List<Map<String, String>>) msg.obj;
                    //创建Adapter
                    final SimpleAdapter simpleAdapter = new SimpleAdapter(SearchWeather.this
                            , list, R.layout.weather_listview_item
                            , new String[]{"date", "day_weather", "day_temp", "day_wind", "day_power"
                            , "night_weather", "night_temp", "night_wind", "night_power"}
                            , new int[]{R.id.date, R.id.day_weather, R.id.day_temp, R.id.day_wind, R.id.day_power
                            , R.id.night_weather, R.id.night_temp, R.id.night_wind, R.id.night_power});
                    //绑定Adapter
                    listView.setAdapter(simpleAdapter);
                    tem_text.setText("");
                    weather_text.setText("");
                    Toast.makeText(SearchWeather.this, "查询成功", Toast.LENGTH_SHORT).show();
                default:
                    break;
            }
        }
    };

    @SuppressLint("HandlerLeak")
    private Handler handlergz = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    //Toast.makeText(SearchWeather.this, (String) msg.obj, Toast.LENGTH_SHORT).show();
                    Toast.makeText(SearchWeather.this, "城市输入有误！", Toast.LENGTH_SHORT).show();
                    listView.setAdapter(null);
                    break;
                case 1:
                    //Toast.makeText(SearchWeather.this, (String) msg.obj, Toast.LENGTH_SHORT).show();
                    Toast.makeText(SearchWeather.this, "服务器无响应！", Toast.LENGTH_SHORT).show();
                    break;
                case 2:
                    //Toast.makeText(SearchWeather.this, "该城市adcode为" + (String) msg.obj, Toast.LENGTH_SHORT).show();
                    break;
                case 3:
                    List<Map<String, String>> list = (List<Map<String, String>>) msg.obj;
                    //创建Adapter
                    final SimpleAdapter simpleAdapter = new SimpleAdapter(SearchWeather.this
                            , list, R.layout.weather_listview_item
                            , new String[]{"date", "day_weather", "day_temp", "day_wind", "day_power"
                            , "night_weather", "night_temp", "night_wind", "night_power"}
                            , new int[]{R.id.date, R.id.day_weather, R.id.day_temp, R.id.day_wind, R.id.day_power
                            , R.id.night_weather, R.id.night_temp, R.id.night_wind, R.id.night_power});
                    //绑定Adapter
                    listView.setAdapter(simpleAdapter);
                    //更新界面上展示的天气信息
                    SharedPreferences sharedPreferences= getSharedPreferences("cityweather", Context .MODE_PRIVATE);
                    String nowcity=sharedPreferences.getString("nowcity","");
                    String tem=sharedPreferences.getString("tem","");
                    String weather=sharedPreferences.getString("weather","");
                    SharedPreferences.Editor editor = sharedPreferences.edit();
                    editor.putString("savecity", nowcity);
                    editor.commit();
                    String savecity=sharedPreferences.getString("savecity","");
                    city_text.setText(savecity);
                    tem_text.setText(tem);
                    weather_text.setText(weather);
                default:
                    break;
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.search_weather);
        //初始化
        init();
        SharedPreferences sharedPreferences= getSharedPreferences("cityweather", Context .MODE_PRIVATE);
        String savecity=sharedPreferences.getString("savecity","");
        String tem=sharedPreferences.getString("tem","");
        String weather=sharedPreferences.getString("weather","");
        if(!savecity.equals("")){
            city_text.setText(savecity);
            weather_text.setText(weather);
            tem_text.setText(tem);
            //getAdcode(city);
        }
    }

    private void init() {
        edit_city = findViewById(R.id.edit_city);
        search_btn = findViewById(R.id.search_w_btn);
        guanzhu_btn = findViewById(R.id.guanzhu_btn);
        city_text = findViewById(R.id.city);
        weather_text = findViewById(R.id.weather);
        tem_text = findViewById(R.id.tem);
        search_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String address = edit_city.getText().toString();
                city_text = (TextView) findViewById(R.id.city);
                city_text.setText(address);
                tem_text.setText("");
                weather_text.setText("");
                //调用方法获取该城市的城市编码
                getAdcode(address);
            }
        });
        guanzhu_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //调用方法储存SharePerfermance
                saveGuanZhu();
            }
        });
        listView = findViewById(R.id.search_weather);
    }

    /**
     * 利用SharedPreferences保存关注信息
     * 先存入SharedPreferences然后Toast提示
     */
    private void saveGuanZhu(){
        //获取输入
        String savecityin = edit_city.getText().toString();
        //获取sharedPreferences
        SharedPreferences sharedPreferences= getSharedPreferences("cityweather", Context .MODE_PRIVATE);
        String nowcity=sharedPreferences.getString("nowcity","");
        String savecity=sharedPreferences.getString("savecity","");
        String tem=sharedPreferences.getString("tem","");
        String weather=sharedPreferences.getString("weather","");
        //输入框为空 取消关注
        if(savecityin.equals("")){
            SharedPreferences.Editor editor = sharedPreferences.edit();
            editor.putString("nowcity", "");
            editor.putString("savecity", "");
            editor.putString("tem", "");
            editor.putString("weather", "");
            editor.commit();
            Toast.makeText(SearchWeather.this, "取消关注成功！" , Toast.LENGTH_SHORT).show();
            //清空界面
            listView.setAdapter(null);
            city_text.setText("");
            tem_text.setText("");
            weather_text.setText("");
            //存日志
            Log.i("SearchWeather.java", "城市信息已取消关注" );
        }
        //输入城市名和已关注的城市名相同 则更新关注
        else if(savecityin.equals(savecity)){
            SharedPreferences.Editor editor = sharedPreferences.edit();
            editor.putString("nowcity", savecityin);
            getAdcodegz(savecityin);
            Toast.makeText(SearchWeather.this, "更新成功！" , Toast.LENGTH_SHORT).show();
        }
        //默认添加关注
        else{
            city_text.setText("");
            tem_text.setText("");
            weather_text.setText("");
            SharedPreferences.Editor editor = sharedPreferences.edit();
            editor.putString("nowcity", savecityin);
            editor.commit();
            getAdcodegz(savecityin);
            //存日志
            Log.i("SearchWeather.java", "城市信息已添加关注" );
            //Toast提醒
            Toast.makeText(SearchWeather.this, "关注成功！" , Toast.LENGTH_SHORT).show();
            //Toast.makeText(SearchWeather.this, "查询成功", Toast.LENGTH_SHORT).show();
        }
    }

    //查询按钮的实现
    /**
     * 高德开发平台请求天气查询API中区域编码adcode是必须项，使用高德地理编码服务获取区域编码
     * address:结构化地址信息，规则遵循：国家、省份、城市、区县、城镇、乡村、街道、门牌号码、屋邨、大厦
     */
    private void getAdcode(final String city) {
        String url = "https://restapi.amap.com/v3/geocode/geo?key=6d29a580912e6f4b7ffb3b057d1f9ab2&address=" + city;

        final Request request = new Request.Builder().url(url).get().build();
        new Thread(new Runnable() {
            @Override
            public void run() {
                Response response = null;
                try {
                    response = httpClient.newCall(request).execute();
                    //请求成功
                    if (response.isSuccessful()) {
                        String result = response.body().string();

                        Log.i("result", result);

                        //转JsonObject
                        JsonObject object = new JsonParser().parse(result).getAsJsonObject();
                        //转JsonArray
                        JsonArray array = object.get("geocodes").getAsJsonArray();
                        JsonObject info = array.get(0).getAsJsonObject();

                        //获取adcode
                        String adcode = info.get("adcode").getAsString();
                        Log.i("测试获取adcode", adcode);

                        //请求天气查询
                        getWeather(adcode,city);

                        Message message = Message.obtain();
                        message.what = 2;
                        message.obj = adcode;
                        handler.sendMessage(message);
                    }
                } catch (Exception e) {
                    Log.i("SearchMainActivity.java", "服务器异常:" + e.toString());

                    Message message = Message.obtain();
                    message.what = 0;
                    message.obj = "服务器异常";
                    handler.sendMessage(message);
                    e.printStackTrace();
                }
            }
        }).start();
    }

    /**
     * 查询天气
     */
    private void getWeather(String adcode, String city) {
        String newUrl = url + "&&city=" + adcode;
        final Request request = new Request.Builder().url(newUrl).get().build();
        new Thread(new Runnable() {
            @Override
            public void run() {
                Response response = null;
                try {
                    response = httpClient.newCall(request).execute();
                    //请求成功
                    if (response.isSuccessful()) {
                        String result = response.body().string();

                        Log.i("服务器返回的结果:", result);
                        //存储解析json字符串得到的天气信息
                        List<Map<String, String>> weatherList = new ArrayList<>();

                        //使用Gson解析
                        Weather weather = gson.fromJson(result, Weather.class);
                        //获取今天天气信息
                        Casts today = weather.getForecasts().get(0).getCasts().get(0);

                        //添加Map数据到List
                        Map<String, String> map1 = new HashMap<>();
                        map1.put("date", "今天");
                        map1.put("day_weather", today.getDayweather());
                        map1.put("day_temp", today.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(today.getDaywind())) {
                            map1.put("day_wind", today.getDaywind());
                        } else {
                            map1.put("day_wind", today.getDaywind() + "风");
                        }
                        map1.put("day_power", today.getDaypower() + "级");
                        map1.put("night_weather", today.getNightweather());
                        map1.put("night_temp", today.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(today.getNightwind())) {
                            map1.put("night_wind", today.getNightwind());
                        } else {
                            map1.put("night_wind", today.getNightwind() + "风");
                        }
                        map1.put("night_power", today.getNightpower() + "级");
                        weatherList.add(map1);

                        //获取明天天气信息
                        Casts tomorrow = weather.getForecasts().get(0).getCasts().get(1);
                        //添加Map数据到List
                        Map<String, String> map2 = new HashMap<>();
                        map2.put("date", "明天");
                        map2.put("day_weather", tomorrow.getDayweather());
                        map2.put("day_temp", tomorrow.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(tomorrow.getDaywind())) {
                            map2.put("day_wind", tomorrow.getDaywind());
                        } else {
                            map2.put("day_wind", tomorrow.getDaywind() + "风");
                        }
                        map2.put("day_power", tomorrow.getDaypower() + "级");
                        map2.put("night_weather", tomorrow.getNightweather());
                        map2.put("night_temp", tomorrow.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(tomorrow.getNightwind())) {
                            map2.put("night_wind", tomorrow.getNightwind());
                        } else {
                            map2.put("night_wind", tomorrow.getNightwind() + "风");
                        }
                        map2.put("night_power", tomorrow.getNightpower() + "级");
                        weatherList.add(map2);

                        //获取后天天气信息
                        Casts afterTomorrow = weather.getForecasts().get(0).getCasts().get(2);
                        //添加Map数据到List
                        Map<String, String> map3 = new HashMap<>();
                        map3.put("date", "后天");
                        map3.put("day_weather", afterTomorrow.getDayweather());
                        map3.put("day_temp", afterTomorrow.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterTomorrow.getDaywind())) {
                            map3.put("day_wind", afterTomorrow.getDaywind());
                        } else {
                            map3.put("day_wind", afterTomorrow.getDaywind() + "风");
                        }
                        map3.put("day_power", afterTomorrow.getDaypower() + "级");
                        map3.put("night_weather", afterTomorrow.getNightweather());
                        map3.put("night_temp", afterTomorrow.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterTomorrow.getNightwind())) {
                            map3.put("night_wind", afterTomorrow.getNightwind());
                        } else {
                            map3.put("night_wind", afterTomorrow.getNightwind() + "风");
                        }
                        map3.put("night_power", afterTomorrow.getNightpower() + "级");
                        weatherList.add(map3);

                        //获取大后天天气信息
                        Casts afterAfterTomorrow = weather.getForecasts().get(0).getCasts().get(3);
                        //添加Map数据到List
                        Map<String, String> map4 = new HashMap<>();
                        map4.put("date", "大后天");
                        map4.put("day_weather", afterAfterTomorrow.getDayweather());
                        map4.put("day_temp", afterAfterTomorrow.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterAfterTomorrow.getDaywind())) {
                            map4.put("day_wind", afterAfterTomorrow.getDaywind());
                        } else {
                            map4.put("day_wind", afterAfterTomorrow.getDaywind() + "风");
                        }
                        map4.put("day_power", afterAfterTomorrow.getDaypower() + "级");
                        map4.put("night_weather", afterAfterTomorrow.getNightweather());
                        map4.put("night_temp", afterAfterTomorrow.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterAfterTomorrow.getNightwind())) {
                            map4.put("night_wind", afterAfterTomorrow.getNightwind());
                        } else {
                            map4.put("night_wind", afterAfterTomorrow.getNightwind() + "风");
                        }
                        map4.put("night_power", afterAfterTomorrow.getNightpower() + "级");
                        weatherList.add(map4);

                        //将服务器返回数据写入Handler
                        Message message = Message.obtain();
                        message.what = 3;
                        message.obj = weatherList;
                        handler.sendMessage(message);
                        //handler.obtainMessage(1, response).sendToTarget();
                    }
                } catch (Exception e) {
                    Log.i("SearchWeather.java", "服务器异常:" + e.toString());
                    Message message = Message.obtain();
                    message.what = 1;
                    message.obj = e.toString();
                    handler.sendMessage(message);
                    e.printStackTrace();
                }
            }
        }).start();
    }

    //关注按钮的实现
    /**
     * 高德开发平台请求天气查询API中区域编码adcode是必须项，使用高德地理编码服务获取区域编码
     * address:结构化地址信息，规则遵循：国家、省份、城市、区县、城镇、乡村、街道、门牌号码、屋邨、大厦
     */
    private void getAdcodegz(final String city) {
        String url = "https://restapi.amap.com/v3/geocode/geo?key=6d29a580912e6f4b7ffb3b057d1f9ab2&address=" + city;

        final Request request = new Request.Builder().url(url).get().build();
        new Thread(new Runnable() {
            @Override
            public void run() {
                Response response = null;
                try {
                    response = httpClient.newCall(request).execute();
                    //请求成功
                    if (response.isSuccessful()) {
                        String result = response.body().string();

                        Log.i("result", result);

                        //转JsonObject
                        JsonObject object = new JsonParser().parse(result).getAsJsonObject();
                        //转JsonArray
                        JsonArray array = object.get("geocodes").getAsJsonArray();
                        JsonObject info = array.get(0).getAsJsonObject();

                        //获取adcode
                        String adcode = info.get("adcode").getAsString();
                        Log.i("测试获取adcode", adcode);

                        //请求天气查询
                        getWeathergz(adcode,city);

                        Message message = Message.obtain();
                        message.what = 2;
                        message.obj = adcode;
                        handlergz.sendMessage(message);
                    }
                } catch (Exception e) {
                    Log.i("SearchMainActivity.java", "服务器异常:" + e.toString());

                    Message message = Message.obtain();
                    message.what = 0;
                    message.obj = "服务器异常";
                    handlergz.sendMessage(message);
                    e.printStackTrace();
                }
            }
        }).start();
    }

    /**
     * 查询天气
     */
    private void getWeathergz(String adcode, String city) {
        String newUrl = url + "&&city=" + adcode;
        final Request request = new Request.Builder().url(newUrl).get().build();
        new Thread(new Runnable() {
            @Override
            public void run() {
                Response response = null;
                try {
                    response = httpClient.newCall(request).execute();
                    //请求成功
                    if (response.isSuccessful()) {
                        String result = response.body().string();

                        Log.i("服务器返回的结果:", result);
                        //存储解析json字符串得到的天气信息
                        List<Map<String, String>> weatherList = new ArrayList<>();

                        //使用Gson解析
                        Weather weather = gson.fromJson(result, Weather.class);
                        //获取今天天气信息
                        Casts today = weather.getForecasts().get(0).getCasts().get(0);
                        //如果SharedPreferences不为空，则已关注的更新天气
                        SharedPreferences sharedPreferences= getSharedPreferences("cityweather", Context .MODE_PRIVATE);
                        String nowcity=sharedPreferences.getString("nowcity","");
                        if(!nowcity.equals("")){
                            SharedPreferences.Editor editor = sharedPreferences.edit();
                            editor.putString("weather", today.getDayweather());
                            editor.putString("tem", today.getDaytemp() + "℃");
                            editor.commit();
                        }
                        //添加Map数据到List
                        Map<String, String> map1 = new HashMap<>();
                        map1.put("date", "今天");
                        map1.put("day_weather", today.getDayweather());
                        map1.put("day_temp", today.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(today.getDaywind())) {
                            map1.put("day_wind", today.getDaywind());
                        } else {
                            map1.put("day_wind", today.getDaywind() + "风");
                        }
                        map1.put("day_power", today.getDaypower() + "级");
                        map1.put("night_weather", today.getNightweather());
                        map1.put("night_temp", today.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(today.getNightwind())) {
                            map1.put("night_wind", today.getNightwind());
                        } else {
                            map1.put("night_wind", today.getNightwind() + "风");
                        }
                        map1.put("night_power", today.getNightpower() + "级");
                        weatherList.add(map1);

                        //获取明天天气信息
                        Casts tomorrow = weather.getForecasts().get(0).getCasts().get(1);
                        //添加Map数据到List
                        Map<String, String> map2 = new HashMap<>();
                        map2.put("date", "明天");
                        map2.put("day_weather", tomorrow.getDayweather());
                        map2.put("day_temp", tomorrow.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(tomorrow.getDaywind())) {
                            map2.put("day_wind", tomorrow.getDaywind());
                        } else {
                            map2.put("day_wind", tomorrow.getDaywind() + "风");
                        }
                        map2.put("day_power", tomorrow.getDaypower() + "级");
                        map2.put("night_weather", tomorrow.getNightweather());
                        map2.put("night_temp", tomorrow.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(tomorrow.getNightwind())) {
                            map2.put("night_wind", tomorrow.getNightwind());
                        } else {
                            map2.put("night_wind", tomorrow.getNightwind() + "风");
                        }
                        map2.put("night_power", tomorrow.getNightpower() + "级");
                        weatherList.add(map2);

                        //获取后天天气信息
                        Casts afterTomorrow = weather.getForecasts().get(0).getCasts().get(2);
                        //添加Map数据到List
                        Map<String, String> map3 = new HashMap<>();
                        map3.put("date", "后天");
                        map3.put("day_weather", afterTomorrow.getDayweather());
                        map3.put("day_temp", afterTomorrow.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterTomorrow.getDaywind())) {
                            map3.put("day_wind", afterTomorrow.getDaywind());
                        } else {
                            map3.put("day_wind", afterTomorrow.getDaywind() + "风");
                        }
                        map3.put("day_power", afterTomorrow.getDaypower() + "级");
                        map3.put("night_weather", afterTomorrow.getNightweather());
                        map3.put("night_temp", afterTomorrow.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterTomorrow.getNightwind())) {
                            map3.put("night_wind", afterTomorrow.getNightwind());
                        } else {
                            map3.put("night_wind", afterTomorrow.getNightwind() + "风");
                        }
                        map3.put("night_power", afterTomorrow.getNightpower() + "级");
                        weatherList.add(map3);

                        //获取大后天天气信息
                        Casts afterAfterTomorrow = weather.getForecasts().get(0).getCasts().get(3);
                        //添加Map数据到List
                        Map<String, String> map4 = new HashMap<>();
                        map4.put("date", "大后天");
                        map4.put("day_weather", afterAfterTomorrow.getDayweather());
                        map4.put("day_temp", afterAfterTomorrow.getDaytemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterAfterTomorrow.getDaywind())) {
                            map4.put("day_wind", afterAfterTomorrow.getDaywind());
                        } else {
                            map4.put("day_wind", afterAfterTomorrow.getDaywind() + "风");
                        }
                        map4.put("day_power", afterAfterTomorrow.getDaypower() + "级");
                        map4.put("night_weather", afterAfterTomorrow.getNightweather());
                        map4.put("night_temp", afterAfterTomorrow.getNighttemp() + "℃");
                        if (WeatherUtil.noWindDirection(afterAfterTomorrow.getNightwind())) {
                            map4.put("night_wind", afterAfterTomorrow.getNightwind());
                        } else {
                            map4.put("night_wind", afterAfterTomorrow.getNightwind() + "风");
                        }
                        map4.put("night_power", afterAfterTomorrow.getNightpower() + "级");
                        weatherList.add(map4);

                        //将服务器返回数据写入Handler
                        Message message = Message.obtain();
                        message.what = 3;
                        message.obj = weatherList;
                        handlergz.sendMessage(message);
                        //handler.obtainMessage(1, response).sendToTarget();
                    }
                } catch (Exception e) {
                    Log.i("SearchWeather.java", "服务器异常:" + e.toString());
                    Message message = Message.obtain();
                    message.what = 1;
                    message.obj = e.toString();
                    handlergz.sendMessage(message);
                    e.printStackTrace();
                }
            }
        }).start();
    }
}