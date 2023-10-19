#include<bits/stdc++.h>
using namespace std;

#define N 50

int n; // Độ dài của số nhị phân
int x[N]; // Mảng lưu kết quả
bool mark[N];

void solution(){
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int k){
    for (int v = 1; v <= n; v++) { 
        if(!mark[v]) {
            x[k]=v;
            mark[v]=true;
        
        if (k == n) {
            solution();
        } else {
            Try(k + 1);    
        }
        mark[v]=false;
        }
    }
}

int main (){
    cin >> n;

    Try(1); // Gọi hàm Try với k = 1 để bắt đầu từ vị trí đầu tiên
    return 0;
}
