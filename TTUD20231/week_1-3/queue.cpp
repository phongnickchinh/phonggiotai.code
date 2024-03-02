#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> number_list;

int main(){
    string key;
    while(true){
        scanf("%s", &key);
        if(key=="#") break;
        if(key=="PUSH"){
            int n;
            scanf("%d", &n);
            number_list.push(n);
        }
        if(key=="POP"){
            printf("%d\n", number_list.top());
            number_list.pop();
        }
    }
    return 0;
}
