package JAVA.JavaClass.JavaModifiers.NonAccess.OtherFinal;

public class Main {
    final int x = 10;
    final double PI = 3.14;

    public static void main(String[] args){
        Main o1 = new Main();
        o1.x = 1; //error , you can't assign a value to a final variable
    }
}
