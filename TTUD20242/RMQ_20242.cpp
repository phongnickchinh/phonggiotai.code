// Pham Van Phong 20215448
// 25/02/2025

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000

void preprocessing(int n, vector<int>& input, vector<vector<int>>& pre) {
    int k = log2(n) + 1;

    //trường hợp i=0:
    for(int i=0; i<n; i++){
        pre[0][i] = i;
    }

    for (int i=1; i<k; i++){
        for(int j=0; j+(1<<(i-1))-1<n; j++){
            int left  = pre[i-1][j];
            int right = pre[i-1][j+(1<<(i-1))];
            pre[i][j] = (input[left]<=input[right])?left:right;
        }
    }
}

int findMin(int a, int b, vector<vector<int>>& pre, vector<int>& input) {
    int k = log2(b-a+1);
    int left = pre[k][a];
    int right = pre[k][b-(1<<k)+1];
    return min(input[left], input[right]);
}

int main() {
    // clock_t begin = clock();

    int n, m;
    long long total = 0;
    
    // Nhập dữ liệu nhanh với scanf
    // freopen("test1.txt", "r", stdin);
    scanf("%d", &n);
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // Khởi tạo Sparse Table với kích thước tối ưu
    vector<vector<int>> save(log2(n) + 1, vector<int>(n, 0));
    preprocessing(n, list, save);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        total += findMin(a, b, save, list);
    }

    printf("%lld", total);

    // clock_t end = clock();
    // printf("\nTime run: %.6f s", (float)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}