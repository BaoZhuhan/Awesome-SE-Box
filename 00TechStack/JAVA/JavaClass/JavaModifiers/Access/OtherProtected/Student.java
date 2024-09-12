package JAVA.JavaClass.JavaModifiers.Access.OtherProtected;

public class Student extends Person{
    private int graduationYear = 24;
    
    public static void main(String[] args){
        Student s1 = new Student();
        System.out.println(s1.fname + " " + s1.lname);
        System.out.println(s1.email);
        System.out.println(s1.age);
        System.out.println(s1.graduationYear);
    }
}
