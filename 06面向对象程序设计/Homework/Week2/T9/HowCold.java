import java.util.Scanner;

public class HowCold {
    public static void main(String[] args){
        System.out.print("请输入华氏温度-58 ºF和41ºF之间：");
        try (Scanner input = new Scanner(System.in)) {
            double ta = input.nextDouble();
            System.out.print("输入风速（>=2 ）：");
            double v = input.nextDouble();
            double windChillIndex = 35.74 + 0.6215 * ta - 35.75 * Math.pow(v, 0.16) + 0.4275 * ta * Math.pow(v, 0.16);
            System.out.println("寒冷指数：" + windChillIndex);
        }
    }
}