/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/

#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    int sum = 0, i, j;
    s.push(state(1, -1));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << " = " << sum << endl;
                // exit(0);
            }
            s.pop();
            continue;
        }
        
        i = top.i; j = top.j;
        if(j==-1){
            x[i] = -1;
            top.j = 0;
            sum -= m[i];
            s.push(state(i+1, -1));
        }
        else if(j==0){
            x[i] = 0;
            top.j = 1;
            sum += m[i];
            s.push(state(i+1, -1));
        }
        else if(j==1){
            x[i] = 1;
            top.j = 2;
            sum += m[i];
            s.push(state(i+1, -1));
        }
        else{
            sum -= m[i];
            x[i] = 0;
            s.pop();
        }
    }
    return 0;
}
