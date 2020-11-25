package com.zamcenter.app.musicplayer.ServiceImpl;

import com.zamcenter.app.musicplayer.Service.SongSheetService;
import com.zamcenter.app.musicplayer.entity.SongBean;
import com.zamcenter.app.musicplayer.entity.SongSheetBean;

import org.litepal.LitePal;

import java.util.List;

public class SongSheetServiceImpl implements SongSheetService {
    private static final String TAG = "SongSheetServiceImpl";
    @Override
    public boolean add(String name, String imgAddress) {
        SongSheetBean songSheet = new SongSheetBean(name, imgAddress);
        return songSheet.save();
    }

    @Override
    public int delete(SongSheetBean songSheet) {
        return songSheet.delete();
    }

    @Override
    public List<SongSheetBean> findAll() {
        return LitePal.findAll(SongSheetBean.class);
    }

    @Override
    public List<SongBean> findSongBeanBySongSheetId(int songSheetId) {
        return LitePal.where("songSheetId = ?", songSheetId+"").find(SongBean.class);
    }

    @Override
    public boolean addSongBean(SongBean songBean, SongSheetBean songSheetBean) {
        songBean.setSongSheetId(songSheetBean.getId());
        songBean.save();
        return songBean.getSongSheetId() == songSheetBean.getId();
    }
}
