#include<stdio.h>
#define MAX_N 21
int n;
int marked[MAX_N], rel[MAX_N];

int check(int v, int k){
    return !marked[v];
}

void solution (){
    for(int i=1; i<=n; i++){
        printf("%d ", rel[i]);
    }
    printf("\n");

}


void Try(int k){
    if(k==(n+1)){
        solution();
        return;
    }

    for(int i=1; i<=n; i++){
        if(check(i, k)){
            marked[i]=1;
            rel[k]=i;
            Try(k+1);
            marked[i]=0;
        }
    }
    return;

}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){

    }
    Try(1);
    return 0;
}