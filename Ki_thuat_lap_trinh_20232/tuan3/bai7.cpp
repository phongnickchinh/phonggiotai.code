/*
Author: Phạm Văn Phong, 
MSSV: 20215448,
Mã lớp: 738919.
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    freopen("cc.txt", "w", stdout);
    int n=20, k=5;
    // cin >> n >> k;
    double start = clock();
    int x[n+1];
    stack<state> s;
    
    s.push(state(1, 0));
    while (!s.empty()){

        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                printf("%d", x[i]);
            printf("\n");
            s.pop();
            continue;
        }
        
        int i = top.i, j = top.j, l = top.old_L;
        if(j == 0){
            x[i] = 0;
            top.j = 1;
            top.old_L = l + 1;
            s.push(state(i+1, 0));
        }

        else if(j == 1){
            if(l < k){
                x[i] = 1;
                top.j = 2;
                s.push(state(i+1, 0, l));
                continue;
            }
            while(s.top().j == 1)
                s.pop();
        }

        else
            s.pop();

    }
    double end = clock();
    double time = (end - start)/1000;
    cout << time;
    return 0;
}