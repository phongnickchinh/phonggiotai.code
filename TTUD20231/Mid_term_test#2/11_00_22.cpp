#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

long long din_list[3][1001];
//bài toán đếm số cách xây dựng một dãy n số 0,1,2 sao cho không có 00 hoặc 11 liên tiếp
int main(){
    int n;
    cin>>n;
    din_list[0][1]=1;
    din_list[1][1]=1;
    din_list[2][1]=1;
    //xây dựng bảng quy hoạch động:
    //cột 0: số cách xây dựng dãy n số kết thúc bằng 0
    //cột 1: số cách xây dựng dãy n số kết thúc bằng 1
    //cột 2: số cách xây dựng dãy n số kết thúc bằng 2
    // các cột tiêsp theo tuân theo công thức:
    // din_list[0][i]=(din_list[1][i-1]+din_list[2][i-1])%MOD;
    for(int i=2; i<=n;i++){
        din_list[0][i]=(din_list[1][i-1]+din_list[2][i-1])%MOD;
        din_list[1][i]=(din_list[0][i-1]+din_list[2][i-1])%MOD;
        din_list[2][i]=(din_list[0][i-1]+din_list[1][i-1]+din_list[2][i-1])%MOD;
    }
    //kết quả là tổng các cột thứ n:
    cout<<(din_list[0][n]+din_list[1][n]+din_list[2][n])%MOD;
    return 0;
    

}