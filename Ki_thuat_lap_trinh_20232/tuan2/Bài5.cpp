#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/

// Cấu trúc số phức
struct Complex {
    double real;
    double imag;
};

// Đa năng hóa phép '+'
Complex operator + (Complex a, Complex b) {
    Complex tong;
    tong.imag = a.imag + b.imag; // tổng phần ảo
    tong.real = a.real + b.real; // tổng phần thực
	return tong;
}

// Đa năng hóa phép '-'
Complex operator - (Complex a, Complex b) {
    Complex hieu;
    hieu.imag = a.imag - b.imag; // hiệu phần ảo
    hieu.real = a.real - b.real; // hiệu phần thực
    return hieu;
}

// Đa năng hóa phép '*'
Complex operator * (Complex a, Complex b) {
    Complex tich;
    tich.imag = a.imag*b.real + a.real*b.imag; // tính phần ảo của tích
    tich.real = a.real*b.real - a.imag*b.imag; // tính phần thực của tích
    return tich;
}

// Đa năng hóa phép '/'
Complex operator / (Complex a, Complex b) {
    Complex thuong;
    float a0 = b.real, a1 = a.real, b0 = b.imag, b1 = a.imag;
	thuong.imag = (a0*b1-a1*b0)/(a0*a0 + b0*b0);  // tính phần ảo của thương bằng công thức
    thuong.real = (a1 + thuong.imag*b0)/a0; // tính phần thực của thương bằng công thức
    return thuong;
}

// Đa năng hóa toán tử '<<' để in số phức
ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    double real_a, real_b, img_a, img_b;
    // Nhập 2 số phức
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    // Lưu số phức theo cấu trúc trên
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    // Thực hiện các phép tính và in ra
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}