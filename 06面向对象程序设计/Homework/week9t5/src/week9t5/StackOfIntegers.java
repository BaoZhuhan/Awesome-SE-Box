package week9t5;
import java.util.Scanner;
public class StackOfIntegers {
    private int[] elements;
    private int size;
    private static final int DEFAULT_CAPACITY = 16;

    public StackOfIntegers() {
        this(DEFAULT_CAPACITY);
    }

    public StackOfIntegers(int capacity) {
        elements = new int[capacity];
    }

    public void push(int value) {
        if (size >= elements.length) {
            int[] temp = new int[elements.length * 2];
            System.arraycopy(elements, 0, temp, 0, elements.length);
            elements = temp;
        }
        elements[size++] = value;
    }
    public int pop() {
        return elements[--size];
    }

    public int peek() {
        return elements[size - 1];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int getSize() {
        return size;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int number = input.nextInt();

        StackOfIntegers stack = getFactors(number);

        System.out.println("The factors for " + number + " is");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    public static StackOfIntegers getFactors(int number) {
        StackOfIntegers stack = new StackOfIntegers();
        int factor = 2;

        while (number != 1) {
            if (number % factor == 0) {
                stack.push(factor);
                number /= factor;
            } else {
                factor++;
            }
        }

        return stack;
    }
}
