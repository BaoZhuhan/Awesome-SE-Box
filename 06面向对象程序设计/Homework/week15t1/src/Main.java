import java.util.Scanner;
import java.io.File;

public class Main {
    public static int cotCLine(String line) {
        return line.length();
    }


    public static int cotWLine(String line){
        int res = 0;
        String[] words = line.split("\\s+");
        res = words.length;
        return res;
    }

    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(new File("./src/Loan.java"));
        int cotC = 0, cotW = 0, cotLine = 0;
        while (input.hasNextLine()) {
            String line = input.nextLine();
            cotC += cotCLine(line);
            cotW += cotWLine(line);
            cotLine++;
        }
        input.close();
        System.out.printf("字符：" + cotC + " 单词：" + cotW + " 行：" + cotLine + "\n");
    }
}
