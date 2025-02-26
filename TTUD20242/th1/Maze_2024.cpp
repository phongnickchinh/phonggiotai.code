#include <bits/stdc++.h>
using namespace std;

// Represents a state in the BFS search
class State {
public:
    int row;     // Row index in the maze
    int column;  // Column index in the maze
    int step;    // Steps taken from the start position

    // Constructor to initialize state
    State(int r, int c, int s) : row(r), column(c), step(s) {};
};

// Implements BFS to find the shortest path out of the maze
class BFS {
public:
    queue<State> Q;
    int n, m;
    vector<vector<int>> maze;
    vector<vector<int>> visited;

    // Constructor to initialize the maze and visited matrix
    BFS(int rows, int cols) : n(rows), m(cols) {
        maze = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
        visited = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
    }

    // Adds a new state to the BFS queue
    void addState(int r, int c, int s) {
        State newState(r, c, s);
        Q.push(newState);
    }

    // Checks if a move is valid
    bool isValid(int row, int column) {
        if (maze[row][column] == 1) return false;
        if (visited[row][column]) return false;
        if (row < 0 || row > n + 1 || column < 0 || column > m + 1) return false;
        return true;
    }

    // Finds the shortest path out of the maze using BFS
    int solution(State start) {
        Q.push(start);

        while (!Q.empty()) {
            State temp = Q.front();
            Q.pop();
            visited[temp.row][temp.column] = 1;
            //if find the uway out, return
            if (temp.row == 0 || temp.column == 0 || temp.row == n + 1 || temp.column == m + 1) 
                return temp.step;
            //try turn up
            if (isValid(temp.row + 1, temp.column)) {
                addState(temp.row + 1, temp.column, temp.step + 1);
                visited[temp.row + 1][temp.column] = 1;
            }
            //try turn down
            if (isValid(temp.row - 1, temp.column)) {
                addState(temp.row - 1, temp.column, temp.step + 1);
                visited[temp.row - 1][temp.column] = 1;
            }

            //try turn right
            if (isValid(temp.row, temp.column + 1)) {
                addState(temp.row, temp.column + 1, temp.step + 1);
                visited[temp.row][temp.column + 1] = 1;
            }
            //try turn left
            if (isValid(temp.row, temp.column - 1)) {
                addState(temp.row, temp.column - 1, temp.step + 1);
                visited[temp.row][temp.column - 1] = 1;
            }
        }
        return -1;
    }
};

// Main function to read input and execute BFS
int main() {
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    
    BFS Phong(n, m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &Phong.maze[i][j]);
        }
    }

    State start(r, c, 0);
    int result = Phong.solution(start);
    
    printf("%d", result);
    
    return 0;
}
