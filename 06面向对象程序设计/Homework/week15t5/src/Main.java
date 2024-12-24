import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Random;

public class Main {
    public static void main(String[] args) throws Exception {
        File file = new File("Exercise12_6.dat");
        try (DataOutputStream output = new DataOutputStream(new FileOutputStream(file, true))) {
            Random random = new Random();
            for (int i = 0; i < 100; i++) {
                int number = random.nextInt();
                output.writeInt(number);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}