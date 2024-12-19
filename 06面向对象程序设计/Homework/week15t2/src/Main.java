import java.util.Scanner;
import java.io.File;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(new File("./testdata.txt"));
        int cot = 0;
        double sum = 0, average = 0;
        while (input.hasNextDouble()) {
            cot++;
            sum += input.nextDouble();
        }
        average = sum / cot;
        input.close();
        System.out.println("总分: " + sum + "\n平均分: " + average);
    }
}
