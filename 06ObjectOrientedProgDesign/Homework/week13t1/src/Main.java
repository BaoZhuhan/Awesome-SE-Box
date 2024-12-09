import java.util.Random;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        try {
            Random random = new Random();
            Scanner input = new Scanner(System.in);
            int[] nums = new int[100];
            for (int i = 0; i < 100; i++)
                nums[i] = random.nextInt();
            System.out.print("Enter an index: ");
            int index = input.nextInt();
            System.out.println("The element is " + nums[index]);
            input.close();
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Index out of bound");
        }
    }
}