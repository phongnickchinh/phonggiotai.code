#include<bits/stdc++.h>
using namespace std;

#define N 50
//các test tuần 2 giống hệt môn thuật toán ứng dụng mình đang học
int n; // Độ dài của số nhị phân
int x[N]; // Mảng lưu kết quả

void solution(){
    for (int i = 1; i <= n; i++) {
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int k){


        for (int v = 0; v <= 1; v++) {
         x[k] = v;
        if (k == n) {
            solution();
        } else {
            Try(k + 1);}
    }
}
int main (){
    cin >> n;
    Try(1); // Gọi hàm Try với k = 1 để bắt đầu từ vị trí đầu tiên
    return 0;
}
