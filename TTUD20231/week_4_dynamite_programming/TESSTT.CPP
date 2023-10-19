#include <bits/stdc++.h>
using namespace std;

#define N 1000000

int **save;

void preprocessing(int list[], int n) {
    save = new int *[30];
    for (int i = 0; i < 30; i++) {
        save[i] = new int[N];
    }

    for (int i = 0; i <= 8; i++) {
        save[0][i] = i;
    }

    for (int i = 1; i <= log2(n); i++) {
        for (int j = 0; j < n; j++) {
            if ((list[save[i - 1][j]]) <= (list[save[i - 1][j + (int)pow(2, i) - 1]])) {
                save[i][j] = save[i - 1][j];
            } else
                save[i][j] = save[i - 1][j + (int)pow(2, i) - 1];
        }
    }
}

int findmin(int a, int b, int list[]) {
    if (b < a) {
        return INT_MAX;
    }

    int dodai = (int)log2(b - a);
    int number1 = list[save[dodai][a]];
    int number2 = list[save[dodai][b - (int)pow(2, dodai) + 1]];
    return min(number1, number2);
}

int main() {
    int list[N];
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    cin >> m;
    preprocessing(list, n);

    int a, b, sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        sum += findmin(a, b, list);
    }
    cout << sum;

    for (int i = 0; i < 30; i++) {
        delete[] save[i];
    }
    delete[] save;

    return 0;
}