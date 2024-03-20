package ex2.exsecise2;

public class TestNV {
    private NhanVien nv1;
    private NhanVien nv2;

    public TestNV(NhanVien nv1, NhanVien nv2) {
        this.nv1 = nv1;
        this.nv2 = nv2;
    }

    public void inThongTin() {
        System.out.println("Nhan vien 1: ");
        nv1.inThongTin();
        System.out.println("Nhan vien 2: ");
        nv2.inThongTin();
    }
    
    public static void main(String[] args) {
        //TẠO RA 2 ĐỐI TƯỢNG HAY HO
        NhanVien nv1 = new NhanVien("Pham Van Phong", 1000000, 2.0, 20000000);
        NhanVien nv2 = new NhanVien("Nguyen Thi Duyen", 2000000, 3.0, 30000000);
        TestNV test = new TestNV(nv1, nv2);
        test.inThongTin();
    }
}
