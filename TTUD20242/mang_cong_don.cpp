#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> preprocess;
    vector<int> value;
    int n,m,l,r;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>value[i];
    }
    for(int i=0; i<n; i++){
        if(i==0) preprocess[i]=value[i];
        else{
            preprocess[i]=preprocess[i-1]+value[i];
        }
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>l>>r;
        cout<<preprocess[r-1]- preprocess[l-1];   
    }
    return 0;

}