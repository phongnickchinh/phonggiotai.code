#include<stdio.h>
int sol[1000];
int num_of_sol;

//không có 2 số 0 đứng cạnh nhau:
int check(int i,int k){
	if(i==1||k==0) return 1;
    if(sol[k-1]==0) return 0;
}
void solution(int k){
    num_of_sol++;
    for (int i=0; i<k; i++ ) printf("%d", sol[i]);
    printf("\n");
    return;
}
void Try(int k,int n){
	for(int i=0; i<=1; i++){
		if(check(i,k)){
			sol[k]=i;
			if(k==n) solution(k);
			else Try(k+1, n);
		}
	}
}

int main(){
    int k=0;
    int n=10;
    Try(k,n);
    printf("%d", num_of_sol);
    return 0;
}