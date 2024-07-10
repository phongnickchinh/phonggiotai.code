/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/

#include<iostream>

using namespace std;

int main(){
    int n, k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);

    int n1 = n+1, a[n1] = {}, t = 0, p = 2;
    while(p > -1){
        
        if(p == n1){
            t = 1;
            if(a[--p]>0 && a[p]<k1)
                continue;
            for(int i=1; i<n1; ++i){
                if(a[i] != 0)
                    printf("1");
                else
                    printf("0");
            }   printf("\n");
        }
        
        if(t == 0){
            if(a[p-1] < k1){
                a[p] = a[p-1] + 1;
                ++p;
            }
            else
                a[p++] = 0;
        }
        else{
            ++p;
            while(--p > -1)
                if(a[p] == 0  &&  a[p-1] < k2){
                        a[p] = a[p-1] + 1;
                        ++p;
                        t = 0;
                        break;
                    }
        }
        
    }
}