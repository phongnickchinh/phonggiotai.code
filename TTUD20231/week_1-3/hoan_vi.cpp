#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n;
int a[MAX];       // mảng chứa hoán vị
bool used[MAX];   // đánh dấu số đã dùng

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            a[k] = i;
            used[i] = true;

            if (k == n) {
                for (int j = 1; j <= n; j++)
                    cout << a[j] << " ";
                cout << endl;
            } else {
                Try(k + 1);
            }

            used[i] = false; // backtrack
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}
