import java.util.Scanner;

public class T8 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("输入体重磅：");
        double weight = input.nextDouble();
        System.out.print("输入身高英寸：");
        double height = input.nextDouble();
        weight *= 0.45359237;
        height *= 0.0254;
        System.out.println(weight/(height*height));
    }
}
