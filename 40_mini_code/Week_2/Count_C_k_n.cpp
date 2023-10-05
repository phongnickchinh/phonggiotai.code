#include<bits/stdc++.h>
using namespace std;
#define N 1000
const int MOD = 1e9 + 7;
int Remember_ar[N][N];


//Hàm tính giá trị của C(k,n) thông qua tính các giá trị tăng dần từ C(0,0) được lưu vào Remember_ar
void C_k_n( int k, int n){

for (int i = 0; i <=n; i++){
    Remember_ar[0][i]=1; 
}
    for (int i = 1; i <=n; i++){
        while (k<=i){
            if(k==i) Remember_ar[k][i]=1;
            else if(k!=i&&k==1) Remember_ar[k][i]=i;
            //Thấy mn bảo lấy dư thì lấy chứ vẫn không hiểu sao lại lấy dư
            else Remember_ar[k][i]=(Remember_ar[k-1][i-1]+Remember_ar[k][i-1]) % MOD;
        k++;
        }
    k=1;
    }
    
}
void in_ra(int k, int n){
    cout<<Remember_ar[k][n];
}
int main(){
    int k,n;
    cin>>k>>n;
    C_k_n(k,n);
    in_ra(k,n);
    return 0;
}