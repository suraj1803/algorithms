import com.suraj.algorithms.datastructures.DynamicArray;

public class Main {
    static void main() {
        DynamicArray<String> pointArray = new DynamicArray<>(5);
        pointArray.add("hello");
        pointArray.add("hello");
        pointArray.forEach(point -> {
            System.out.println(point);
        });
        pointArray.remove("hello");
        System.out.println(pointArray.size());
    }
}
