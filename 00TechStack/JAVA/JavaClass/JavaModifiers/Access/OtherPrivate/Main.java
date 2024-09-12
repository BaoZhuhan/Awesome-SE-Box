package JAVA.JavaClass.JavaModifiers.Access.OtherPrivate;

public class Main {
    private String fname = "John";
    private String lname = "Doe";
    private String email = "john@doe.com";
    private int age = 21;

    public static void main(String[] args) {
        Main o2 = new Main();
        System.out.println(o2.fname + " " + o2.lname);
        System.out.println(o2.email);
        System.out.println(o2.age);
    }
}
