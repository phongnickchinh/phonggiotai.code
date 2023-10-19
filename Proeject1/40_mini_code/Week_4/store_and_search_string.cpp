#include<bits/stdc++.h>
using namespace std;

int main(){
    //Sử dụng set để lưu trữ dữ liệu không trùng lặp
    set<string> list;
    string word;
    string command;
    while(true){
        cin>>word;
        if(word=="*") break;
        list.insert(word);
    }

    while(true){
        cin>>command;
        if(command=="***") break;

        if(command=="find"){
            cin>>word;
            if(list.find(word)!=list.end()) cout<<"1"<<endl;
            else cout<<"0"<<endl;  
        }

        if(command=="insert"){
            cin>>word;
            if(list.find(word)==list.end()){
                list.insert(word);
                cout<<"1"<<endl;
            }else cout<<"0"<<endl;
        }
    }
    return 0;
}