#include<iostream>
#include<vector>
#include<list>
#include<queue>
#define p(i, j) adj[i].push_back(j);
using namespace std;
/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    for(int j=0; j < (int)adj.size(); ++j){
        visited[j] = true;
    }
    Q.push(1); // Bắt đầu từ đỉnh số 1
    visited[1] = false;
    cout << 1 << endl;
    int i=1, temp;
    while(Q.size() || !adj[1].empty()){
        if(adj[i].empty()){
            Q.pop();
            i = Q.front(); 
        }
        else{
            temp = adj[i].front();
            adj[i].pop_front();
            if(visited[temp]){
                cout << temp << endl;
                visited[temp] = false;
                Q.push(temp);
            }
        }
    }
}

int main(){
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    // adj[1].push_back(2);
    p(1,2);
    p(1,3);
    p(2,3);
    p(2,5);
    p(3,7);
    p(5,7);
    p(7,1);
    bfs(adj);
}