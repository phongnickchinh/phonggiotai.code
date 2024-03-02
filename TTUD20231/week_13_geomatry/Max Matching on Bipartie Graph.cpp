
//bài toán đường tăng luồng 

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> match;
int n,m;
//tìm kiếm đường đi tăng luồng
//nếu tìm được đường đi thì trả về true
//nếu không tìm được đường đi thì trả về false
bool DFS(int u){
    if(visited[u]) return false;
    visited[u]=true;
    for(int v:graph[u]){
        if(match[v]==-1||DFS(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main(){
   // freopen("test.txt","r",stdin);
    cin>>n>>m;
    graph.resize(n+1);
    visited.assign(n+1,false);
    match.assign(m+1,-1);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int u;
            cin>>u;
            graph[i].push_back(u);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        visited.assign(n+1,false);
        if(DFS(i)) ans++;
    }
    cout<<ans;
    return 0;
}
