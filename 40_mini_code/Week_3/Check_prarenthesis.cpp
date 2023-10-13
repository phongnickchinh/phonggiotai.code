#include<bits/stdc++.h>
using namespace std;

int check(string x){
    int tron_trai=0,tron_phai=0, vuong_trai=0, vuong_phai=0, nhon_trai=0, nhon_phai=0;
    for (unsigned int i=0; i<=x.size();i++){
        if(x[i]=='(')tron_trai++;
        if(x[i]==')') tron_phai++;
        if(x[i]=='[') vuong_trai++;
        if(x[i]==']') vuong_phai++;
        if(x[i]=='{') nhon_trai++;
        if(x[i]=='}') nhon_phai++;
    }
    /*cout<<tron_trai<<" "<<tron_phai<<endl;
    cout<<vuong_trai<< " "<<vuong_phai<<endl;
    cout<<nhon_trai<<" "<<nhon_phai<<endl;*/
    if(tron_trai!=tron_phai) return 0;
    if(vuong_phai!=vuong_trai) return 0;
    if(nhon_trai!=nhon_phai) return 0;
    return 1;
}
int main(){
  
    string input;
    cin>>input;
    cout<<check(input);
    return 0;
    
    
    
}