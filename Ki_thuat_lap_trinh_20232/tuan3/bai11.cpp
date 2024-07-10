/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/

#include<iostream>

using namespace std;

int main(){
    int n, r;
    scanf("%d%d", &n, &r);

    int n1 = n + 1, s[n1][n1];
    for(int i = 1; i < n1; i++)
        for(int j = 1; j < n1; j++)
            scanf("%d", &s[i][j]);
    
    char a;
    scanf("%c", &a);
    while(--r > -1){    
        // x[n] luu danh sach dia diem, y[n] luu thu tu den, z[n] xem da den do chua
        // p tro toi vi tri xet, k luu so luong dia diem, i la ung vien cho vi tri
        // cp luu chi phi hien tai, min luu chi phi toi uu
        int x[n], y[n] = {0}, z[n] = {1}, i = 1, p = 0, k = 0, k1, cp, min = 1000000;

        // nhap du lieu
        while(1){
            scanf("%d", &x[k]);
            scanf("%c", &a);
            if(a == '\n')
                break;
            ++k;
        }
        k1 = k-1; y[k] = k;
        
        // tim min
        while(p > -1){
            // neu den diem k - 1
            if(p == k1){ 
                // xem co den duoc diem k khong
                if(s[x[y[p]]][x[k]] != 0){
                    cp = 0;
                    for(i=0; i<k; i++) 
                        cp += s[x[y[i]]][x[y[i+1]]];
                    if(cp < min) 
                        min = cp;
                }
                // tro lai buoc truoc do
                i = y[p] + 1;
                z[y[p--]] = 0;
            }

            // tim dia diem chua den
            for(i; i < k; ++i)
                if(z[i] == 0)
                    break;

            // neu khong co, tro lai buoc truoc
            if(i > k1){
                i = y[p] + 1;
                z[y[p--]] = 0;
                continue;
            }

            // thoa man, them dia diem do vao
            if(s[x[y[p]]][x[i]] != 0){
                y[++p] = i;
                z[i] = 1;
                i = 1;
            }
            else
                i += 1;
        }

        // in ra
        if(min == 1000000)
            printf("0\n");
        else
            printf("%d\n", min);
    }
}