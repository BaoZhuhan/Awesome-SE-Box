package week10t2;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class MyDate {
    private int year;
    private int month;
    private int day;

    MyDate() {
        GregorianCalendar date = new GregorianCalendar();
        this.year = date.get(Calendar.YEAR);
        this.month = date.get(Calendar.MONTH);
        this.day = date.get(Calendar.DAY_OF_MONTH);
    }
    MyDate(long elapsedTime) {
        setDate(elapsedTime);
    }
    MyDate(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }
    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    void setDate(long elapsedTime) {
        GregorianCalendar date = new GregorianCalendar();
        date.setTimeInMillis(elapsedTime);
        this.year = date.get(Calendar.YEAR);
        this.month = date.get(Calendar.MONTH);
        this.day = date.get(Calendar.DAY_OF_MONTH);
    }
    
    public static void main(String[] args) {
        MyDate date1 = new MyDate();
        MyDate date2 = new MyDate(34355555133101L);

        System.out.println("The current time is:\nYear: " + date1.getYear() + "\nmonth: " + (date1.getMonth() + 1) + "\nday: " + date1.getDay());
        System.out.println("34355555133101L millisecond is:\nYear: " + date2.getYear() + "\nmonth:" + (date2.getMonth()) + "\nday:" + date2.getDay());
    }
}
