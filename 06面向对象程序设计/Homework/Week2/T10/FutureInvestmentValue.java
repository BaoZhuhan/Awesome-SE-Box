import java.util.Scanner;

public class FutureInvestmentValue {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        double investmentAmount = input.nextDouble();
        double yearlyInterestRate = input.nextDouble();
        yearlyInterestRate /= 100;
        double numberOfYears = input.nextDouble();

        double futureInvestmentValue = investmentAmount * Math.pow((1.0 + yearlyInterestRate), numberOfYears);

        System.out.println(futureInvestmentValue);
    }
}
