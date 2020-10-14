package cn.campsg.practical.bubble.service;

import javafx.scene.layout.AnchorPane;

public interface StarService {
	/**
	 * ��ָ��������ĳ��ĳ�л�һ��������
	 * @param root ������
	 * @param row ������
	 * @param col ������
	 * @param type ����������(blue_star,green_star,yellow_star,purple_star,red_star)
	 */
	public void drawOneBubble(AnchorPane root, int row, int col, String type);
	
	/**
	 * ��ָ�����������10*10���������еĳ�ʼ��
	 * @param root ������
	 */
	public void drawBubbles(AnchorPane root);
	
}