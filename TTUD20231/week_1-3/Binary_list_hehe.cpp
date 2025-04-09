#include<bits/stdc++.h>
using namespace std;

#define N 50

int n; // Độ dài của số nhị phân
int x[N]; // Mảng lưu kết quả


int check(int v, int k){
    // if(v==1 && (k%2==1)) return 0;
    return 1;
}

void solution(){
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void genBinary(int k){
    for (int v = 0; v <= 1; v++) {
        if(check(v, k)){
            x[k] = v;
            if (k == n) {
                solution();
            } else {
                genBinary(k + 1);
            }
        }
    }

}

int main (){
    cin >> n;
    genBinary(1); // Gọi hàm genBinary với k = 1 để bắt đầu từ vị trí đầu tiên
    return 0;
}
