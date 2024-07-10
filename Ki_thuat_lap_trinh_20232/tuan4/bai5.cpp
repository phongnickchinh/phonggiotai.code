#include<iostream>
#include<vector>
#include<stack>
#include<list>
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
using namespace std;
void dfs(vector< list<int> > adj) {
    int i=1, temp;
    stack<int> S;
    vector<bool> visited(adj.size());
    for(int j=0; j < (int)adj.size(); ++j){
        visited[j] = true;
    }
    S.push(1); // Bắt đầu từ đỉnh số 1
    visited[1] = false;
    cout << "1" << endl;
    while(S.size() > 1 || !adj[1].empty()){
        if(adj[i].empty()){
            S.pop();
            i = S.top();
        }
        else{
            temp = adj[i].front();
            adj[i].pop_front();
            if(visited[temp]){
                visited[temp] = false;
                i = temp;
                S.push(i);
                cout << i << endl;
            }
        }
    }
}

int main(){
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}