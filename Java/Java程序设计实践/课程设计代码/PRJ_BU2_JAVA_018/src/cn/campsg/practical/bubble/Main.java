package cn.campsg.practical.bubble;

import cn.campsg.practical.bubble.service.StarService;
import cn.campsg.practical.bubble.service.StarServiceImpl;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) {
		try {
			AnchorPane root = FXMLLoader.load(getClass().getResource("/res/layout/main_layout.fxml"));
			// 将主布局加入到视图场景中
			Scene scene = new Scene(root);
			// 设置场景
			primaryStage.setScene(scene);
			primaryStage.setTitle("消灭泡泡糖-Popstar3");
			primaryStage.setResizable(false);

			// 设置泡泡糖
			AnchorPane gamePane = (AnchorPane) root.lookup("#game_pane");
			StarService service = new StarServiceImpl();
//			service.drawOneBubble(gamePane, 1, 2, "yellow_star");
			service.drawBubbles(gamePane);
			
			primaryStage.show();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		launch(args);
	}
	
}
