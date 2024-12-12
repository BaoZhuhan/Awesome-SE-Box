//import package.name.Class;
//import package.name.*;
package JAVA.JavaClass.JavaPackage;

import java.util.Scanner;
class MyClass {
    public static void main(String[] args) {
      Scanner myObj = new Scanner(System.in);
      System.out.println("Enter username");
  
      String userName = myObj.nextLine();
      System.out.println("Username is: " + userName);
    }
  }
