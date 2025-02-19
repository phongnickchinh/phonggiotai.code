#include<stdio.h>
int remeber[1000][1000];
int C(int k, int n){

if(n==k) return 1;
if(k==0) return 1;
return C(k-1, n-1) +C(k,n-1);
}

int main(){
int n, k;
scanf("%d%d", &k, &n);
printf("%d", C(k, n));
return 0;
}