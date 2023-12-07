//Phạm Văn Phong 20215448 _ 27/10/2023
#include <bits/stdc++.h>
using namespace std;
//lưu một danh sách kề của các điểm bằng vector 2 chiều
vector<int> graph[1000001];
int odd_even[1000001]={0};//đánh dấu đỉnh ở bên chẵn hay lẻ

//kiểm tra đồ thị có phải là đồ thị 2 phần hay không
//nếu có đỉnh chẵn nối với đỉnh chẵn thì không phải đồ thị 2 phần
int Check2side(int source, int nodes) {
    int n=1;
    odd_even[source]=1;
    //vòng lặp vẫn chạy chừng nào chưa duyệt hết nút:
    while (n<=nodes) {
        for(int &i:graph[n]){
            if(odd_even[i]==odd_even[n]){
                return 0; 
            }else{
                if(odd_even[n]==1) odd_even[i]=2;
                if(odd_even[n]==2) odd_even[i]=1;
            }
        }
        n++;
    }
    return 1;
}

int main() {
    //freopen("test1.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<< Check2side(1,n)<<endl;// đề bài lúc nào cũng duyệt từ 1

    return 0;
}
