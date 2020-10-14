package cn.campsg.practical.bubble.util;

import cn.campsg.practical.bubble.MainForm;
import cn.campsg.practical.bubble.entity.MovedStar;
import cn.campsg.practical.bubble.entity.Position;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.StarList;
import cn.campsg.practical.bubble.entity.Star.StarType;

/**
 * 泡泡糖/待移动泡泡糖实体类工具类，提供以下功能：<br>
 * <ul>
 * <li>1. 排序指定列表中的泡泡糖-按列升序排序，列相同按行升序排序（冒泡排序算法）。</li>
 * <li>2. 对指定列表中的泡泡糖按行分组。</li>
 * <li>3. 克隆一个泡泡糖对象</li>
 * </ul>
 * 
 * @see cn.campsg.practical.bubble.entity.Star
 * @see cn.campsg.practical.bubble.entity.MovedStar
 * 
 * 
 * @author Frank.Chen
 * @version 1.5
 *
 */
public class StarsUtil {
	
	/**
	 * 排序指定列表中的泡泡糖<br>
	 * 排序规则：按列升序排序，如果列相同按行升序排序<br>
	 * 排序算法：冒泡排序
	 * 
	 * @param starList
	 *            待排序的泡泡糖列表
	 */
	/************ PRJ-BU2-JAVA-010 Task2 【2/3 start】***************/
	
	public static void Sort(StarList starList) {

		for (int i = 0; i < starList.size() - 1; i++) {
			for (int j = 0; j < starList.size() - i - 1; j++) {
				Star nextStar = starList.get(j + 1);
				Star preStar = starList.get(j);
				if (preStar.getPosition().getColumn() > nextStar.getPosition().getColumn()) {
					Swap(preStar, nextStar);
					continue;
				}
				if (preStar.getPosition().getColumn() == nextStar.getPosition().getColumn()) {
					if (preStar.getPosition().getRow() > nextStar.getPosition().getRow()) {
						Swap(preStar, nextStar);
						//powered by Jingyu Zhang
					}
				}
			}
		}
	}

	
	/************ PRJ-BU2-JAVA-010 Task2 【2/3 end】*****************/
	
	/**
	 * 交换两个泡泡糖在列表中的位置
	 * 
	 * @param preStar
	 *            第N个泡泡糖
	 * @param nextStar
	 *            第N+1个泡泡糖
	 */
	/************ PRJ-BU2-JAVA-010 Task1 【1/3 start】***************/
	
	private static void Swap(Star preStar ,Star nextStar) {
		Star staring = new Star();
		staring.setPosition(new Position(preStar.getPosition().getRow(),preStar.getPosition().getColumn()));
		preStar.setPosition(new Position(nextStar.getPosition().getRow(),nextStar.getPosition().getColumn()));
		nextStar.setPosition(new Position(staring.getPosition().getRow(),staring.getPosition().getColumn()));
		staring.setType(preStar.getType());
		preStar.setType(nextStar.getType());
		nextStar.setType(staring.getType());
		//powered by Jingyu Zhang
	}
	
	public static void main(String[] args)
	{
	   StarList sList = new StarList();
	   sList.add(new Star(new Position(2,0), Star.StarType.BLUE));
	   sList.add(new Star(new Position(5,0), Star.StarType.GREEN));
	   sList.add(new Star(new Position(9,0), Star.StarType.PURPLE));
	   sList.add(new Star(new Position(3,0), Star.StarType.RED));
	   sList.add(new Star(new Position(8,0), Star.StarType.YELLOW));
	   System.out.println("排序前：starList："+sList.toString());
	   Sort(sList);
	   System.out.println("排序后：starList："+sList.toString());
	   //powered by Jingyu Zhang
	}

	/************ PRJ-BU2-JAVA-010 Task1 【1/3 end】*****************/

	/**
	 * 克隆一个新的泡泡糖。
	 * 
	 * @param star
	 *            待克隆的泡泡糖
	 * @return 新的泡泡糖（独立内存地址的泡泡糖）。
	 */
	public static Star copy(Star star) {

		Star ret = new Star();

		ret.setPosition(new Position(star.getPosition().getRow(), star
				.getPosition().getColumn()));
		ret.setType(star.getType());

		return ret;
	}

	public static MovedStar toMovedStar(Star star) {

		MovedStar ret = new MovedStar();

		ret.setPosition(new Position(star.getPosition().getRow(), star
				.getPosition().getColumn()));
		ret.setType(star.getType());

		return ret;
	}
}
