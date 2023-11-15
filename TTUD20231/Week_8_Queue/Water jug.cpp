//Phạm Văn Phong 20215448_8/11/2023
#include<bits/stdc++.h>
#define N 1001
using namespace std;

bool visited[N][N];

struct state {
    int a, b, step;
    state(int a, int b, int t) : a(a), b(b), step(t) {}
};

void solve(int a, int b, int target) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=false;
        }
    }
    queue<state> q;
    state start(0,0,0);
    q.push(start);
    visited[0][0]=true;

    while (!q.empty()) {
        state u = q.front(); q.pop();

        if (u.a == target || u.b == target) {
            cout << u.step;
            return;
        }

        // fill jug a
        if (u.a < a && !visited[a][u.b]) {
            q.push(state(a, u.b, u.step + 1));
            visited[a][u.b] = true;
        }

        // fill jug b
        if (u.b < b && !visited[u.a][b]) {
            q.push(state(u.a, b, u.step + 1));
            visited[u.a][b] = true;
        }

        // empty jug a
        if (u.a > 0 && !visited[0][u.b]) {
            q.push(state(0, u.b, u.step + 1));
            visited[0][u.b] = true;
        }

        // empty jug b
        if (u.b > 0 && !visited[u.a][0]) {
            q.push(state(u.a, 0, u.step + 1));
            visited[u.a][0] = true;
        }

        // pour from a to b
        if (u.a > 0 && u.b < b) {
            int pour = min(u.a, b - u.b);
            if (!visited[u.a - pour][u.b + pour]) {
                q.push(state(u.a - pour, u.b + pour, u.step + 1));
                visited[u.a - pour][u.b + pour] = true;
            }
        }

        // pour from b to a
        if (u.b > 0 && u.a < a) {
            int pour = min(u.b, a - u.a);
            if (!visited[u.a + pour][u.b - pour]) {
                q.push(state(u.a + pour, u.b - pour, u.step + 1));
                visited[u.a + pour][u.b - pour] = true;
            }
        }
    }

    cout << "-1" << endl;
}

int main() {
   int a, b, target;
   cin>>a>>b>>target;
    solve(a, b, target);
    return 0;
}



//Minh hoạ hàng đợi với test case 6 8 4:
/*khởi tạo:(0,0,0)
loop 1: u=(0,0,0)
    (6,0,1)
    (0,8,1)
loop 2: u=(6,0,1)
    (0,8,1)
    (6,8,2)
    (0,6,2)
loop3: u=(0,8,1)
    (6,8,2)
    (0,6,2)
    (6,2,2)
loop4: u=(6,8,2)
    (0,6,2)
    (6,2,2)
loop5: u=(0,6,2)
    (6,2,2)
    (6,6,3)
loop6: u=(6,2,2)
    (6,2,2)
    (0,2,3)
loop7: u=(6,2,2)
    (4,8,4)
    (0,2,3)
loop8: u=(4,8,4) break
x=4, y=8, step=4 là kết quả đầu tiên thỏa mãn điều kiện đề bài
kết thúc vòng lặp





        */