package week10t3;

import java.math.*;

public class Main {
    public static void main(String[] args) {
    	for(int i = 100; i < 1300 ; i += 100) {
    		BigDecimal e = calculateE(i);
            e = e.setScale(25, RoundingMode.CEILING);
            System.out.println("The e is " + e.toPlainString() + " for i = " + i);  
    	}
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
