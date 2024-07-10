#include<stdio.h>
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
int main(){
    int n, m, i, *j, *k, temp, begin, *end, xr = 0;
    freopen("b11_case4.txt", "r", stdin);
    // Nhập m, n và các giá trị
    scanf("%d", &n);
    int n1 = n + 1, a[n1];
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    int m1 = m + 1, b[m1], nm1 = n + m + 1;
    for(i = 0; i < m1; i++)
        scanf("%d", &b[i]);
    
    // Nhân lần lượt các giá trị theo thứ tự tích có mũ từ nhỏ đến lớn và lưu vào biến temp sau đó xor với xr.
    for(i = 0; i < nm1; i++){
        temp = 0;
        if(i > m)
            begin = i - m;
        else
            begin = 0;
        if(i > n)
            end = a + n1;
        else
            end = a + i + 1;
        k = b + i - begin;
        
        for(j = a + begin; j < end; j++){
            temp += *j * *k;
            k--;
        }
        xr ^= temp;
    }

    printf("%d\n", xr);
}