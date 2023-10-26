#include<bits/stdc++.h>
using namespace std;
#define  m (int)(1e9+7)

//Tìm kiếm số kết quả bằng Dynamite_programing:
int solution(int n, int k1, int k2){

//2 danh sách lưu các bài toán con tăng dần đối với mỗi trường hợp 1 đúng cuối
//và 0 đứng cuối:
vector<int> s_1(n+1);
vector<int> s_0(n+1);

//thiết lập các giá trị ban đầu mà không thể chạy bằng công thức truy hồi:
for(int i=1; i<k1;i++) s_1[i]=0;
s_1[k1]=1;
for(int i=k1+1;i<=k2;i++) s_1[i]=2;

s_0[1]=1;
s_0[k1+1]=1;
for(int i=k1+2;i<=k2; i++) s_0[i]=2;
for(int i=2; i<k1+1;i++) s_0[i]=0;

//sử dụng công thức truy hồi để tính các giá trị tiếp theo:
for(int i=k2+1; i<=n;i++){
    for(int j=i-k2;j<=i-k1; j++) s_1[i]+=s_0[j];
    s_0[i]=s_1[i-1];
}
return (s_0[n]+s_1[n]);
}
int main(){
    int n,  k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    cout<<solution(n, k1, k2);
    return 0;
}