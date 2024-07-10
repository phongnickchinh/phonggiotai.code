/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/

#include<iostream>

using namespace std;

int main(){
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m); // nhap so nguyen n, k, m

    // p de tro toi thu tu dinh thu p dang xet
    int n1 = n+1, k1 = k+1, i, j, p = 0;
    // s[n][n] luu cac canh, x[] luu cac dinh di qua, y[] de biet dinh da di qua chua
    int s[n1+1][n1] = {}, x[k+1] = {}, y[n1] = {};

    // nhap cac canh
    for(m; m>0; --m){
        scanf("%d%d", &i, &j);
        s[i][j] = 1;
        s[j][i] = 1;
    }
    // tao 1 dinh gia lam diem bat dau
    for(i=1; i<n1; ++i)
        s[n1][i] = 1;
    x[0] = n1;

    // i de luu ung vien, j luu so luong duong di
    i = 0; j = 0;
    int c = 0;
    while(p > -1){
        // neu di duoc k dinh thi cong j them 1
        if(p == k1){
            j += 1;
            i = x[p] + 1;
            y[x[p--]] = 0;
        }
        
        // tim dinh chua den
        for(i; i < n1; ++i)
            if(y[i] == 0)
                break;

        // khong co diem thoa man, quay lai thu tu dinh truoc do
        if(i == n1){
            i = x[p] + 1;
            y[x[p--]] = 0;
            continue;
        }

        // neu den duoc diem i
        if(s[x[p]][i] != 0){
            x[++p] = i;
            y[i] = 1;
            i = 1;
        }
        // khong thi xet diem i + 1
        else
            i += 1;
    }
    // vi co hoan vi diem dau va diem cuoi nen chia 2
    printf("%d", j / 2);
}