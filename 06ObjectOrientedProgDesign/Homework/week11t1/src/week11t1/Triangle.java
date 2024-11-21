package week11t1;
import java.util.Date;
import java.util.Scanner;

class Triangle extends GeometricObject{
	double side1 = 1;
	double side2 = 1;
	double side3 = 1;
	Triangle(){
		
	}
	Triangle(double side1, double side2, double side3){
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}
	double getSide1() {
		return this.side1;
	}
	double getSide2() {
		return this.side2;
	}
	double getSide3() {
		return this.side3;
	}
	double getArea() {
		double s = (this.side1 + this.side2 + this.side3)/2;
		return Math.sqrt(s*(s-this.side1)*(s-this.side2)*(s-this.side3));
	}
	double getPerimeter() {
		return this.side1 + this.side2 + this.side3;
	}
	public String toString() {
		return "Triangle: side1= "+ this.side1 + " side2 = " + this.side2 + " side3 = " + this.side3;
	}
	public static void main(String[] args) {
		System.out.print("Enter three sides: ");
		Scanner input = new Scanner(System.in);
		Triangle NT = new Triangle(input.nextDouble(), input.nextDouble(), input.nextDouble());
		System.out.println("Enter the color: ");
		NT.setcolor(input.next());
		System.out.println("Enter a boolean value for filled: ");
		NT.setFilled(input.nextBoolean());
		System.out.println(NT.toString());
		System.out.println("The area is " + NT.getArea());
		System.out.println("The perimeter is " +  NT.getPerimeter());
		System.out.println("The color is " + NT.getcolor());
		System.out.println("Is it filled? " + NT.isFilled());
		input.close();
	}
}

class GeometricObject {
	String color;
	boolean filled;
	Date dateCreated;
	GeometricObject(){
		
	}
	GeometricObject(String color, boolean filled) {
		this.color = color;
		this.filled = filled;
	}
	String getcolor() {
		return this.color;
	}
	void setcolor(String color) {
		this.color = color;
	}
	boolean isFilled() {
		return this.filled;
	}
	void setFilled(boolean filled) {
		this.filled = filled;
	}
	Date getDateCreated() {
		return this.dateCreated;
	}
	public String toString() {
		return "GeometricObject: color = " + this.color + " filled = " + this.filled;
	}
}