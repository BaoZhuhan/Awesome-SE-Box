package week6t5;
import java.util.GregorianCalendar;
public class Main {
	public static void main(String[] args) {
		GregorianCalendar gc = new GregorianCalendar();
		System.out.println("Year is " + gc.get(GregorianCalendar.YEAR));
		System.out.println("Month is " + gc.get(GregorianCalendar.MONTH));
		System.out.println("Date is " + gc.get(GregorianCalendar.DAY_OF_MONTH));
		
		gc.setTimeInMillis(1234567898765L);
		System.out.println("Year is " + gc.get(GregorianCalendar.YEAR));
		System.out.println("Month is " + gc.get(GregorianCalendar.MONTH));
		System.out.println("Date is " + gc.get(GregorianCalendar.DAY_OF_MONTH));
	}
}
