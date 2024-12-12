import java.util.Scanner;
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] nums = new int[n];
        input.nextLine();
        for (int i = 0; i < n; i++) {
            String s;
            while(true){
                try{
                    s = input.nextLine();
                    nums[i] = Integer.parseInt(s); 
                    break;
                }catch(NumberFormatException e){
                    System.out.println("Java.lang.NumberFormatException: For input string: " + e.getMessage());
                }
            }
        }
        System.out.println(Arrays.toString(nums));
        input.close();
    }
}