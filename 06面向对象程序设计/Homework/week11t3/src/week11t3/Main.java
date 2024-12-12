package week11t3;

import java.util.Date;

class Account {
	private int id = 0;
	private double balance = 0;
	private double annualInterestRate = 0;
	private Date dateCreated ;
	
	Account() {
		dateCreated = new Date();
	}
	Account(int newid, double newbalance){
		id = newid;
		balance = newbalance;
		dateCreated = new Date();
	}
	
	int getid() {
		return id;
	}
	double getbalance() {
		return balance;
	}
	double getannualInterestRate() {
		return annualInterestRate*100.0;
	}
	void setid(int newid) {
		id  = newid;
	}
	void setbalance(double newbalance) {
		balance = newbalance;
	}
	void setannualInterestRate(double newannualInterestRate) {
		annualInterestRate = newannualInterestRate/100.0;
	}
	Date getdateCreate() {
		return dateCreated;
	}
	double getMonthlyInterestRate () {
		return annualInterestRate/12.0d;
	}
	double getMonthlyInterest() {
		return this.getMonthlyInterestRate()*this.getbalance();
	}
	void withDraw(double money) {
		balance -= money;
	}
	void deposit(double money) {
		balance += money;
	}
	public String toString() {
		return "Account: id=" + this.getid();
	}
}

class SavingsAccount extends Account {
    SavingsAccount(int id, double balance) {
        super(id, balance);
    }
    public String toString() {
        return "SavingsAccount id=" + this.getid();
    }
}

class CheckingAccount extends Account {
    private double overdraftLimit = 0;

    CheckingAccount(int id, double balance) {
        super(id, balance);
    }

    public String toString() {
        return "CheckAccount id=" + this.getid() + " overdraft limit: " + this.overdraftLimit;
    }
}

public class Main {
    public static void main(String[] args) {
        Account a1 = new Account(1, 0);
        SavingsAccount a2 = new SavingsAccount(2, 0);
        CheckingAccount a3 = new CheckingAccount(3, 0);
        System.out.println(a1.toString());
        System.out.println(a2.toString());
        System.out.println(a3.toString());
    }
}
