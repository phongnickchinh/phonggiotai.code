#include<bits/stdc++.h>
using namespace std;

int n, M;
vector<int> Elements;

void solution(const vector<int>& Phantu) {
    for (unsigned int i = 0; i < Phantu.size(); i++) {
        cout << Phantu[i] << " ";
    }
    cout << endl;
}

void Try(int soluong, int Tong, vector<int> Phantu) {
    if (soluong == 0) {
        if (Tong == 0) {
            solution(Phantu);
        }
        return;
    } else {
        for (int i = 1; i <= Tong; i++) {
            Phantu.push_back(i);
            Try(soluong - 1, Tong - i, Phantu);
            Phantu.pop_back();
        }
    }
}

int main() {
    cin >> n >> M;
    Try(n, M,{});
    return 0;
}
