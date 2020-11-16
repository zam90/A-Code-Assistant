package OPER;

import java.text.SimpleDateFormat;
import java.util.Date;

public class DateTime {

    public SimpleDateFormat getTime(){
        Date now = new Date( );
        SimpleDateFormat nowtime = new SimpleDateFormat ("yyyy-MM-dd hh:mm:ss");
        return nowtime;
    }
}
