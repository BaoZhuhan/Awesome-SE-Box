import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main {
    public static void printCalendar(int year, int month) {
        final String months[] = { "January", "February", "March", "April", "May", "June", "July",
                "August", "September", "October", "November", "December" };
        System.out.println("        " + months[month - 1] + ", " + year);
        System.out.println("-----------------------------");
        Calendar fd = new GregorianCalendar(year, month - 1, 1);
        int dayOfWeek = fd.get(Calendar.DAY_OF_WEEK);
        System.out.println(" Sun Mon Tue Wed Thu Fri Sat");
        for (int i = 1; i < dayOfWeek; i++) {
            System.out.print("    ");
        }
        int daysInMonth = fd.getActualMaximum(Calendar.DAY_OF_MONTH);
        for (int day = 1; day <= daysInMonth; day++) {
            System.out.print(String.format("%4d", day));
            if ((day + dayOfWeek - 1) % 7 == 0) {
                System.out.println();
            }
        }
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        System.out.println("please input the year: ");
        int year = input.nextInt();
        System.out.println("please input the month");
        int month = input.nextInt();
        input.close();
        printCalendar(year, month);
    }
}