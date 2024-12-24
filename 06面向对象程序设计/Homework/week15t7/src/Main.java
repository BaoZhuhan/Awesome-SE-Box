import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class Main {
    public static void main(String[] args) throws Exception {
        Loan[] loans = new Loan[5];
        loans[0] = new Loan(3.5, 5, 10000);
        loans[1] = new Loan(4.0, 10, 20000);
        loans[2] = new Loan(4.5, 15, 30000);
        loans[3] = new Loan(5.0, 20, 40000);
        loans[4] = new Loan(5.5, 25, 50000);

        try (ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream("Exercise12_7.dat"))) {
            for (Loan loan : loans) {
                output.writeObject(loan);
            }
        }
    }
}

//第十次作业没找到，这里伪造一个
class Loan implements Serializable {
    private double annualInterestRate;
    private int numberOfYears;
    private double loanAmount;

    public Loan(double annualInterestRate, int numberOfYears, double loanAmount) {
        this.annualInterestRate = annualInterestRate;
        this.numberOfYears = numberOfYears;
        this.loanAmount = loanAmount;
    }
}
