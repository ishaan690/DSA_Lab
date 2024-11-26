#include <iostream>
#include <vector>
using namespace std;

// Function to print the solution
void printSolution(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        // All queens are placed
        printSolution(board, n);
        return true;
    }

    bool foundSolution = false;

    // Try placing the queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the next queen
            foundSolution |= solveNQueens(board, row + 1, n);

            // Backtrack
            board[row][col] = 0;
        }
    }

    return foundSolution;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize board with 0

    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists for " << n << " queens.\n";
    }

    return 0;
}
