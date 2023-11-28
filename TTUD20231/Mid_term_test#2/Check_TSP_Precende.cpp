#include<bits/stdc++.h>
using namespace std;
//bài toán TSP có điều kiện trước
//đầu vào là một chu trình hamilton và một danh sách điều kiện đỉnh j cần đứng trước i
int dis_map[1001][1001];//đây là ma trận kề
int tsp_vex[1001];//mảng lưu các đỉnh của chu trình
int visited[1001];//mảng lưu các đỉnh đã đi qua
int totalDis=0;//tổng độ dài của chu trình
map<int,set<int>> precedeList;//danh sách các đỉnh cần đứng trước i

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n;i++){
        scanf("%d", &tsp_vex[i]);
    }
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            scanf("%d", &dis_map[i][j]);
        }
    }

    int m;
    cin>>m;
    for(int i=0; i<m;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        precedeList[b].insert(a);
    }

    for(int i=1; i<n; i++){
        visited[tsp_vex[i]]=1;
        totalDis+=dis_map[tsp_vex[i]][tsp_vex[i+1]];
        for(auto j: precedeList[tsp_vex[i]]){
            //nếu đỉnh j chưa đi qua thì không thể đi đến đỉnh i
            if(visited[j]==0){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<totalDis+dis_map[tsp_vex[n]][tsp_vex[1]];
    return 0;


}