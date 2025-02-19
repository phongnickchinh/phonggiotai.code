#include<stdio.h>
void thapHN(int n, char first, char mid, char last){
if (n==1) {
printf("chuyen 1 dia tu %c den %c \n", first, last);
return;
}
thapHN(n-1, first, last, mid);
thapHN(1, first, mid, last);
thapHN(n-1,mid, first, last);
}

int main(){
int n;
scanf("%d", &n);
thapHN(n, 'A', 'B', 'C');
return 0;
}