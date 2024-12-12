package week9t1;

public class Main {
    public static void main(String[] args) {
        Time time1 = new Time();
        System.out.println("Hours: " + time1.getHour() + " Minutes: " + time1.getMinute() + " Seconds: " + time1.getSecond());

        Time time2 = new Time((long)555550000);
        System.out.println("Hours: " + time2.getHour() + " Minutes: " + time2.getMinute() + " Seconds: " + time2.getSecond());
    }
}
