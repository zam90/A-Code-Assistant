package cn.campsg.practical.bubble;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import cn.campsg.practical.bubble.common.StarAnimation;
import cn.campsg.practical.bubble.common.StarFormUtils;
import cn.campsg.practical.bubble.entity.Star;
import cn.campsg.practical.bubble.entity.StarList;
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

	/** �ӷ���˻�ȡ������10*10�������б� **/
	private StarList mCurretStars = null;

	/** ��������ʾ�����ǵ����� **/
	private AnchorPane mStarForm = null;

	public static void show(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) {

		try {
			AnchorPane root = (AnchorPane) FXMLLoader.load(getClass()
					.getResource("/res/layout/main_layout.fxml"));

			// �������ּ��뵽��ͼ������
			Scene scene = new Scene(root);
			primaryStage.setScene(scene);



			// ҳ�����ʱ�����¿�ʼ�µ����������ʱ���ʼ��������
			initGameStars(root);

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
			StarList clearStars = starService.tobeClearedStars(base,
						mCurretStars);

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
}
