import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        ArrayList<Integer> list = new ArrayList<>();
        System.out.print("Enter integers(input ends with 0):");
        Scanner input = new Scanner(System.in);
        while(true){
            int num = input.nextInt();
            if(num == 0) break;
            list.add(num);
        }
        System.out.println("The minimum number is " + min(list));
    }

    public static Integer min(ArrayList<Integer> list){
        if (list == null || list.isEmpty()) {
            return null;
        }
        Integer min = list.get(0);
        for (Integer num : list) {
            if (num < min) {
                min = num;
            }
        }
        return min;
    }
}