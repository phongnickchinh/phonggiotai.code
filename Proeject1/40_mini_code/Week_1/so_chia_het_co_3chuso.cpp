#include<iostream>
using namespace std;

//tìm số có 3 chữ số chia hết cho n
void timsochiahet(int n){
    int sochiahet_dautien=0;
    if(n>=100) sochiahet_dautien=n;
    else {
        for (int i = 100; i < 199; i++){
            if(i%n==0) {sochiahet_dautien=i;
            break;}
        }
    }
    for (int i = sochiahet_dautien; i <=999; i+=n){
        cout<<i<<" ";   /* code */
    }
    
}

int main(){
    int n;
    cin>>n;
    timsochiahet(n);
    return 0;
}