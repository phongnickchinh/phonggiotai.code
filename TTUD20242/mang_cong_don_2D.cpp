#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1001
#define MAX_M 1001
vector<vector<int>> input(MAX_N, vector<int>(MAX_M + 1, 0));
vector<vector<int>> pre(MAX_N, vector<int>(MAX_M + 1, 0));

void preprocess(int n, int m){
    // cout<<"hello there";
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            pre[i][j]=input[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

}

int findTotal(int l1, int r1, int l2, int r2){
    return pre[l2][r2]+ pre[l1-1][r1-1] - pre[l1-1][r2] - pre[l2][r1-1];
}

int main() {
    int n, m;
    // freopen("test1.txt", "r", stdin);
    
    scanf("%d %d", &n, &m);



    // Đọc dữ liệu
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &input[i][j]);
        }
    }

    preprocess(n, m);

    int q, r1, r2, l1, l2;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        printf("%d\n", findTotal(l1, r1, l2, r2));
    }

    return 0;
}