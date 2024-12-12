package week9t2;

public class BMI {
    private String name;
    private int age;
    private double weight;
    private double height;
    private double bmi;

    public BMI(String name, double weight, double height) {
        this.name = name;
        this.weight = weight;
        this.height = height;
        calculateBMI();
    }

    public BMI(String name, int age, double weight, double feet, double inches) {
        this.name = name;
        this.age = age;
        this.weight = weight;
        this.height = feet * 12 + inches;
        calculateBMI();
    }

    private void calculateBMI() {
        this.bmi = weight * 703 / (height * height);
    }

    public double getBMI() {
        return bmi;
    }

    public String getStatus() {
        if (bmi < 18.5)
            return "体重过轻";
        else if (bmi < 25)
            return "正常体重";
        else if (bmi < 30)
            return "超重";
        else
            return "严重超重";
    }

    public String getName() {
        return name;
    }
    
    public static void main(String[] args) {
    	BMI bmi1 = new BMI("Johe Doe", 18, 145, 5, 10);
    	BMI bmi2 = new BMI("Peter King", 215, 70);
    	System.out.println(bmi1.getName() + "的BMI是" + String.format("%.2f", bmi1.getBMI()) + "," + bmi1.getStatus());
    	System.out.println(bmi2.getName() + "的BMI是" + String.format("%.2f",bmi2.getBMI()) + "," + bmi2.getStatus());
    }
}
