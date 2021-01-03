package com.zamcenter.app.musicplayer.ServiceImpl;

import android.app.Service;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.IBinder;
import android.os.SystemClock;


public class MusicDownloadService extends Service {
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        //接收从Activity发来的数据
        String url = intent.getStringExtra("url");
        // Toast.makeText(this,url,Toast.LENGTH_SHORT).show();
        //启动下载任务
        new DownLoadTask().execute(url);
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public IBinder onBind(Intent intent) {
        throw new UnsupportedOperationException("Not yet implemented");
    }


    private class DownLoadTask extends AsyncTask<String,Void,String>{

        @Override
        protected String doInBackground(String... params) {
            for(int i = 1; i <= 10; i++){
                Intent intent = new Intent();
                intent.setAction("http://m10.music.126.net/20201126234433/1bc67203a484dde3d43ee9ef56c178fb/ymusic/025b/525d/040c/51958d1f13e76f9787173fe94bdca8fc.mp3");
                intent.putExtra("progress",10*i);
                //发送广播
                sendBroadcast(intent);
            }
            return null;
        }
    }

}
