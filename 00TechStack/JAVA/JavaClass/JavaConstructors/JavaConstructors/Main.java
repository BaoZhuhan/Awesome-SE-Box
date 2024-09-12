package JAVA.JavaClass.JavaConstructors.JavaConstructors;

public class Main {
    int x;

    public Main(){
        x = 5;
    }

    public static void main(String[] args){
        Main myObj = new Main();
        System.out.println(myObj.x);
    }
}
