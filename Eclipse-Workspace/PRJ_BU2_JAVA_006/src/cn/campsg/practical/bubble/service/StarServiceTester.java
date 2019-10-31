package cn.campsg.practical.bubble.service;

import cn.campsg.practical.bubble.MainForm;
import cn.campsg.practical.bubble.entity.Position;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.Star.StarType;
import cn.campsg.practical.bubble.entity.StarList;

public class StarServiceTester implements StarService{

	@Override
	public StarList createStars() {
		StarList save = new StarList();
		Star star1 = new Star(new Position(0,0),StarType.BLUE);
		Star star2 = new Star(new Position(0,1),StarType.GREEN);
		Star star3 = new Star(new Position(1,0),StarType.PURPLE);
		Star star4 = new Star(new Position(1,1),StarType.YELLOW);
		Star star5 = new Star(new Position(0,2),StarType.RED);
		save.add(star1);
		save.add(star2);
		save.add(star3);
		save.add(star4);
		save.add(star5);
		return save;
		
	}

	@Override
	public StarList tobeClearedStars(Star base, StarList sList) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public StarList getYMovedStars(StarList clearStars, StarList currentStarList) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public StarList getXMovedStars(StarList currentStarList) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean tobeEliminated(StarList currentStarList) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public StarList getAwardStarList(StarList currentStarList) {
		// TODO Auto-generated method stub
		return null;
	}
	

	public static void main(String[] args) {
		StarServiceTester sst = new  StarServiceTester();
        sst.createStars();
        System.out.println(sst.createStars());
	}
    //powered by Jingyu Zhang
}
