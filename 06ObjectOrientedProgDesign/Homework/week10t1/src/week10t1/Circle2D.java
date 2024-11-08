package week10t1;

public class Circle2D {
	private double x = 0;
	private double y = 0;
	private double radius = 1;
	Circle2D(){
		
	}
	Circle2D(double x, double y, double radius){
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	double getX() { return x; }
	double getY() { return y; }
	double getRadius() { return radius; }
	void setX(double x) { this.x = x; }
	void setY(double y) { this.y = y; }
	void setRadius(double radius) { this.radius = radius; }
	double getPerimeter() { return Math.PI*2.0d*this.radius; }
	double getArea() { return Math.PI*this.radius*this.radius; }
	public static double distance(double x1, double x2, double y1, double y2) { return Math.sqrt(Math.pow((x1-x2),2)+Math.pow((y1-y2), 2));}
	boolean contains(double x, double y) {
		return distance(this.x, x, this.y, y) <= this.radius;
	}
	boolean contains(Circle2D circle) {
		return distance(this.x, circle.x, this.y ,circle.y) + circle.radius <= this.radius;
	}
	boolean overlaps(Circle2D circle) {
		return distance(this.x, circle.x, this.y, circle.y) < circle.radius + this.radius;
	}
	
	public static void main(String[] args) {
		Circle2D c1 = new Circle2D(2,2,5.5);
		System.out.println("Area is " + c1.getArea());
		System.out.println("Perimeter is " + c1.getPerimeter());
		System.out.println("c1 contains point(3,3)? " + c1.contains(3, 3));
		System.out.println("c1 contains circle Circle2D(4, 5, 10.5)? " + c1.contains(new Circle2D(4, 5, 10.5)));
		System.out.println("c1 overlaps circle Circle2D(3, 5, 2.3)? " + c1.overlaps(new Circle2D(3, 5, 2.3)));
		
	}
}
