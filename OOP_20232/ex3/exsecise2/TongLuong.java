package ex3.exsecise2;
import ex3.exsecise1.NhanVien;

import java.util.List;
public class TongLuong {
    public static double tongLuong(List< NhanVien> nhanViens, int numbers) {
        double sum = 0;
        for (int i = 0; i < numbers; i++) {
            sum += nhanViens.get(i).tinhLuong();
        }
        return sum;
    }
}