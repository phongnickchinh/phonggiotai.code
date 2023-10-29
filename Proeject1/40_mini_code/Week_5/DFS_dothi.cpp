//Phạm Văn Phong 20215448_29/10/2023
#include<bits/stdc++.h>
using namespace std;
//lưu một danh sách kề của các điểm bằng vector 2 chiều
vector<vector<int>> graph;
//một danh sách đánh dấu đỉnh đã được duyệt hay chưa
vector<bool> visited; 

//Duyệt theo chiều sâu, sử dụng ngăn xếp:
void DFS(int sourse, int node){
    stack<int> s;
    int n=1;
    s.push(sourse);
    while(n<=node){ 
        if(!s.empty()){
            int temp=s.top();
            if(!visited[temp]){
                cout<<temp<<" ";
                visited[temp]=true;
                n++;
            }s.pop();
            for( auto &&number:graph[temp]){
                if(!visited[number]){
                    s.push(number);
                }
            }
        }else{
            //Đoạn này là để xử lí trường hợp duyệt đến ngõ cụt
            // mà vẫn chưa duyệt hết các đỉnh
            int newSource;
            for(int i=1;i<=n; i++){if(!visited[i]){newSource=i;break;}}
            s.push(newSource);
            visited[newSource]=true;
        }
    }

}
 int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //tiền xử lí, sắp xếp danh sách đỉnh kề theo chiêu giảm dần:
    for (int i = n; i >= 1; i--) {
    sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    DFS(1,n);
    return 0;
 }