import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.Date;

public class Main {
    public static void main(String[] args) throws Exception {
        int[] numbers = { 1, 2, 3, 4, 5 };
        Date currentDate = new Date();
        double doubleValue = 5.5;

        try (ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream("Exercise12_6.dat"))) {
            output.writeObject(numbers);
            output.writeObject(currentDate);
            output.writeDouble(doubleValue);
        }
    }
}