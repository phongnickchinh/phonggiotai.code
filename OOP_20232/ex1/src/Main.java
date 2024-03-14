import exercise1.*;
import exercise2.*;
import exercise3.*;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        //chạy ex1
        System.out.println("Chạy ex1");
        //tạo 2 đối tượng
        Square HinhVuongTest = new Square(5);
        Cricle HinhTronTest = new Cricle(5);
        //in ra diện tích
        System.out.println("Diện tích hình vuông: " + HinhVuongTest.getArea());
        System.out.println("Diện tích hình tròn: " + HinhTronTest.getArea());

        //chạy ex2
        System.out.println("Chạy ex2");
        //tạo 2 đối tượng từ nhập vào
        Vector vector1 = new Vector(1, 2, 3);
        Vector vector2 = new Vector(4, 5, 6);

        //in ra tổng, hiệu, tích vô hướng, nhân với số
        System.out.println("Tổng 2 vecto: " + vector1.sum(vector2).getX() + " " + vector1.sum(vector2).getY() + " " + vector1.sum(vector2).getZ());
        System.out.println("Hiệu 2 vecto: " + vector1.sub(vector2).getX() + " " + vector1.sub(vector2).getY() + " " + vector1.sub(vector2).getZ());
        System.out.println("Tích vô hướng 2 vecto: " + vector1.dotProduct(vector2));
        System.out.println("Nhân 1 vecto với 1 số: " + vector1.multiply(2).getX() + " " + vector1.multiply(2).getY() + " " + vector1.multiply(2).getZ());

        //chạy ex3
        System.out.println("Chạy ex3");
        //tạo 1 đối tượng
        NhanVien NhanVienTest = new NhanVien("Phạm Văn Phong", 100000000, 7, 1000000000);
        //in ra thông tin
        NhanVienTest.inThongTin();
        //tăng lương
        NhanVienTest.tangLuong(1);
        //in ra thông tin
        NhanVienTest.inThongTin();

    }
}
