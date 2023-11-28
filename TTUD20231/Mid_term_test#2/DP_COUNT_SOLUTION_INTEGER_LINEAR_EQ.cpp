#include<bits/stdc++.h>
using namespace std;

//bài toán: đếm số cách để tạo ra số m từ tổng n số nguyên dương a1,a2,...,an
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n;i++){
        scanf("%d", &a[i]);
    }
    int dynamicList[10001]={0};
    dynamicList[0]=1;
    for(int i=0; i<n;i++){
        for(int j=a[i]; j<=m;j++){
            dynamicList[j]+=dynamicList[j-a[i]];
        }
    }
    cout<<dynamicList[m];
    return 0;
}