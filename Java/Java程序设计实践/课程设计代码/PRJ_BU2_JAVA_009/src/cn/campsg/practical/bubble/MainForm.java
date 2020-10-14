package cn.campsg.practical.bubble;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import org.apache.log4j.Logger;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

import cn.campsg.practical.bubble.common.StarAnimation;
import cn.campsg.practical.bubble.common.StarFormUtils;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.StarList;
import cn.campsg.practical.bubble.exception.NoClearedStarsException;
import cn.campsg.practical.bubble.exception.ServiceInitException;
import cn.campsg.practical.bubble.service.StarService;

/**
 * 泡泡糖窗体类，用于显示泡泡糖阵列、处理泡泡糖点击事件与动画
 * 
 * 
 * @author Frank.Chen
 * @version 1.5
 */
public class MainForm extends Application {
	
	/** 创建StarServiceImpl的日志输出类 **/
	protected static Logger log = Logger.getLogger("StarServiceImpl");
	//powered by Jingyu Zhang
	/** 从服务端获取的完整10*10泡泡糖列表 **/
	private StarList mCurretStars = null;

	/** 窗体中显示泡泡糖的区域 **/
	private AnchorPane mStarForm = null;
	
	/** 窗体根容器 **/
	private AnchorPane mRoot = null;

