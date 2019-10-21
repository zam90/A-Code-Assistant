package cn.campsg.practical.bubble.service;

import cn.campsg.practical.bubble.entity.StarList;
import cn.campsg.practical.bubble.entity.Position;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.Star.StarType;

/**
 * 
 * ������ҵ���������࣬����Ϊ�����ṩ���·���<br>
 * 1. ������Ļ�������������<br>
 * 2. �й��ж�<br>
 * 3. �������������ݼ���÷�<br>
 * 4. ����ʣ�������ǵĵ÷ֽ���<br>
 * 
 * @author Frank.Chen
 * @version 2.5
 *
 */
public class StarServiceImpl implements StarService {

	/**
	 * ������Ļ������������ǣ�10 * 10��
	 * 
	 * @return �������б�-��������ʾ
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
	 * ���������Ǻ󣬻�ȡ���ƶ��������б�(����ˮƽ�б��������)<br>
	 * �ù��̶ܹ��ڴ�ֱ�б��������֮������
	 * 
	 * @param currentStarList
	 *            ��ǰ�����Ľ����������б��Ѿ�����������������null��ʾ��
	 * 
	 * @return ���ƶ��������б�
	 */
	public StarList getXMovedStars(StarList currentStarList) {
		return null;
	}

	/**
	 * �ж��Ƿ񻹴���δ������������
	 * 
	 * @param currentStarList
	 *            ��ǰ�����Ľ����������б��Ѿ�����������������null��ʾ��
	 * @return true:��Ȼ��δ������������,false:û��δ������������
	 * 
	 */
	@Override
	public boolean tobeEliminated(StarList currentStarList) {
		return false;
	}

	/**
	 * ��ȡ�޷������������б�
	 * 
	 * @param curretStars
	 *            ��ǰ�����Ľ����������б��Ѿ�����������������null��ʾ��
	 * @return �޷������������б�
	 * */
	public StarList getAwardStarList(StarList curretStars) {
		return null;
	}

}
