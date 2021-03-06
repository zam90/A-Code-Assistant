package cn.campsg.practical.bubble.service;

import javafx.scene.control.Label;
import javafx.scene.layout.AnchorPane;

public class StarServiceImpl implements StarService {

	public void drawOneBubble(AnchorPane root, int row, int col, String type) {
		Label starFrame = new Label();
		starFrame.setLayoutX(col * 48);
		starFrame.setLayoutY(row * 48);
		starFrame.getStyleClass().add(type);
		starFrame.setPrefHeight(48);
		starFrame.setPrefWidth(48);
		AnchorPane anchorPane = (AnchorPane) root.lookup("#game_pane");
		anchorPane.getChildren().add(starFrame);
		//powered by Jingyu Zhang
	}

	@Override
	public void drawBubbles(AnchorPane root) {
		// 创建泡泡糖控件
		// 泡泡糖样式集合
		String[] styles = { "purple_star", "red_star", "green_star", "yellow_star", "blue_star" };
		// 遍历10*10的泡泡糖阵列
		for (int row = 0; row < 10; row++) {
			for (int col = 0; col < 10; col++) {
				// 设置泡泡糖样式
				int typeIndex = (int) (Math.random() * 5);
				String type = styles[typeIndex];
				this.drawOneBubble(root, row, col, type);
			}
		}
	}

}
