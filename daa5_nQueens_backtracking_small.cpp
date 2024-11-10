#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check this column on the upper side
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    // If all queens are placed, return true
    if (row >= N)
        return true;

    // Try placing a queen in each column for this row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place queen
            board[row][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, row + 1, N))
                return true;

            // If placing queen at board[row][col] doesn't lead to a solution, remove it
            board[row][col] = 0;
        }
    }

    // If the queen can't be placed in any column in this row, return false
    return false;
}

// Function to solve the N-Queens problem
void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueensUtil(board, 0, N)) {
        // Print the solution
        for (const auto& row : board) {
            for (int cell : row)
                cout << (cell ? "Q " : ". ");
            cout << endl;
        }
    } else {
        cout << "No solution exists for " << N << " queens." << endl;
    }
}

int main() {
    int N = 8; // Change N to any desired board size
    solveNQueens(N);
    return 0;
}
