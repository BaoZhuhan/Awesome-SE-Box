package week9t3;

public class MyInteger {
	int value;
	MyInteger(int value){
		this.value = value;
	}
	int getter() { return value; }
	boolean isEven() { return value%2==0; }
	boolean isOdd() { return value%2==1; }
	boolean isPrime() {
		for(int i = 2; i < Math.sqrt((double)value)+1; i++) {
			if(value%i==0) return false; 
		}
		return true;
	}
	static boolean isEven(int value) {return value%2 == 0; }
	static boolean isOdd(int value) {return value%2==1; }
	static boolean isPrime(int value) {
		for(int i = 2; i < Math.sqrt((double)value)+1; i++) {
			if(value%i==0) return false;
		}
		return true;
	}
	boolean equals(int value) {return this.value == value;}
	boolean equals(MyInteger now) {return this.value == now.value;}
	static int parseInt(char[] chars) {
        int result = 0;
        for (char c : chars) {
            if (c >= '0' && c <= '9') {
                result = result * 10 + (c - '0');
            } else {
            	break;
            }
        }
        return result;
    }
	static int parseInt(String str) {
        int result = 0;
        int sign = 1;
        int startIndex = 0;
        if (str.charAt(0) == '-') {
            sign = -1;
            startIndex = 1;
        }

        for (int i = startIndex; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c >= '0' && c <= '9') {
                result = result * 10 + (c - '0');
            } else {
               break;
            }
        }
        return result * sign;
    }
	  public static void main(String[] args) {
		    MyInteger n1 = new MyInteger(5);
		    System.out.println("n1 is even? " + n1.isEven());
		    System.out.println("n1 is prime? " + n1.isPrime());
		    System.out.println("15 is prime? " + MyInteger.isPrime(15));

		    char[] chars = {'3', '5', '3', '9'};
		    System.out.println(MyInteger.parseInt(chars));

		    String s = "3539";
		    System.out.println(MyInteger.parseInt(s));
		    
		    MyInteger n2 = new MyInteger(24);
		    System.out.println("n2 is odd? " + n2.isOdd());
		    System.out.println("45 is odd? " + MyInteger.isOdd(45));
		    System.out.println("n1 is equal to n2? " + n1.equals(n2));
		    System.out.println("n1 is equal to 5? " + n1.equals(5));
		  }
}
