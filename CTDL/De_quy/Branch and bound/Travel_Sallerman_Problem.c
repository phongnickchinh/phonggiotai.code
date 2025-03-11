#include <stdio.h>

#define MAX_N 20
int min_dis = 99999999, total_dis, n;
int distance[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1];
int result[MAX_N + 2];

// Function to return to the starting point after visiting all nodes.
// It updates the minimum distance and then subtracts the last traveled distance.
void solution() {
    total_dis += distance[result[n - 1]][result[0]];
    if (total_dis < min_dis) min_dis = total_dis;
    total_dis -= distance[result[n - 1]][result[0]];
}

// Legitimacy check function.
// The only condition is that the node has not been visited yet.
int check(int v) {
    return !visited[v];
}

// Recursive function to explore all possible paths.
// k represents the current step in the journey.
void Try(int k) {
    // If all nodes have been visited, call the return-to-home function.
    if (k == n) {
        solution();
        return;
    }
    
    // Iterate through all possible next locations.
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            result[k] = i;
            total_dis += distance[result[k - 1]][result[k]];
            visited[i] = 1;
            
            // Pruning condition: continue only if the current path cost is less than the minimum found so far.
            if (total_dis < min_dis) Try(k + 1);

            // Backtrack: undo changes before trying the next option.
            total_dis -= distance[result[k - 1]][result[k]];
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) distance[i][j] = 0;
            else scanf("%d", &distance[i][j]);
        }
    }

    result[0] = 1;
    visited[1] = 1;
    Try(1);
    printf("%d", min_dis);
    return 0;
}