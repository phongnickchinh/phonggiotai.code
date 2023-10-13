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

// Tìm kiếm các xâu nhị phân độ dài n, bằng cách thử từng vị trí k<=n:
void Try(int k){

        //Mỗi vị trí chỉ có 2 cách chọn 0 hoặc 1:
        for (int v = 0; v <= 1; v++) {
         x[k] = v;
        if (k == n) {
            solution(); //in ra kết quả khi hoàn tất 1 nhánh
        } else {
            Try(k + 1);} //quay lui
    }
}
int main (){
    cin >> n;//nhập vào độ dài xâu nhị phân
    Try(1); // Gọi hàm Try với k = 1 để bắt đầu từ vị trí đầu tiên
    return 0;
}
