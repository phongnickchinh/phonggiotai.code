//Phạm Văn Phong 20215448_9/11/2023
//thuật toán floyd tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh
//Ý tưởng là cập nhật độ dài đường đi thông qua các đỉnh trung gian
//Độ phức tạp O(n^3)
#include<bits/stdc++.h>
using namespace std;

//Cộng 2 trọng số, trả về vô cùng nếu có 1 trong 2 trọng số là vô cùng
int sum(int a, int b){
    if(a==INT_MAX || b==INT_MAX) return INT_MAX;
    return a+b;
}
int main(){
    int eges, nodes;
    int u, v, w;
    cin>>nodes>>eges;
    int graph[nodes+1][nodes+1];

    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
            graph[i][j] = INT_MAX;
        }
    }

    for(int i=1; i<=eges; i++){
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = w;
    }
    //thuật toán floyd duyệt qua các đinh trung gian 
    //và quãng đường giữa 2 đỉnh thông qua đỉnh trung gian đó
    for(int k=1; k<=nodes; k++){
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                if(i==j) graph[i][j] = 0;
                else{
                    //cập nhật đương đi
                    graph[i][j] = min(graph[i][j], sum(graph[i][k], graph[k][j])); 
                }
                
            }
        }
    }
    //in ra ma trận kết quả
    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
            printf("%d ", graph[i][j]); 
        }
        printf("\n");
    }
}