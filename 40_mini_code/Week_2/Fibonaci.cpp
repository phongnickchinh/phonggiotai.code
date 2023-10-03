#include<bits/stdc++.h>

using namespace std;

//đệ quy không nhớ để xử lí số thứ n-1
int so_thu (int number){

    if(number==0) return 0;
    if(number==1) return 1;
    if(number>1) return so_thu(number-1)+so_thu(number-2);
}
int main(){
int number;
scanf("%d", &number);
cout<<so_thu(number-1);
return 0;
}