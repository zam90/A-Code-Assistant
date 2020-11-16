package Connect;

import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBCUtil {
    private static String driver;
    private static String url;
    private static String user;
    private static String passw;
    private static Properties DBconn = new Properties();
    private JDBCUtil(){}

    static {
        try{
            DBconn.load(JDBCUtil.class.getClassLoader().getResourceAsStream("DB.properties"));
            driver = DBconn.getProperty("DRIVER");
            url = DBconn.getProperty("URL");
            user = DBconn.getProperty("USER");
            passw = DBconn.getProperty("PASSW");
            try {
                Class.forName(driver);
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //创建连接方法
    public static Connection getConnection() throws SQLException{
        return DriverManager.getConnection(url,user,passw);
    }

    //
    public static void free(ResultSet rs, Statement st, Connection conn) throws Exception{
        if(rs!=null){
            rs.close();
        }
        if(st!=null){
            st.close();
        }
        if(conn!=null){
            conn.close();
        }
    }
}
