package ex2.exsecise2;

public class NhanVien {
    String tenNhanVien;
    double luongCoBan;
    double heSoLuong;
    double LUONG_MAX;

    //constructor
    public NhanVien(String tenNhanVien, double luongCoBan, double heSoLuong, double LUONG_MAX) {
        this.tenNhanVien = tenNhanVien;
        this.luongCoBan = luongCoBan;
        this.heSoLuong = heSoLuong;
        this.LUONG_MAX = LUONG_MAX;
    }

    //getters and setters
    public String getTenNhanVien() {
        return tenNhanVien;
    }
    public void setTenNhanVien(String tenNhanVien) {
        this.tenNhanVien = tenNhanVien;
    }
    public double getLuongCoBan() {
        return luongCoBan;
    }
    public void setLuongCoBan(double luongCoBan) {
        this.luongCoBan = luongCoBan;
    }
    public double getHeSoLuong() {
        return heSoLuong;
    }
    public void setHeSoLuong(double heSoLuong) {
        this.heSoLuong = heSoLuong;
    }
    public double getLUONG_MAX() {
        return LUONG_MAX;
    }
    public void setLUONG_MAX(double LUONG_MAX) {
        this.LUONG_MAX = LUONG_MAX;
    }

    //tinh luong
    public double tinhLuong() {
        return luongCoBan * heSoLuong;
    }
    //tang luong
    public boolean tangLuong(double tangThem) {
        heSoLuong += tangThem;
        if (tinhLuong() > LUONG_MAX) {
            heSoLuong -= tangThem;
            return false;
        }
        return true;
    }
    //in thong tin
    public void inThongTin() {
        System.out.println("Ten nhan vien: " + tenNhanVien);
        System.out.println("Luong co ban: " + luongCoBan);
        System.out.println("He so luong: " + heSoLuong);
        System.out.println("Luong: " + tinhLuong());
    }
}
