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
 * �����Ǵ����࣬������ʾ���������С����������ǵ���¼��붯��
 * 
 * 
 * @author Frank.Chen
 * @version 1.5
 */
public class MainForm extends Application {
	
	/** ����StarServiceImpl����־����� **/
	protected static Logger log = Logger.getLogger("StarServiceImpl");
	//powered by Jingyu Zhang
	/** �ӷ���˻�ȡ������10*10�������б� **/
	private StarList mCurretStars = null;

	/** ��������ʾ�����ǵ����� **/
	private AnchorPane mStarForm = null;
	
	/** ��������� **/
	private AnchorPane mRoot = null;

	public static void show(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) {

		try {
			mRoot = (AnchorPane) FXMLLoader.load(getClass()
					.getResource("/res/layout/main_layout.fxml"));

			// �������ּ��뵽��ͼ������
			Scene scene = new Scene(mRoot);
			primaryStage.setScene(scene);

			// ҳ�����ʱ�����¿�ʼ�µ����������ʱ���ʼ��������
			initGameStars(mRoot);

			primaryStage.setTitle("����������-Popstar3");
			primaryStage.setResizable(false);
			primaryStage.show();
			
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	/**
	 * ҳ�����ʱ�����¿�ʼ�µ����������ʱ���ʼ��������
	 * 
	 * @param root
	 *            �����ܲ���
	 * 
	 */
	private void initGameStars(AnchorPane root) {
		
		// ���ش�������ʾ�����ǵ�����
		mStarForm = (AnchorPane) root.lookup("#game_pane");
		
		// ��������������ҵ����
		StarService starService = null;
		try {
			starService = getStarService();
		} catch (ServiceInitException e) {
			//��ʾ������Ϣ��ʾ�û�
			StarFormUtils.errorMessage(e.getMessage());
			//�˳�Ӧ�ó���
			System.exit(0);
		}

		// �������ô��������Ǵ���
		mCurretStars = starService.createStars();

		// ѭ���������������ǣ��������Ƕ���Starת��Ϊ������ʾ�ؼ�Label
		for (int i = 0; i < mCurretStars.size(); i++) {
			// �������Ǽ�����ȡ��һ��������
			Star star = mCurretStars.get(i);

			// ����������������ʾ�ؼ�Label
			Label starFrame = new Label();
			starFrame.setPrefWidth(48);
			starFrame.setPrefHeight(48);

			// ��ȡ�����Ƕ���Star��������
			int row = star.getPosition().getRow();
			int col = star.getPosition().getColumn();

			// Ϊ��������ʾ�ؼ�Label����Ψһ��ʶID��ID����Ϊs+�к�+�кţ����磺s00,s01��
			starFrame.setId("s" + row + col);
			// �������ǵ�����λ�ñ�����������ʶ���������ڽ����е�λ�á�
			starFrame.setUserData(row + ";" + col);
			// ������������ʾ�ؼ�Label�ڽ���ĳ�������
			starFrame.setLayoutX(col * 48);
			starFrame.setLayoutY(row * 48);

			// ������������ʾ�ؼ�Label��ʾ���
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

			// �������Ǽ��뵽��������ʾ�����ǵ�����
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
	 * �����Ǳ�������¼��������
	 */
	public class StartEventHandler implements EventHandler<MouseEvent> {
		private StarService starService = null;

		public StartEventHandler(StarService starService) {
			this.starService = starService;
		}

		@Override
		public void handle(MouseEvent event) {

			// ��ȡ���������������ͼ
			Label starFrame = (Label) event.getTarget();

			// ����ͼת��Ϊ������ʵ��
			Star base = StarFormUtils.convert(starFrame);

			// �ӷ���˻�ȡ��Ҫ������������б�
			StarList clearStars = null;
			try {
				clearStars = starService.tobeClearedStars(base,
						mCurretStars);
			} catch (NoClearedStarsException e) {
				return;
			}

			// ���ݴӷ���˻�ȡ��Ҫ������������б������Ӧ����ͼ
			clearStars(clearStars);

		}

	}

	/**
	 * ���ݴӷ���˻�ȡ��Ҫ������������б������Ӧ����ͼ
	 * 
	 * @param clearStars
	 *            �ӷ���˻�ȡ��Ҫ������������б�
	 */
	private void clearStars(StarList clearStars) {
		if (clearStars == null || clearStars.size() == 0)
			return;

		for (Star star : clearStars) {

			Label starFrame = StarFormUtils.findFrame(star, mStarForm);

			// ɾ�������ϵ�������
			StarAnimation.clearStarLable(mStarForm, starFrame);

			// ɾ���ڴ��е������ǣ�����汣��һ�£�
			mCurretStars.setNull(star.getPosition().getRow(), star
					.getPosition().getColumn());
		}
	}

	/**
	 * ���ڽӿڶ�̬���������Ƿ����࣬��������������bean.conf�����ļ���
	 * 
	 * @return �����Ƿ�����
	 * @throws FileNotFoundException
	 */
	private StarService getStarService() throws ServiceInitException {
		// ����JVM�������
		ClassLoader loader = this.getClass().getClassLoader();

		// �������ļ�bean.conf�ж�ȡ�����Ƿ�����[��ȫ��]
		String className = getClassName();

		try {
			// ���������Ƿ�����
			Class<?> clazz = loader.loadClass(className);
			// ��̬���������������Ƿ������ʵ��
			return (StarService) clazz.newInstance();
		} catch (Exception e) {
			return null;
		}

	}

	/**
	 * �������ļ�bean.conf�ж�ȡ�����Ƿ�����[��ȫ��]
	 * 
	 * @return �����Ƿ�����[��ȫ��]
	 * @throws FileNotFoundException
	 */
	private String getClassName() throws ServiceInitException {

		InputStream is = getClass().getClassLoader().getResourceAsStream(
				"bean.conf");

		if (is == null)
			throw new ServiceInitException("�����ļ���ʧ�������°�װ����Ϸ");

		// ��ȡbean.conf�����ļ�
		BufferedReader br = new BufferedReader(new InputStreamReader(is));

		try {
			// ��ȡ��һ������
			String line = br.readLine();
			// ���صȺ��Ҳ�������Ƿ�����[��ȫ��]�ַ���
			return line.split("=")[1];
		} catch (IOException e) {
			throw new ServiceInitException("�����ļ��𻵣������°�װ����Ϸ");
		}
	}

	/**
	 * ����״̬�¿���ʾ�����ǵ�����
	 * 
	 * @param root
	 * @param pane
	 */
	private void showStarsCoordinate() {

		// ��ȡ�˵�����
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
