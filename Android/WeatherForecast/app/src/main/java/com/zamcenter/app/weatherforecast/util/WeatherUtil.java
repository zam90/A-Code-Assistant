package com.zamcenter.app.weatherforecast.util;

public class WeatherUtil {

    //判断返回结果中的风是否为“无风向”，如果是，直接显示“无风向”，否则显示“xx风”
    public static boolean noWindDirection(String wind) {
        if (wind != null) {
            if ("无风向".equals(wind)) {
                return true;
            }
        }
        return false;
    }

}
