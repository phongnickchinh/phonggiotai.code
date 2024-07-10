/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
#include<iostream>

using namespace std;

int main(){
    int t, n, h;
    scanf("%d", &t);
    // số case t
    while(--t>-1){
        scanf("%d%d", &n, &h);
        // p để trỏ tới vị trí đang xét, k để biết duyệt theo chiều thuận hay xuôi
        // a để lưu số số 0 còn lại, b để lưu số số 1 còn lại
        // s[n1] lưu chuỗi
        int p = 1, k = 0, a = n-h-1, b = h, n1 = n+1, s[n1] = {};

        while(p > 0){
            // in ra
            if(p==n1){
                for(int i=1; i<n1; i++)
                    printf("%d", s[i]);
                printf("\n");
                k = 1;
                b = 0;
            }
            
            // nếu duyệt chiều thuận
            if(k == 0)
                if(a>0){
                    s[++p] = 0;
                    --a;
                }
                else{ 
                    s[++p] = 1;
                    --b;
                }
            
            // nếu duyệt ngược lại 
            else{
                k = 0;
                while(--p > 0){
                    if(s[p] == 1)
                        ++b;
                    else
                        if(b > 0){
                            s[p] = 1;
                            ++a;
                            --b;
                            break;
                        }
                        else
                            ++a;
                }
            }
        }
        printf("\n");
    }
}