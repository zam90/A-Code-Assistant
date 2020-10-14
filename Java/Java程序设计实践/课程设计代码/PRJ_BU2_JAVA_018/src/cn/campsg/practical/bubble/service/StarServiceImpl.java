package cn.campsg.practical.bubble.service;


import javafx.scene.control.Label;
import javafx.scene.layout.AnchorPane;

import java.util.List;

import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;

public class StarServiceImpl implements StarService {

	public void drawOneBubble(AnchorPane root, int row, int col, String type) {

		// ���������ǿؼ�
		Label starFrame = new Label();
		// ���������ǵĴ�С
		starFrame.setPrefHeight(48);
		starFrame.setPrefWidth(48);
		// ���������ǵ�λ��
		starFrame.setLayoutX(col * 48);// ��
		starFrame.setLayoutY(row * 48);// ��
		// ���������ǵ���ʽ
		// skin2.css���Ѷ���5����������ʽ
		starFrame.getStyleClass().add(type);
		
		//��������ǵ���¼� ��START��
		
		starFrame.setOnMouseClicked(new EventHandler<Event>() {
			@Override
			public void handle(Event event) {  
				//System.out.println("�㴥���˵���¼�");
				starFrame.setOnMouseClicked(new StartEventHandler());
				//powered by Jingyu Zhang
			}  
			});
			
		//��������ǵ���¼� ��END��
		// ��������ǲ��ֶ���
		AnchorPane anchorPane = (AnchorPane) root.lookup("#game_pane");
		// �������ǿؼ����븸������
		anchorPane.getChildren().add(starFrame);
	}

	@Override
	public void drawBubbles(AnchorPane root) {
		// ���������ǿؼ�
		// ��������ʽ����
		String[] styles = { "purple_star", "red_star", "green_star", "yellow_star", "blue_star" };
		// ����10*10������������
		for (int row = 0; row < 10; row++) {
			for (int col = 0; col < 10; col++) {
				// ������������ʽ
				int typeIndex = (int) (Math.random() * 5);
				String type = styles[typeIndex];
				this.drawOneBubble(root, row, col, type);
			}
		}
	}
	
	class StartEventHandler implements EventHandler<MouseEvent> {
		@Override
		
		public void handle(MouseEvent event) {
		Label label1 = (Label) event.getTarget();
		int c = (int) (label1.getLayoutX()/48);
		int r = (int) (label1.getLayoutY()/48);
		List<String> styles=label1.getStyleClass();
		String style=styles.get(styles.size()-1);
		System.out.println("�����˵�"+r+"��,��"+c+"�е�������;����Ϊ:"+style);
		//powered by Jingyu Zhang
		}
		}


}
