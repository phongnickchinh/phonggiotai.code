#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1000
vector<int> elements(MAX_N+1);

int _s=0, total=0;
int n, M;
void Try(int k){
    if(k==n+1){
        if(total==M) _s++;
        return;
    }
    for(int i=1; i<=M; i++ ){
        total+=i*elements[k];
        if(total<=M)Try(k+1);
        total-=i*elements[k];
    }
}

int main(){
    cin>>n>>M;
    for(int i=1; i<=n; i++){
        cin>>elements[i];
    }
    Try(1);
    cout<<_s;
    return 0;
}
