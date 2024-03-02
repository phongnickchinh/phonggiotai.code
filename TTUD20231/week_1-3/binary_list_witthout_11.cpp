#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> sequence;
void Solution(){
    for(int i=0; i<n; i++)printf("%d", sequence[i]);
    printf("\n");
}
void backtrack(int k){
    if(k>n){
        Solution();
        return;
    }else{
        for(int i=0; i<=1; i++){
            if(i==0){
                sequence.push_back(i);
                backtrack(k+1);
                sequence.pop_back();
            }else{
                if(sequence.back()==0 ||sequence.empty()){
                sequence.push_back(i);
                backtrack(k+1);
                sequence.pop_back();
                }
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    backtrack(1);
}

