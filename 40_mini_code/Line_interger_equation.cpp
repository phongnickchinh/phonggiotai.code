#include<bits/stdc++.h>
using namespace std;

int n, M;
vector<int> Elements;

void solution(){
     for (unsigned int i = 0; i < Elements.size(); i++) {
                cout << Elements[i];
                cout << " ";
            }
            cout << endl;
}

void Try(int soluong, int Tong){
    if(soluong==0){
        if(Tong==0) solution();
        return;
    }else{
        for (int i = 1; i <=Tong; i++){
            if(i<=Tong){
                Elements.push_back(i);
                Try(soluong-1,Tong-i);
                Elements.pop_back();
            }    
        }     
    }
    
}
int main(){
cin>>n>>M;
Try(n,M);
return 0;
}