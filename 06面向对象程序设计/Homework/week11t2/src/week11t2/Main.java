package week11t2;
import java.util.Date;
class Person{
	String name;
	String address;
	String phoneNumber;
	String email;
	public String toString() {
		return "Person " + this.name;
	}
}
class Student extends Person {
	int FRESHMAN;
	int SOPHOMORE;
	int JUNIOR;
	int SENIOR;
	int status;
	public String toString() {
		return "Student " + this.name;
	}
}
class MyDate{
//	Sorry I forget how to write MyDate in week 6, and there is a simple demo; 
	Date date;
	MyDate(){
		date = new Date();
	}
}
class Employee extends Person {
	String office;
	int salary;
	MyDate dateHaired;
	public String toString() {
		return "Employee " + this.name;
	}
}
class Faculty extends Employee {
	int LECTURER;
	int ASSISTANT_PROFESSOR;
	int ASSOCIATE_PROFESSOR;
	int PROFESSOR;
	String officeHours;
	int rank;
	public String toString() {
		return "Faculty " + this.name;
	}
}
class Staff extends Employee {
	String title = "director";
	public String toString() {
		return "Staff "+ this.name + "'s thtle is " + this.title ;
	}
}
public class Main {
	public static void main(String[] args) {
		Person Jack = new Person();
		Student Tom = new Student();
		Employee Jim = new Employee();
		Faculty Mark = new Faculty();
		Staff Susie = new Staff();
		Jack.name = "Jack";
		Tom.name = "Tom";
		Jim.name = "Jim";
		Mark.name = "Mark";
		Susie.name = "Susie";
		System.out.print(Jack.toString() +"\n"+ Tom.toString() +"\n"+ Jim.toString() +"\n"+ Mark.toString() +"\n"+ Susie.toString()+"\n");
	}
}
