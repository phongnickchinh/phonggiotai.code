package ex2.exsecise1;
import java.util.Scanner;
public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Nhap so luong sinh vien:");
        int N = scanner.nextInt();
        Student[] cls = new Student[N];

        for (int i = 0; i < N; i++) {
            System.out.println("Nhap sinh vien thu " + (i + 1));
            System.out.println("Ten: ");
            String name = scanner.next();
            System.out.println("Nam sinh: ");
            int year = scanner.nextInt();
            cls[i] = new Student(name, year);
        }
        scanner.close();

        int totalAge = 0;
        System.out.println("Danh sach sinh vien: ");
        for (int i = 0; i < N; i++) {
            totalAge += 2012 - cls[i].getYear();
            System.out.println(cls[i].getName());
        }
        System.out.println("Tong so tuoi: " + totalAge);
    }
}
