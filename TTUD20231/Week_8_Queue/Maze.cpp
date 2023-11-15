    #include<bits/stdc++.h>
    using namespace std;

    const int MAX = 1001;
    int n, m, row, comlumn;
    int maze[MAX][MAX];
    bool visited[MAX][MAX];
    struct state {
        int row, comlumn, step;
        state(int row, int comlumn, int t) : row(row), comlumn(comlumn), step(t) {}
    };


    bool isValid(int x, int y) {
        //Trả về true nếu vị trí (x,y) nằm trong mê cung( trừ các bụi rậm) và chưa được thăm
        //cần xét cả trường hợp rìa mê cung để tìm được đường đi đầu tiên thoát khỏi mê cung
        return x >= 0 && y >= 0 && x <= n+1 && y <= m+1 && maze[x][y] == 0 && !visited[x][y];
    }

    int solution(int r, int c){
        queue<state> q;
        state start(r,c,0);
        q.push(start);
        visited[r][c] = true;
        while (!q.empty()){
            state u = q.front();
            q.pop();
            //cout<<"POP " << u.row <<" "<<u.comlumn<<endl;
            if (u.row == 0 || u.comlumn == 0 || u.row == n+1 || u.comlumn == m+1) {
                return u.step;
            }

            //rẽ lên
            if(isValid(u.row-1,u.comlumn)){
                q.push(state(u.row-1,u.comlumn,u.step+1));
                //cout<<"push "<<u.row-1<<" "<<u.comlumn<<endl;
                visited[u.row-1][u.comlumn] = true;
            }

            //rẽ xuống
            if(isValid(u.row+1,u.comlumn)){
                q.push(state(u.row+1,u.comlumn,u.step+1));
                //cout<<"push "<<u.row+1<<" "<<u.comlumn<<endl;
                visited[u.row+1][u.comlumn] = true;
            }


            //rẽ trái
            if(isValid(u.row, u.comlumn-1)){
                q.push(state(u.row,u.comlumn-1,u.step+1));
                //cout<<"push "<<u.row<<" "<<u.comlumn-1<<endl;
                visited[u.row][u.comlumn-1] = true;
            }

            //rẽ phải
            if(isValid(u.row,u.comlumn+1)){
                q.push(state(u.row,u.comlumn+1,u.step+1));
                //cout<<"push "<<u.row<<" "<<u.comlumn+1<<endl;
                visited[u.row][u.comlumn+1] = true;
            }


        }
        return -1;
        

    }

    int main() {
    //freopen("inp.txt", "r", stdin);
        cin >> n >> m >> row >> comlumn;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> maze[i][j];
            }
        }

        memset(visited, false, sizeof(visited));
        for(int i=1; i<=MAX; i++){
            for(int j=1; j<=MAX; j++){
                visited[i][j]=false;
            }
        }
        cout << solution(row, comlumn) << endl;

        return 0;
    }

    /*
    Mô phỏng ngăn xếp với test case:
    8 12 5 6
    1 1 0 0 0 0 1 0 0 0 0 1
    1 0 0 0 1 1 0 1 0 0 1 1
    0 0 1 0 0 0 0 0 0 0 0 0
    1 0 0 0 0 0 1 0 0 1 0 1
    1 0 0 1 0 0 0 0 0 1 0 0 
    1 0 1 0 1 0 0 0 1 0 1 0
    0 0 0 0 1 0 1 0 0 0 0 0
    1 0 1 1 0 1 1 1 0 1 0 1

    POP 5 6
    push 4 6
    push 6 6
    push 5 5
    push 5 7
    POP 4 6
    push 3 6
    push 4 5
    POP 6 6
    push 7 6
    push 6 7
    POP 5 5
    POP 5 7
    push 5 8
    POP 3 6
    push 3 5
    push 3 7
    POP 4 5
    push 4 4
    POP 7 6
    POP 6 7
    push 6 8
    POP 5 8
    push 4 8
    push 5 9
    POP 3 5
    push 3 4
    POP 3 7
    push 2 7
    push 3 8
    POP 4 4
    push 4 3
    POP 6 8
    push 7 8
    POP 4 8
    push 4 9
    POP 5 9
    POP 3 4
    push 2 4
    POP 2 7
    POP 3 8
    push 3 9
    POP 4 3
    push 5 3
    push 4 2
    POP 7 8
    push 7 9
    POP 4 9
    POP 2 4
    push 1 4
    push 2 3
    POP 3 9
    push 2 9
    push 3 10
    POP 5 3
    push 5 2
    POP 4 2
    push 3 2
    POP 7 9
    push 8 9
    push 7 10
    POP 1 4
    push 0 4 //Điểm đích, tuy nhiên vẫn chạy tiếp vì chưa gặp điều kiện dừng
    push 1 3
    push 1 5
    POP 2 3
    push 2 2
    POP 2 9
    push 1 9
    push 2 10
    POP 3 10
    push 3 11
    POP 5 2
    push 6 2
    POP 3 2
    push 3 1
    POP 8 9
    push 9 9
    POP 7 10
    push 6 10
    push 7 11
    POP 0 4 //Mặc dù gặp điểm đích tít bên trên nhưng xuống đây mới dừng được thuật toán
    7
    */