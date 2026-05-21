import com.suraj.algorithms.datastructures.DynamicArray;

public class Main {
    static void main() {
        Point p1 = new Point(1,2);
        Point p2 = new Point(3,4);
        DynamicArray<Point> pointArray = new DynamicArray<>(5);
        pointArray.add(p1);
        pointArray.add(p2);
        pointArray.remove(p1);
        for (int i = 0; i < pointArray.size(); i++){
            System.out.println(pointArray.get(i));
        }
    }
}

class Point {
    public int x;
    public int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "x: " + x + ", y: " + y;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }

        Point point = (Point) obj;

        return x == point.x && y == point.y;
    }
}