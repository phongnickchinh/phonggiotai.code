//Phạm Văn Phong 20215448_6/12/2023
//thuật toán floyd tìm đường đi ngắn nhất giữa tất cả các cặp đỉnh
#include<iostream>
#include<climits>
using namespace std;

//Cộng 2 trọng số, trả về vô cùng nếu có 1 trong 2 trọng số là vô cùng
int sum(int a, int b){
    if(a==INT_MAX || b==INT_MAX) return INT_MAX;
    return a+b;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int eges, nodes;
    int u, v, w;
    cin>>nodes>>eges;
    int graph[nodes+1][nodes+1];

    //khởi tạo ma trận trọng số, các cạnh  mặc định là vô cùng
    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
            if(i==j) graph[i][j]=0;
            else graph[i][j]=INT_MAX;
        }
    }

    for(int i=0; i<eges; i++){
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v]=w;
    }

    //thuật toán floyd xét đọ dài đường đi từ i đến j thông qua các đỉnh k trung gian
    //nếu đường đi thông qua k nhỏ hơn đường đi hiện tại thì cập nhật lại đường đi
    //nếu không thế đi qua k hoặc đi qua k dài hơn thì giữ nguyên đường đi hiện tại
    for(int k=1; k<=nodes; k++){
        for(int i=1; i<=nodes; i++){
            for(int j=1; j<=nodes; j++){
                if(i==j) graph[i][j]=0;
                else graph[i][j]=min(graph[i][j], sum(graph[i][k], graph[k][j]));
            }
        }
    }

    for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;

}