import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void average(ArrayList<Number> list) {
        double sum = 0;
        int cot = 0;
        for (Number i : list) {
            cot++;
            sum += i.doubleValue();
        }
        System.out.println(sum / cot);
    }

    public static void main(String[] args) throws Exception {
        ArrayList<Number> list = new ArrayList<Number>();
        Scanner input = new Scanner(System.in);
        double num = input.nextDouble();
        while (num != -1) {
            list.add(num);
            num = input.nextDouble();
        }
        average(list);
        input.close();
    }
}