	public static void show(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) {

		try {
			mRoot = (AnchorPane) FXMLLoader.load(getClass()
					.getResource("/res/layout/main_layout.fxml"));

			// 将主布局加入到视图场景中
			Scene scene = new Scene(mRoot);
			primaryStage.setScene(scene);

			// 页面加载时或重新开始新的泡泡糖棋局时候初始化泡泡糖
			initGameStars(mRoot);

			primaryStage.setTitle("消灭泡泡糖-Popstar3");
			primaryStage.setResizable(false);
			primaryStage.show();
			
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	/**
	 * 页面加载时或重新开始新的泡泡糖棋局时候初始化泡泡糖
	 * 
	 * @param root
	 *            窗体总布局
	 * 
	 */
	private void initGameStars(AnchorPane root) {
		
		// 返回窗体中显示泡泡糖的区域
		mStarForm = (AnchorPane) root.lookup("#game_pane");
		
		// 创建消灭泡泡糖业务类
		StarService starService = null;
		try {
			starService = getStarService();
		} catch (ServiceInitException e) {
			//显示错误信息提示用户
			StarFormUtils.errorMessage(e.getMessage());
			//退出应用程序
			System.exit(0);
		}

		// 创建调用创建泡泡糖代码
		mCurretStars = starService.createStars();

		// 循环遍历所有泡泡糖，将泡泡糖对象Star转化为界面显示控件Label
		for (int i = 0; i < mCurretStars.size(); i++) {
			// 从泡泡糖集合中取出一个泡泡糖
			Star star = mCurretStars.get(i);

			// 创建界面泡泡糖显示控件Label
			Label starFrame = new Label();
			starFrame.setPrefWidth(48);
			starFrame.setPrefHeight(48);

			// 获取泡泡糖对象Star的行与列
			int row = star.getPosition().getRow();
			int col = star.getPosition().getColumn();

			// 为泡泡糖显示控件Label设置唯一标识ID，ID规则为s+行号+列号（例如：s00,s01）
			starFrame.setId("s" + row + col);
			// 将泡泡糖的坐标位置保存起来用于识别泡泡糖在界面中的位置。
			starFrame.setUserData(row + ";" + col);
			// 设置泡泡糖显示控件Label在界面的呈现坐标
			starFrame.setLayoutX(col * 48);
			starFrame.setLayoutY(row * 48);

			// 设置泡泡糖显示控件Label显示外观
			switch (star.getType().value()) {
			case 0:
				starFrame.getStyleClass().add("blue_star");
				break;
			case 1:
				starFrame.getStyleClass().add("green_star");
				break;
			case 2:
				starFrame.getStyleClass().add("yellow_star");
				break;
			case 3:
				starFrame.getStyleClass().add("red_star");
				break;
			case 4:
				starFrame.getStyleClass().add("purple_star");
				break;
			}

			StartEventHandler handler = new StartEventHandler(starService);
			starFrame.setOnMouseClicked(handler);

			// 将泡泡糖加入到窗体中显示泡泡糖的区域
			mStarForm.getChildren().add(starFrame);
			
			/******************** PRJ-BU2-EL-009 Task3 ********************/
			if(log.isDebugEnabled())
			{
				showStarsCoordinate();
			}
			//powered by Jingyu Zhang
			

			/**************************************************************/
		}

	}

	/**
	 * 泡泡糖被点击的事件处理对象
	 */
	public class StartEventHandler implements EventHandler<MouseEvent> {
		private StarService starService = null;

		public StartEventHandler(StarService starService) {
			this.starService = starService;
		}

		@Override
		public void handle(MouseEvent event) {

			// 获取被点击的泡泡糖视图
			Label starFrame = (Label) event.getTarget();

			// 将视图转换为泡泡糖实体
			Star base = StarFormUtils.convert(starFrame);

			// 从服务端获取需要清除的泡泡糖列表
			StarList clearStars = null;
			try {
				clearStars = starService.tobeClearedStars(base,
						mCurretStars);
			} catch (NoClearedStarsException e) {
				return;
			}

			// 根据从服务端获取需要清除的泡泡糖列表，清除对应的视图
			clearStars(clearStars);

		}

	}

	/**
	 * 根据从服务端获取需要清除的泡泡糖列表，清除对应的视图
	 * 
	 * @param clearStars
	 *            从服务端获取需要清除的泡泡糖列表
	 */
	private void clearStars(StarList clearStars) {
		if (clearStars == null || clearStars.size() == 0)
			return;

		for (Star star : clearStars) {

			Label starFrame = StarFormUtils.findFrame(star, mStarForm);

			// 删除界面上的泡泡糖
			StarAnimation.clearStarLable(mStarForm, starFrame);

			// 删除内存中的泡泡糖（与界面保持一致）
			mCurretStars.setNull(star.getPosition().getRow(), star
					.getPosition().getColumn());
		}
	}

	/**
	 * 基于接口动态创建泡泡糖服务类，服务类名保存与bean.conf配置文件中
	 * 
	 * @return 泡泡糖服务类
	 * @throws FileNotFoundException
	 */
	private StarService getStarService() throws ServiceInitException {
		// 创建JVM类加载器
		ClassLoader loader = this.getClass().getClassLoader();

		// 从配置文件bean.conf中读取泡泡糖服务类[类全名]
		String className = getClassName();

		try {
			// 加载泡泡糖服务类
			Class<?> clazz = loader.loadClass(className);
			// 动态创建并返回泡泡糖服务类的实例
			return (StarService) clazz.newInstance();
		} catch (Exception e) {
			return null;
		}

	}

	/**
	 * 从配置文件bean.conf中读取泡泡糖服务类[类全名]
	 * 
	 * @return 泡泡糖服务类[类全名]
	 * @throws FileNotFoundException
	 */
	private String getClassName() throws ServiceInitException {

		InputStream is = getClass().getClassLoader().getResourceAsStream(
				"bean.conf");

		if (is == null)
			throw new ServiceInitException("核心文件丢失，请重新安装本游戏");

		// 读取bean.conf配置文件
		BufferedReader br = new BufferedReader(new InputStreamReader(is));

		try {
			// 读取第一行数据
			String line = br.readLine();
			// 返回等号右侧的泡泡糖服务类[类全名]字符串
			return line.split("=")[1];
		} catch (IOException e) {
			throw new ServiceInitException("核心文件损坏，请重新安装本游戏");
		}
	}

	/**
	 * 调试状态下可显示泡泡糖的坐标
	 * 
	 * @param root
	 * @param pane
	 */
	private void showStarsCoordinate() {

		// 获取菜单对象
		FlowPane menu_title = (FlowPane) mRoot.lookup("#menu_title");

		menu_title.setOnMousePressed(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				for (int i = 0; i < mStarForm.getChildren().size(); i++) {
					Label button = (Label) mStarForm.getChildren().get(i);
					button.setText("(" + button.getId() + ")");
				}
			}

		});

		menu_title.setOnMouseReleased(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				for (int i = 0; i < mStarForm.getChildren().size(); i++) {
					Label button = (Label) mStarForm.getChildren().get(i);
					button.setText("");
				}

			}

		});
	}
}
