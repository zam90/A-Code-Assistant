package Zam;

import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import Zam.PlayerMain;

import uk.co.caprica.vlcj.component.EmbeddedMediaPlayerComponent;
import uk.co.caprica.vlcj.player.embedded.EmbeddedMediaPlayer;
import javax.swing.JButton;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JProgressBar;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JSlider;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;

public class Window extends JFrame {

    /**
     *
     */
    private static final long serialVersionUID = 1L;
    private JPanel contentPane;
    EmbeddedMediaPlayerComponent playerComponent;
    private JPanel panel;
    private JButton btnPlay;
    private JButton btnPause;
    private JButton btnStop;
    private JButton btnMute;
    private JPanel controlpanel;
    private JProgressBar progress;
    private JMenuBar menuBar;
    private JMenu menu;
    private JMenuItem openmenu;
    private JMenuItem closemenu;
    private JSlider slider;

    /**
     * Launch the application.
     */
    public static void main(String[] args) {

    }

    /**
     * Create the frame.
     */
    public Window() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 960, 540);

        menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        menu = new JMenu("选项");
        menuBar.add(menu);

        openmenu = new JMenuItem("打开文件");
        menu.add(openmenu);

        closemenu = new JMenuItem("退出程序");
        menu.add(closemenu);

        openmenu.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {

                PlayerMain.openVideo();
            }
        });

        closemenu.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {

                PlayerMain.exit();
            }
        });






        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel Videopanel = new JPanel();
        contentPane.add(Videopanel, BorderLayout.CENTER);
        Videopanel.setLayout(new BorderLayout(0, 0));

        playerComponent = new EmbeddedMediaPlayerComponent();
        Videopanel.add(playerComponent);

        panel = new JPanel();
        Videopanel.add(panel, BorderLayout.SOUTH);
        panel.setLayout(new BorderLayout(0, 0));

        controlpanel = new JPanel();
        panel.add(controlpanel);

        btnStop = new JButton("停止");
        controlpanel.add(btnStop);

        btnPlay = new JButton("播放");
        controlpanel.add(btnPlay);

        btnPause = new JButton("暂停");
        controlpanel.add(btnPause);

        btnMute = new JButton("静音");
        controlpanel.add(btnMute);

        slider = new JSlider();
        slider.setValue(100);
        slider.setMaximum(120);
        slider.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                PlayerMain.setvol(slider.getValue());
            }
        });
        controlpanel.add(slider);

        progress = new JProgressBar();
        progress.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int x=e.getX();
                PlayerMain.jumpTo(((float)x/progress.getWidth()));

            }
        });
        progress.setStringPainted(true);
        panel.add(progress, BorderLayout.NORTH);
        btnPause.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                PlayerMain.pause();
            }
        });
        btnPlay.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                PlayerMain.play();
            }
        });
        btnStop.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {

                PlayerMain.stop();
            }
        });
        btnMute.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                PlayerMain.mute();
            }
        });
    }

    public EmbeddedMediaPlayer  getMediaPlayer() {

        return playerComponent.getMediaPlayer();
    }
    public JProgressBar getProgressBar(){

        return progress;
    }

}