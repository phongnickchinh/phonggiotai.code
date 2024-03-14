package exercise1;

public class Square {
    private double side;

    public Square(double side) {
        if (side <= 0) {
            throw new IllegalArgumentException("Side must be positive");
        }
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    public void setSide(double side) {
        if (side <= 0) {
            throw new IllegalArgumentException("Side must be positive");
        }
        this.side = side;
    }

    public double getArea() {
        return side * side;
    }

    public double getPerimeter() {
        return 4 * side;
    }
    
}
