package cn.campsg.practical.bubble.service;

import javafx.scene.layout.AnchorPane;

public interface StarService {
	/**
	 * 在指定容器的某行某列画一个泡泡糖
	 * @param root 父容器
	 * @param row 所在行
	 * @param col 所在列
	 * @param type 泡泡糖类型(blue_star,green_star,yellow_star,purple_star,red_star)
	 */
	public void drawOneBubble(AnchorPane root, int row, int col, String type);
	
	/**
	 * 在指定容器里完成10*10泡泡糖阵列的初始化
	 * @param root 父容器
	 */
	public void drawBubbles(AnchorPane root);
	
}