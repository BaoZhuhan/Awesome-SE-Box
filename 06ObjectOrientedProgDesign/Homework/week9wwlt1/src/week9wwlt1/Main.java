package week9wwlt1;

import java.math.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        BigDecimal e = calculateE(n);
        e = e.setScale(25, RoundingMode.CEILING);
        System.out.println(e.toPlainString());
        scanner.close();
    }

    private static BigDecimal calculateE(int n) {
        BigDecimal e = BigDecimal.ONE;
        BigDecimal factorial = BigDecimal.ONE;
        for (int i = 1; i <= n; i++) {
        	factorial = factorial.multiply(new BigDecimal(i + ""));
        	e = e.add(BigDecimal.ONE.divide(factorial,25,RoundingMode.CEILING));  
        }
        return e;
    }    
}
