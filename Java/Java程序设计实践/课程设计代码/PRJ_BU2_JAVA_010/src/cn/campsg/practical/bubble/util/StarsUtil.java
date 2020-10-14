package cn.campsg.practical.bubble.util;

import cn.campsg.practical.bubble.MainForm;
import cn.campsg.practical.bubble.entity.MovedStar;
import cn.campsg.practical.bubble.entity.Position;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.StarList;
import cn.campsg.practical.bubble.entity.Star.StarType;

/**
 * ������/���ƶ�������ʵ���๤���࣬�ṩ���¹��ܣ�<br>
 * <ul>
 * <li>1. ����ָ���б��е�������-����������������ͬ������������ð�������㷨����</li>
 * <li>2. ��ָ���б��е������ǰ��з��顣</li>
 * <li>3. ��¡һ�������Ƕ���</li>
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
	 * ����ָ���б��е�������<br>
	 * ������򣺰������������������ͬ������������<br>
	 * �����㷨��ð������
	 * 
	 * @param starList
	 *            ��������������б�
	 */
	/************ PRJ-BU2-JAVA-010 Task2 ��2/3 start��***************/
	
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

	
	/************ PRJ-BU2-JAVA-010 Task2 ��2/3 end��*****************/
	
	/**
	 * �����������������б��е�λ��
	 * 
	 * @param preStar
	 *            ��N��������
	 * @param nextStar
	 *            ��N+1��������
	 */
	/************ PRJ-BU2-JAVA-010 Task1 ��1/3 start��***************/
	
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
	   System.out.println("����ǰ��starList��"+sList.toString());
	   Sort(sList);
	   System.out.println("�����starList��"+sList.toString());
	   //powered by Jingyu Zhang
	}

	/************ PRJ-BU2-JAVA-010 Task1 ��1/3 end��*****************/

	/**
	 * ��¡һ���µ������ǡ�
	 * 
	 * @param star
	 *            ����¡��������
	 * @return �µ������ǣ������ڴ��ַ�������ǣ���
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
