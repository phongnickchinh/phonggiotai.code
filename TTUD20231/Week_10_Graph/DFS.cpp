//Phạm Văn Phong 20215448 _ 27/10/2023
#include <bits/stdc++.h>
using namespace std;
//lưu một danh sách kề của các điểm bằng vector 2 chiều
vector<vector<int>> graph;
vector<bool> visited; //một danh sách đánh dấu đỉnh đã được duyệt hay chưa

//Duyệt đồ thị theo chiều rộng, bằng đầu từ nút nhận vào
void DFS(int source, int nodes) {
    stack<int>q; // danh sách duyệt bằng stack, với phần từ đầu tiên là diểmđầu
    q.push(source);
    int n=1;
    visited[source] = true;
    cout << source << " ";
    //vòng lặp vẫn chạy chừng nào chưa duyệt hết nút:
    while (n<=nodes) {
        if(!q.empty()){
            int current = q.top();
            q.pop();
            if(visited[current]==false){
                cout << current << " ";
                visited[current]=true;
                n++;
            }
            for (int node : graph[current]) {
            //nếu đỉnh chưa được duyệt bao giờ:
                if (!visited[node]) {
                q.push(node);
                }
            }
        }else{
            //Đoạn này là để xử lí trường hợp duyệt đến ngõ cụt
            // mà vẫn chưa duyệt hết các đỉnh
            int newSource;
            for(int i=1;i<=n; i++){if(!visited[i]){newSource=i;break;}}
            q.push(newSource);
            visited[newSource]=true;
            n++;
        }
    }
}

int main() {
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

    //Sắp xếp danh sách kề theo chiều giảm dần:
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(),greater<int>());
    }
    //thử in ra danh sách kề:
    for (int i = 1; i <= n; i++) {
        cout<<i<<": ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    DFS(1,n);// đề bài lúc nào cũng duyệt từ 1
    return 0;
}
