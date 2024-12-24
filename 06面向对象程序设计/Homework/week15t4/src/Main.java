import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        String filePath = "robots.txt";
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filePath));
            String line;
            int wordCount = 0;
            while ((line = reader.readLine()) != null) {
                String[] words = line.split("\\s+");
                wordCount += words.length;
            }
            reader.close();
            System.out.println("单词的数量为：" + wordCount + "字");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}