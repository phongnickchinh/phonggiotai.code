#include <bits/stdc++.h>
using namespace std;

#define N 50

int n;
int x[N]; // Lưu dãy nhị phân


int check(int v, int k) {
    // if(v == 1 && (k % 2 == 1)) return 0;
    return 1;
}

int main() {
    cin >> n;
    int k = 1;
    x[k] = -1; // Khởi tạo giá trị ban đầu chưa được chọn

    while (k > 0) {
        x[k]++; // Thử giá trị tiếp theo (0 -> 1)

        while (x[k] <= 1 && !check(x[k], k)) {
            x[k]++;
        }

        if (x[k] <= 1) {
            if (k == n) {
                // In ra kết quả khi đủ độ dài
                for (int i = 1; i <= n; i++) {
                    cout << x[i] << " ";
                }
                cout << endl;
            } else {
                // Tiếp tục đến vị trí tiếp theo
                k++;
                x[k] = -1;
            }
        } else {
            // Quay lui
            k--;
        }
    }

    return 0;
}


