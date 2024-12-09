import java.util.Scanner;
class InvalidScoreException extends Exception {
    private int score;
    
    public InvalidScoreException(int score) {
        this.score = score;
    }
    
    @Override
    public String toString() {
        return score + " invalid!"; 
    } 
}
class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int passCount = 0;
        int failCount = 0;

        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            int score = -1;
            while (true) {
                try {
                    score = scanner.nextInt();
                    if (score < 0 || score > 100) {
                        throw new InvalidScoreException(score);
                    }
                    break;
                } catch (InvalidScoreException e) {
                    System.out.println(e);
                }
            }

            if (score >= 60) {
                passCount++;
            } else {
                failCount++;
            }
        }

        System.out.println(passCount);
        System.out.println(failCount);
    }
}