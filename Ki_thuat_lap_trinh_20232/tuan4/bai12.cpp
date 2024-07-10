#include <bits/stdc++.h>
using namespace std;
/*
Author: Phạm Văn Phong,
MSSV: 20215448,
Mã lớp: 738919.
*/
int s[10000] = {};
int main(){
    int n, x, mx = 0, *p = s + 2;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        int st = 0;
        while(*p > x){
            st += *(p + 1);
            mx = max(mx, *p * st);
            p -= 2;
        }
        if(*p == x){
            *(p + 1) += ++st;
        }
        else{
            p += 2;
            *p = x;
            *(p + 1) = ++st;   
        }
    }
    while(*p){
        mx = max(mx, *p * *(p + 1));
        *(p - 1) += *(p + 1);
        p -= 2;
    }
    printf("%d", mx);
}