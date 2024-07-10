#include <stdio.h>

// Hàm in ra giá trị 
void print(int n) {
    printf("n=%d\n", n);
}

// Hàm nhân 3 cộng 1
int mul3plus1(int n) {
    return n * 3 + 1;
}

// Hàm chia 2
int div2(int n) {
    return n / 2;
}

// Khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int)){
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main() {
    // Khởi tạo con trỏ hàm để chuẩn bị trỏ vào hàm
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;

    // Trỏ con trỏ vào hàm tương ứng
    odd = mul3plus1;
    even = div2;
    
    int n;
    scanf("%d", &n); // nhập số n
    simulate(n, odd, even, print); // tính, biến đổi về 1 và in ra

    return 0;
}