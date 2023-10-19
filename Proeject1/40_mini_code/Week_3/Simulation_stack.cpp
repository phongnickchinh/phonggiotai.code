#include<bits/stdc++.h>
using namespace std;
stack<int> number_list;



int main(){
    string command;
    while(true){
        cin>>command;
        if(command=="#") break;
        if(command=="PUSH"){
            int n;
            cin>>n;
            number_list.push(n);
        }

        if(command=="POP"){
            if(number_list.empty()) cout<<"NULL"<<endl;
            else{
                cout<<number_list.top()<<endl;
                number_list.pop();
            }
        }
    }
}