import java.util.ArrayList;

public class Main {
    public static void sort(ArrayList<Number> list) {
        int n = list.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (list.get(j).doubleValue() > list.get(j + 1).doubleValue()) {
                    Number temp = list.get(j);
                    list.set(j, list.get(j + 1));
                    list.set(j + 1, temp);
                }
            }
        }
        for (Number i : list) {
            System.out.print(i + " ");
        }
        System.out.print("\n");
    }

    public static void main(String[] args) throws Exception {
        ArrayList<Number> list = new ArrayList<Number>();
        list.add(5);
        list.add(4);
        list.add(24);
        list.add(42);
        list.add(14);
        sort(list);
    }
}
