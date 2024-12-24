import java.util.Scanner;

public class Triangle extends GeometricObject {
  double side1;
  double side2;
  double side3;

  public Triangle(double side1, double side2, double side3, String color, boolean filled) {
    super(color, filled);
    this.side1 = side1;
    this.side2 = side2;
    this.side3 = side3;
  }

  @Override
  public double getArea() {
    double s = (side1 + side2 + side3) / 2;
    return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
  }

  @Override
  public double getPerimeter() {
    return side1 + side2 + side3;
  }

  @Override
  public String toString() {
    return "三角形面积是 " + this.getArea() + "\n三角形周长是 " + this.getPerimeter() + "\n三角形颜色是 " + this.getColor() + "\n三角形是否填充 "
        + this.isFilled();
  }

  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    System.out.println("请输入三角形的颜色: ");
    String c = input.nextLine();
    System.out.println("请输入三条边：");
    double s1 = input.nextDouble();
    double s2 = input.nextDouble();
    double s3 = input.nextDouble();
    System.out.println("三角形是否填充（ True 或 False ）");
    boolean f = input.nextBoolean();
    Triangle ob = new Triangle(s1, s2, s3, c, f);
    System.out.print(ob.toString());
    input.close();
  }
}
