package JAVA.JavaClass.JavaModifiers.NonAccess.ClassAbstract;

class Second {
    public static void main(String[] args) {
        // create an object of the Student class (which inherits attributes and methods
        // from Main)
        Student myObj = new Student();

        System.out.println("Name: " + myObj.fname + " " + myObj.lname);
        System.out.println("Email: " + myObj.email);
        System.out.println("Age: " + myObj.age);
        System.out.println("Graduation Year: " + myObj.graduationYear);
        myObj.study(); // call abstract method
    }
}