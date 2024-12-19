import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FileWriter fileW = null;
        fileW = new FileWriter("rw.txt");
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            fileW.write(String.valueOf(random.nextInt(100)));
            if (i > 0 && i % 10 == 0) {
                fileW.write("\n");
            } else {
                fileW.write(" ");
            }
        }
        fileW.close();
        Scanner input = new Scanner(new File("rw.txt"));
        int[] nums = new int[100];
        for (int i = 0; i < 100; i++) {
            nums[i] = input.nextInt();
        }
        for (int i = 99; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < 100; i++) {
            System.out.print(nums[i] + " ");
            if (i % 9 == 0) {
                System.out.print("\n");
            }
        }
        input.close();
    }
}
