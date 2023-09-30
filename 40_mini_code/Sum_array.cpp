#include <iostream>
using namespace std;

int nhap_mang(int n, int *array) {
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
}

int tong_mang(int n, int *array ) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int mang[n];
    nhap_mang(n, mang);
    int sum = tong_mang(n, mang);
    cout << sum;
    return 0;
}
