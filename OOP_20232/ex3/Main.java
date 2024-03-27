package ex3;
import ex3.exsecise1.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import ex3.exsecise2.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Tạo một danh sách các nhân viên
        List<NhanVien> nhanViens = new ArrayList<>();
        nhanViens.add(new NhanVien("Pham Van Phong", 10000000, 7, 1000000000));
        nhanViens.add(new NhanVien("Nguyen Van A", 10000000, 7, 1000000000));
        nhanViens.add(new NhanVien("Tran Van B", 10000000, 7, 1000000000));
        System.out.println("Bai tap 1:");
        System.out.println("ban đau co: " + NhanVien.getCount() + " nhan vien");

        //bài 1
        int choice;
        do {
            System.out.println("Nhap 1 de them nhan vien, 2 de xoa nhan vien, 0 de thoat: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // consume newline left-over
            if (choice == 1) {
                System.out.println("Nhap ten nhan vien: ");
                String tenNhanVien = scanner.nextLine();
                System.out.println("Nhap luong co ban: ");
                double luongCoBan = scanner.nextDouble();
                System.out.println("Nhap he so luong: ");
                double heSoLuong = scanner.nextDouble();
                System.out.println("Nhap luong toi da: ");
                double LUONG_MAX = scanner.nextDouble();
                nhanViens.add(new NhanVien(tenNhanVien, luongCoBan, heSoLuong, LUONG_MAX));
                System.out.println("So luong nhan vien trong danh sach: " + NhanVien.getCount());
            } else if (choice == 2) {
                nhanViens.remove(0);
                System.out.println("So luong nhan vien trong danh sach sau khi xoa: " + NhanVien.getCount());
            } else if (choice != 0) {
                System.out.println("Lua chon khong hop le!");
            }
        } while (choice != 0);



        //bài 2 tính tổng lương của n phần tử đầu
        System.out.println("\n\n\nBai tap 2:");
        System.out.println("Nhap so luong nhan vien muon tinh tong luong: ");
        int n = scanner.nextInt();
        double tongLuong = TongLuong.tongLuong(nhanViens, n);
        System.out.println("Tong luong cua " + n + " nhan vien dau tien: " + tongLuong);

        //bài 3
        System.out.println("\n\n\nBai tap 3:");
        System.out.println("Nhap so lan lap: ");
        int soLanLap = scanner.nextInt();
        System.out.println("Nhap xau can lap: ");
        String xau = scanner.next();
        long startTime = System.currentTimeMillis();
        String result = "";
        for (int i = 0; i < soLanLap; i++) {
            result += xau;
        }
        long endTime = System.currentTimeMillis();
        System.out.println("Thoi gian thuc hien voi String: " + (endTime - startTime) + "ms");
        scanner.close();

    }

}



