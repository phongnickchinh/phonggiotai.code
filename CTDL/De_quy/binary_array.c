#include<stdio.h>

#define MAX_N 21
int result[MAX_N];
int n;

void solution(){
    for(int i=1; i<=n; i++){
        printf("%d", result[i]);
    }
    printf("\n");
}

void Try(int k){
    if(k==(n+1)){
        solution();
        return;
    }
    for(int i=0; i<=1; i++){
        result[k]=i;
        Try(k+1);
    }
    result[k]=0;
    return;
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}