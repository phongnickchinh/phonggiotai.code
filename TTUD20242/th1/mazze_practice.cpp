#include<bits/stdc++.h>
using namespace std;

struct State {
    int row;
    int column;
    int step;

    State(int r, int c, int s){
        row=r;
        column=c;
        step=s;
    }
};

#define MAX_N 1002
#define MAX_M 1002


int check(int r, int c, int n, int m, vector<vector<int>> &map, vector<vector<int>> &visited){
    if(map[r][c]==1) return 0;
    if(visited[r][c]) return 0;
    if(r<0||c<0||r>n+1||c>m+1) return 0;
    return 1;
    

}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, r, c;
    bool notFound=true;
    cin>>n>>m>>r>>c;
    vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> visited(n + 2, vector<int>(m + 2, 0));    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            visited[i][j]=0;
            cin>>map[i][j];
        }
    }

    queue<State> Q;
    State start(r,c,0);
    Q.push(start);
    while (!Q.empty())
    {
        State temp = Q.front();
        Q.pop();
        visited[temp.row][temp.column]=1;

        if(temp.row==0 || temp.column==0 || temp.row==n+1 || temp.column == m+1){
            cout<<temp.step;
            notFound=false;
            break;
        }

        if(check(temp.row+1,temp.column,n,m,map,visited)){
            State newstate(temp.row+1,temp.column, temp.step+1);
            Q.push(newstate);
            visited[newstate.row][newstate.column]=1;
        }

        if(check(temp.row-1,temp.column,n,m,map,visited)){
            State newstate(temp.row-1,temp.column, temp.step+1);
            Q.push(newstate);
            visited[newstate.row][newstate.column]=1;
        }

        if(check(temp.row,temp.column+1,n,m,map,visited)){
            State newstate(temp.row,temp.column+1, temp.step+1);
            Q.push(newstate);
            visited[newstate.row][newstate.column]=1;
        }

        if(check(temp.row,temp.column-1,n,m,map,visited)){
            State newstate(temp.row,temp.column-1, temp.step+1);
            Q.push(newstate);
            visited[newstate.row][newstate.column]=1;
        }

    }
    if(notFound) cout<<-1;
    return 0;
    
}