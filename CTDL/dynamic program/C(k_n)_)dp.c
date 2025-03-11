#include<stdio.h>

#define MOD 1000000007

int pre[1000][1000];

void C_k_n(int n){

    for(int i=0; i<=n; i++){
        pre[0][i]=1;
    }

    for(int i=1; i<=n; i++){
        for(int k=1; k<=i; k++){
            if(k==i) pre[k][i]=1;
            else pre[k][i]=(pre[k-1][i-1]%MOD+pre[k][i-1]%MOD)%MOD;
        }
    }
}

void print(int k, int n){
    printf("%d", pre[k][n]);
}


int main(){
    int k, n;
    scanf("%d%d", &k, &n);
    C_k_n(n);
    print(k,n);
    return 0;
}