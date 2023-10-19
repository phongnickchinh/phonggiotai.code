#include <iostream>
using namespace std;

const int N = 9; // Size of the Sudoku grid

// Function to check if a number is safe to place in a given cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not already in the current row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number is not already in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking and count solutions
int solveSudokuCount(int grid[N][N]) {
    int row, col;

    // Find the first empty cell in the grid
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If there are no empty cells, a solution is found
    if (!isEmpty) {
        return 1;
    }

    int count = 0;

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the puzzle and count solutions
            count += solveSudokuCount(grid);

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return count;
}

int main() {
    int grid[N][N];

    // Input the Sudoku grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Count the number of Sudoku solutions
    int solutionCount = solveSudokuCount(grid);

    // Output the number of solutions
    cout << solutionCount << endl;

    return 0;
}