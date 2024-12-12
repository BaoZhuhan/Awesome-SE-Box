import java.util.Scanner;

public class CompoundInterest {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double money = input.nextDouble();
		for(int i = 0 ; i < 5 ; i++) {
			money *= 1.00417;
			money += input.nextDouble();
		}
		
		System.out.println(String.format("%.2f",money));
	}
}
