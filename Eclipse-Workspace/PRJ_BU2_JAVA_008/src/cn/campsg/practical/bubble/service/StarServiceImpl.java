package cn.campsg.practical.bubble.service;

import cn.campsg.practical.bubble.common.StarFormUtils;
import cn.campsg.practical.bubble.entity.Position;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.Star.StarType;
import cn.campsg.practical.bubble.exception.ServiceInitException;
import cn.campsg.practical.bubble.entity.StarList;
import cn.campsg.practical.bubble.util.StarsUtil;

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
	public StarList createBubbleMatrix() {

		StarList stars = new StarList();

		for (int row = 0; row < StarService.MAX_ROW_SIZE; row++) {

			for (int col = 0; col < StarService.MAX_COLUMN_SIZE; col++) {

				Star star = new Star();
				// �����������ڻ����ϵ�λ��
				star.setPosition(new Position(row, col));
				// ���������������
				int typeIndex = (int) (Math.random() * StarService.STAR_TYPES);
				star.setType(StarType.valueOf(typeIndex));
				// �����б�
				stars.add(star);
			}
		}

		return stars;

	}


	/**
	 * �Ը��������ǣ��û�����ģ�Ϊ�����������ҡ�����·������Ѱ����ͬ���͵�������
	 * 
	 * @param base
	 *            ���������ǣ��û�����ģ�
	 * @param sList
	 *            ԭʼ�������б����������е������ǣ�
	 * @param clearStars
	 *            ��������������б�
	 */
	private void lookupByPath(Star base, StarList sList, StarList clearStars) {
		// ��ȡ��ǰ����������ǵ��к���
		int row = base.getPosition().getRow();
		int col = base.getPosition().getColumn();
		StarType type = base.getType();

		Star star = null;

		// �����·�������ж�
		if (col - 1 >= 0) {
			// ���������߽������£���ȡ����������ǵ����������
			star = (Star) sList.findout(row, (col - 1));
			// �Ѿ����������������ڽ��������е��������б��л���null��ʾ
			// �Ѿ���������������������б����Ѿ����ڵ������������ظ��жϣ�����������ѭ����
			if (star != null && !clearStars.isexisted(star)) {
				if (star.getType() == type) {
					// ��������������ж����ݱ���һ��ʱ�������б�
					clearStars.add(StarsUtil.copy(star));
					// ���������·�������жϡ�
					lookupByPath(star, sList, clearStars);
				}
			}
		}

		// ���Ҳ�·�������ж�
		if (col + 1 < StarService.MAX_COLUMN_SIZE) {
			// �������Ҳ�߽������£���ȡ����������ǵ��Ҳ�������
			star = (Star) sList.findout(row, (col + 1));
			// �Ѿ����������������ڽ��������е��������б��л���null��ʾ
			// �Ѿ���������������������б����Ѿ����ڵ������������ظ��жϣ�����������ѭ����
			if (star != null && !clearStars.isexisted(star)) {
				if (star.getType() == type) {
					// ��������������ж����ݱ���һ��ʱ�������б�
					clearStars.add(StarsUtil.copy(star));
					// �������Ҳ�·�������жϡ�
					lookupByPath(star, sList, clearStars);
				}
			}
		}

		// ���Ϸ�·�������ж�
		if (row - 1 >= 0) {
			// �������Ϸ��߽������£���ȡ����������ǵ��Ϸ�������
			star = (Star) sList.findout((row - 1), col);
			// �Ѿ����������������ڽ��������е��������б��л���null��ʾ
			// �Ѿ���������������������б����Ѿ����ڵ������������ظ��жϣ�����������ѭ����
			if (star != null && !clearStars.isexisted(star)) {
				if (star.getType() == type) {
					// ��������������ж����ݱ���һ��ʱ�������б�
					clearStars.add(StarsUtil.copy(star));
					// �������Ϸ�·�������жϡ�
					lookupByPath(star, sList, clearStars);
				}
			}
		}

		// ���·�·�������ж�
		if (row + 1 < MAX_ROW_SIZE) {
			// �������·��߽������£���ȡ����������ǵ��·�������
			star = (Star) sList.findout((row + 1), col);
			// �Ѿ����������������ڽ��������е��������б��л���null��ʾ
			// �Ѿ���������������������б����Ѿ����ڵ������������ظ��жϣ�����������ѭ����
			if (star != null && !clearStars.isexisted(star)) {
				if (star.getType() == type) {
					// ��������������ж����ݱ���һ��ʱ�������б�
					clearStars.add(StarsUtil.copy(star));
					// �������·�·�������жϡ�
					lookupByPath(star, sList, clearStars);
				}
			}
		}

		// �����ĸ��ж϶����������ʾ���ܶ�û���������ˣ���ô�����ݹ鷽����
	}

	/**
	 * �û���������ǣ���ȡ���������������������б�
	 * 
	 * @param base
	 *            ���û������������
	 * @param sList
	 *            ��ǰ���������ݵ��б�
	 * @return ��Ҫ�����������
	 */
	@Override
	public StarList tobeClearedStars(Star base, StarList mCurrent){

		// ���ڱ���������������
		StarList clearStars = new StarList();

		// �ӵ�ǰ�б��л�ȡָ������ָ���е������ǣ�base�����ǣ�
		// ������������Ϊ������󱣴����б���
		// ע�⣺���д�����������Ƕ�Ӧ����ԭʼ�Ľ����������б���
		clearStars.add(base);

		// �Ա����������Ϊ���������ҡ����²�ͬ·��Ѱ����ͬ���ͣ���ɫ���Ĵ����������
		lookupByPath(base, mCurrent, clearStars);

		if (clearStars.size() == 1) {
			clearStars.clear();
			/******************** PRJ-BU2-JAVA-008 Task3 ********************/
			try {
				

			} catch (ServiceInitException e) {
				e.printStackTrace();

				//powered by Jingyu Zhang
			}
			/******************************************************/
		}

		return clearStars;
	}

	/**
	 * ���������Ǻ󣬻�ȡ���ƶ��������б�(���޴�ֱ�б��������)<br>
	 * �ù��̶ܹ������������������֮������
	 * 
	 * @param clearStars
	 *            ��������������б��Դ���Ϊ�ж����ƶ������ǵĻ�����
	 * @param currentStarList
	 *            ��ǰ�����Ľ����������б��Ѿ�����������������null��ʾ��
	 * @return ���ƶ��������б�
	 */
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
