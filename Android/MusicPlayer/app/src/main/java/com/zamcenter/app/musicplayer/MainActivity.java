package com.zamcenter.app.musicplayer;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;

import com.zamcenter.app.musicplayer.R;
import com.zamcenter.app.musicplayer.ui.MainContentFragment;
import com.zamcenter.app.musicplayer.ui.MainFragment;
import com.zamcenter.app.musicplayer.ui.MusicInfoFragment;
import com.zamcenter.app.musicplayer.ui.SongContentFragment;

import org.litepal.LitePal;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //初始化数据库
        LitePal.initialize(this);
        //隐藏最上方工具栏
        ActionBar actionBar = getSupportActionBar();
        if (actionBar != null) {
            actionBar.hide();
        }
        //将碎片和activity绑定
        initMainFragment(savedInstanceState);
        //避免点击editText时，软键盘遮挡输入框
        //getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_ADJUST_PAN);
    }

    private void initMainFragment(Bundle bundle) {
        if (bundle == null) {
            FragmentManager fragmentManager = getSupportFragmentManager();
            FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
            fragmentTransaction
                    .add(R.id.fragment_host, MainFragment.getInstance(), MainFragment.class.getName())
                    .add(R.id.fragment_host, MusicInfoFragment.getInstance(), MusicInfoFragment.class.getName())
                    .add(R.id.main_content, MainContentFragment.getInstance(), MainContentFragment.class.getName())
                    .hide(MusicInfoFragment.getInstance())
                    .commit();
        }
    }

    //初始化footer
    public void enterMusicInfoFragment() {
        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction
                .hide(MainFragment.getInstance())
                .show(MusicInfoFragment.getInstance())
                .addToBackStack(null)
                .commit();
    }

    //初始化歌单列表碎片
    public void enterSongContentFragment() {
        FragmentManager fragmentManager = getSupportFragmentManager();
        Fragment fragment = fragmentManager.findFragmentByTag(SongContentFragment.class.getName());
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction
                .hide(MainContentFragment.getInstance());
        if (fragment == null) {
            fragmentTransaction
                    .add(R.id.main_content, SongContentFragment.getInstance(), SongContentFragment.class.getName());
        } else {
            fragmentTransaction
                    .show(fragment);
        }
        fragmentTransaction
                .addToBackStack(null)
                .commit();
    }

    //设置返回键方法
    @Override
    public void onBackPressed() {
        FragmentManager fragmentManager = getSupportFragmentManager();
        if (fragmentManager.getBackStackEntryCount() > 0) {
            Log.d(TAG, "onBackPressed: " + fragmentManager.getBackStackEntryCount());
            fragmentManager.popBackStack();
        }
    }

}
