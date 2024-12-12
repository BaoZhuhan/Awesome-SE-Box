import java.util.ArrayList;
import java.util.Date;

public class Main {
    public static void main(String[] args) {

        Account account = new Account("George", 1122, 1000);
        account.setAnnualInterestRate(1.5);

        account.deposit(30);
        account.deposit(40);
        account.deposit(50);

        account.withdraw(5);
        account.withdraw(4);
        account.withdraw(2);

        System.out.println("Name: " + account.getName());
        System.out.println("Annual interest rate: " + account.getAnnualInterestRate());
        System.out.println("Balance: " + account.getBalance());
        System.out.println("Date                         Type    Amount    Balance");
        for (Transaction transaction : account.getTransactions()) {
            System.out.println(transaction);
        }
    }
}

class Transaction {
    private Date date;
    private char type;
    private double amount;
    private double balance;

    public Transaction(Date date, char type, double amount, double balance) {
        this.date = date;
        this.type = type;
        this.amount = amount;
        this.balance = balance;
    }

    public Date getDate() {
        return date;
    }

    public char getType() {
        return type;
    }

    public double getAmount() {
        return amount;
    }

    public double getBalance() {
        return balance;
    }

    @Override
    public String toString() {
        return date +
                "    " + type +
                "      " + amount +
                "      " + balance;
    }
}

class Account {
    private String name;
    private int id;
    private double balance;
    private double annualInterestRate;
    private ArrayList<Transaction> transactions = new ArrayList<>();

    public Account(String name, int id, double balance) {
        this.name = name;
        this.id = id;
        this.balance = balance;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public double getBalance() {
        return balance;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public ArrayList<Transaction> getTransactions() {
        return transactions;
    }

    public void withdraw(double amount) {
        balance -= amount;
        transactions.add(new Transaction(new Date(), 'W', amount, balance));
    }

    public void deposit(double amount) {
        balance += amount;
        transactions.add(new Transaction(new Date(), 'D', amount, balance));
    }
}
