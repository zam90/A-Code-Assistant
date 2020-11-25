package com.zamcenter.app.weatherforecast.bean;

import java.util.List;

/**
 * 预报天气信息数据
 */
public class Forecasts {
    private String city;//城市名
    private String adcode;//区域编码
    private String province;//省份名
    private String reporttime;//数据发布的时间
    private List<Casts> casts;//预报数据list结构，元素cast,按顺序为当天、第二天、第三天、第四天的预报数据

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getAdcode() {
        return adcode;
    }

    public void setAdcode(String adcode) {
        this.adcode = adcode;
    }

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }

    public String getReporttime() {
        return reporttime;
    }

    public void setReporttime(String reporttime) {
        this.reporttime = reporttime;
    }

    public List<Casts> getCasts() {
        return casts;
    }

    public void setCasts(List<Casts> casts) {
        this.casts = casts;
    }
}
