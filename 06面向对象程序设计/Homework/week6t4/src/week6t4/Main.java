package week6t4;
import java.util.Random;
public class Main {
	public static void main(String[] args) {
		Random num = new Random(1000);
		for(int i = 0 ; i < 5; i++) {
			for(int j = 0 ; j < 10 ; j++) {
				System.out.print(num.nextInt(100)+" ");
			}
			System.out.print("\n");
		}
		
	}
}
