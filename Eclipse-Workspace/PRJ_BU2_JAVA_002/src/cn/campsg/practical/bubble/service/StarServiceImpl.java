package cn.campsg.practical.bubble.service;

import cn.campsg.practical.bubble.entity.StarList;
import cn.campsg.practical.bubble.entity.Position;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.Star.StarType;

/**
 * 
 * 泡泡糖业务计算服务类，用于为界面提供以下服务<br>
 * 1. 创建屏幕画布随机泡泡糖<br>
 * 2. 切关判定<br>
 * 3. 根据消除的泡泡计算得分<br>
 * 4. 计算剩余泡泡糖的得分奖励<br>
 * 
 * @author Frank.Chen
 * @version 2.5
 *
 */
public class StarServiceImpl implements StarService {

	/**
	 * 创建屏幕画布随机泡泡糖（10 * 10）
	 * 
	 * @return 泡泡糖列表-供画面显示
	 */
	@Override
	public StarList createStars()
	{
		Star star0 = new Star(new Position(0,0), Star.StarType.BLUE);
		Star star1 = new Star(new Position(1,1), Star.StarType.RED);
		Star star2 = new Star(new Position(2,2), Star.StarType.YELLOW);
		Star star3 = new Star(new Position(3,3), Star.StarType.GREEN);
		Star star4 = new Star(new Position(4,4), Star.StarType.PURPLE);
		StarList starList = new StarList();
		starList.add(star0);
		starList.add(star1);
		starList.add(star2);
		starList.add(star3);
		starList.add(star4);
		return starList;

		//powered by Jingyu Zhang

	}

	private int StarNum(String color) {
		if(color=="BLUE") {
			return 0;
		}
		else if(color=="GREEN") {
			return 1;
		}
		else if(color=="YELLOW") {
			return 2;
		}
		else if(color=="RED") {
			return 3;
		}
		else {return 4;}
	}

	public StarList getYMovedStars(StarList clearStars,
			StarList currentStarList) {
		return null;
	}

	/**
	 * 消除泡泡糖后，获取待移动泡泡糖列表(仅限水平列表的泡泡糖)<br>
	 * 该功能固定在垂直列表的泡泡糖之后运行
	 * 
	 * @param currentStarList
	 *            当前完整的界面泡泡糖列表（已经被消除的泡泡糖用null表示）
	 * 
	 * @return 待移动泡泡糖列表
	 */
	public StarList getXMovedStars(StarList currentStarList) {
		return null;
	}

	/**
	 * 判断是否还存在未消除的泡泡糖
	 * 
	 * @param currentStarList
	 *            当前完整的界面泡泡糖列表（已经被消除的泡泡糖用null表示）
	 * @return true:任然有未消除的泡泡糖,false:没有未消除的泡泡糖
	 * 
	 */
	@Override
	public boolean tobeEliminated(StarList currentStarList) {
		return false;
	}

	/**
	 * 获取无法消除泡泡糖列表
	 * 
	 * @param curretStars
	 *            当前完整的界面泡泡糖列表（已经被消除的泡泡糖用null表示）
	 * @return 无法消除泡泡糖列表
	 * */
	public StarList getAwardStarList(StarList curretStars) {
		return null;
	}

}
