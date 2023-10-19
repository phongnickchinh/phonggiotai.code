#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> number_list;

int main(){
    string key;
    string ppp;
    while(cin>>key){
        if(key=="#") break;
        if(key=="PUSH"){
            int n;
            cin>>n;
            number_list.push(n);
        }
        if(key=="POP"){
            ppp.push_back(number_list.top());
            ppp.push_back("/n");
            number_list.pop();
        }
    }
}
