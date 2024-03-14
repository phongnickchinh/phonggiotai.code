package exercise2;

public class Vector {
    //include x y z
    private double x;
    private double y;
    private double z;

    public Vector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    //getters and setters
    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    //sum 2 vecto
    public Vector sum(Vector vector) {
        return new Vector(this.x + vector.x, this.y + vector.y, this.z + vector.z);
    }
    //sub 2 vecto
    public Vector sub(Vector vector) {
        return new Vector(this.x - vector.x, this.y - vector.y, this.z - vector.z);
    }

    //multiply 2 vecto
    public double dotProduct(Vector vector) {
        return this.x * vector.x + this.y * vector.y + this.z * vector.z;
    }

    //multiply with numbẻ
    public Vector multiply(double number) {
        return new Vector(this.x * number, this.y * number, this.z * number);
    }
    
    
}
