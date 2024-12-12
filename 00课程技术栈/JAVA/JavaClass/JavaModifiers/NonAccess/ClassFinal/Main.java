package JAVA.JavaClass.JavaModifiers.NonAccess.ClassFinal;

public class Main extends Vehicle {
    private String modelName = "Mustang";

    public static void main(String[] args) {
        Main myFastCar = new Main();
        myFastCar.honk();
        System.out.println(myFastCar.brand + " " + myFastCar.modelName);
    }
}
