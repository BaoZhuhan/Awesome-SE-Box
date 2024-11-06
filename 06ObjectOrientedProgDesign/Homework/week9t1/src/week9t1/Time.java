package week9t1;

public class Time {
	private int hour;
	private int minute;
	private int second;
	Time(){
		setTime(System.currentTimeMillis()+8*60*60*1000);
	}
	
	Time(long elapseTime){
		setTime(elapseTime);
	}
	
	Time(int hour, int minute, int second){
		this.hour = hour;
		this.minute = minute;
		this.second = second;
	}
	
	int getHour() {return hour;}
	int getMinute() { return minute;}
	int getSecond() { return second;}
		
	void setTime(long elapseTime) {
		long totalSeconds = elapseTime/1000;
		this.second = (int)(totalSeconds%60);
		long totalMinutes = totalSeconds/60;
		this.minute = (int)(totalMinutes%60);
		long totalHours = totalMinutes/60;
		this.hour = (int)((totalHours)%24);
	}
	
    public static void main(String[] args) {
        Time time1 = new Time();
        System.out.println("Hours: " + time1.getHour() + " Minutes: " + time1.getMinute() + " Seconds: " + time1.getSecond());

        Time time2 = new Time((long)555550000);
        System.out.println("Hours: " + time2.getHour() + " Minutes: " + time2.getMinute() + " Seconds: " + time2.getSecond());
    }
}
