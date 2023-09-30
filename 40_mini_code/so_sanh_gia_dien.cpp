    #include <iostream>
    using namespace std;

    double tien_dien_cu(int cong_to) {
        double tien_dien = 0;
        int muc;
    if (cong_to==0) 
    {
        return 0;
    }

        // Tính tiền điện theo bảng giá cũ
        muc = cong_to - 50 > 0 ? 50 : cong_to;
        tien_dien += muc * 1728;
        cong_to -= 50;
        if(cong_to<=0) return tien_dien*1.1;

        muc = cong_to - 50 > 0 ? 50 : cong_to;
        tien_dien += muc * 1786;
        cong_to -= 50;
        if(cong_to<=0) return tien_dien*1.1;
        
        muc = cong_to - 100 > 0 ? 100 : cong_to;
        tien_dien += muc * 2074;
        cong_to -= 100;
        if(cong_to<=0) return tien_dien*1.1;
        
        muc = cong_to - 100 > 0 ? 100 : cong_to;
        tien_dien += muc * 2612;
        cong_to -= 100;
        if(cong_to<=0) return tien_dien*1.1;
        
        muc = cong_to - 100 > 0 ? 100 : cong_to;
        tien_dien += muc * 2919;
        cong_to -= 100;
        if(cong_to<=0) return tien_dien*1.1;
        
        tien_dien += cong_to * 3015;
        return tien_dien * 1.1;
    }

    double tien_dien_moi(int cong_to) {
        double tien_dien = 0;

        if (cong_to <= 0) {
            return 0.0; // Không tiêu thụ điện, trả về 0
        }

        int muc;

        // Tính tiền điện theo bảng giá mới
        muc = cong_to - 100 > 0 ? 100 : cong_to;
        tien_dien += muc * 1728;
        cong_to -= 100;
        if(cong_to<=0) return tien_dien*1.1;
               
        muc = cong_to - 100 > 0 ? 100 : cong_to;
        tien_dien += muc * 2074;
        cong_to -= 100;
        if(cong_to<=0) return tien_dien*1.1;
        
        muc = cong_to - 200 > 0 ? 200 : cong_to;
        tien_dien += muc * 2612;
        cong_to -= 200;
        if(cong_to<=0) return tien_dien*1.1;
               
        muc = cong_to - 300 > 0 ? 300 : cong_to;
        tien_dien += muc * 3111;
        cong_to -= 300;
        if(cong_to<=0) return tien_dien*1.1;
        
        tien_dien += cong_to * 3457;
        return tien_dien * 1.1;
    }

    int main() {
        unsigned int cong_to;
        cin >> cong_to;

        double chenh_lech = tien_dien_moi(cong_to) - tien_dien_cu(cong_to);

        printf("%.2f", chenh_lech);

        return 0;
    }
