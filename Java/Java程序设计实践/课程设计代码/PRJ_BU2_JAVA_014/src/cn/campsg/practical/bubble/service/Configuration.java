package cn.campsg.practical.bubble.service;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

import cn.campsg.practical.bubble.entity.Score;

public class Configuration {
	public final String SCNF = "score.conf";
	Score sco = null;
	
	public Score getSco() {
		return sco;
	}

	public void setSco(Score sco) {
		this.sco = sco;
	}
	//powered by Jingyu Zhang
	public Configuration(){
		try {
		BufferedReader bufrea = new BufferedReader(new InputStreamReader(getClass().getClassLoader().getResourceAsStream("SCNF")));
		Score score = new Score();
		score.setLevelScore(Integer.parseInt(bufrea.readLine()));
		score.setStep(Integer.parseInt(bufrea.readLine()));
		score.setIncrement(Integer.parseInt(bufrea.readLine()));
		score.setLength(Integer.parseInt(bufrea.readLine()));
        bufrea.close();
        }
		catch(FileNotFoundException e) {
            sco = null;
        }
		catch (IOException e) {
            sco = null;
        }
		//powered by Jingyu Zhang
    } 
}
