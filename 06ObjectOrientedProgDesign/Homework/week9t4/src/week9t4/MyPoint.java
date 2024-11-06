package week9t4;

public class MyPoint {
	double x = 0;
	double y = 0;
	MyPoint(){
		
	}
	MyPoint(double x, double y){
		this.x = x;
		this.y = y;
	}
	double getX() {return x;}
	double getY() {return y;}
	static double distance(MyPoint a, MyPoint b) {
		return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y,2));
	}
	double distance(MyPoint b) {
		return Math.sqrt(Math.pow(b.x-this.x,2) + Math.pow(b.y - this.y,2));
	}
	public static void main(String[] args) {
		MyPoint p1 = new MyPoint(0,0);
		MyPoint p2 = new MyPoint(10,30.5);
		System.out.println(p1.distance(p2));
		System.out.println(MyPoint.distance(p1, p2));
	}
}
