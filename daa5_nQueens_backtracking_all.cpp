#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check entire row (both left and right)
    for (int j = 0; j < n; j++)
        if (board[row][j] == 1)
            return false;

    // Check entire column (both up and down)
    for (int i = 0; i < n; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    // Check lower diagonal on right side
    for (int i = row, j = col; i < n && j < n; i++, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n, int firstQueenCol) {
    // Base case: If all queens are placed
    if (col >= n)
        return true;

    // Skip the column where first queen is already placed
    if (col == firstQueenCol) {
        return solveNQueensUtil(board, col + 1, n, firstQueenCol);
    }

    // Try placing queen in all rows of current column
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, n, firstQueenCol))
                return true;

            // If placing queen doesn't lead to solution
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQueens(vector<vector<int>>& board, int firstQueenRow, int firstQueenCol, int n) {
    // Clear the board first
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    
    // Place the first queen at user specified position
    board[firstQueenRow][firstQueenCol] = 1;
    
    // Check if first queen position is valid
    if (!isSafe(board, firstQueenRow, firstQueenCol, n)) {
        board[firstQueenRow][firstQueenCol] = 0;  // Remove the queen to check properly
        if(isSafe(board, firstQueenRow, firstQueenCol, n)) {
            board[firstQueenRow][firstQueenCol] = 1;  // Place it back
        } else {
            cout << "Invalid position for first queen!\n";
            return false;
        }
    }
    
    // Start solving from the first column
    if (!solveNQueensUtil(board, 0, n, firstQueenCol)) {
        cout << "Solution does not exist!\n";
        return false;
    }
    
    return true;
}

void printBoard(vector<vector<int>>& board, int n) {
    cout << "\nBoard Configuration:\n";
    cout << "   ";
    for(int j = 0; j < n; j++) {
        cout << j << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << i << "  ";
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    int n, firstQueenRow, firstQueenCol;
    
    cout << "Enter the size of board (n): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid board size!\n";
        return 1;
    }
    cout << "Enter the row position for first queen (0 to " << n-1 << "): ";
    cin >> firstQueenRow;
    cout << "Enter the column position for first queen (0 to " << n-1 << "): ";
    cin >> firstQueenCol;
    
    if (firstQueenRow < 0 || firstQueenRow >= n || firstQueenCol < 0 || firstQueenCol >= n) {
        cout << "Invalid position! Row and column must be between 0 and " << n-1 << "\n";
        return 1;
    }

    // Initialize the board
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    if (solveNQueens(board, firstQueenRow, firstQueenCol, n)) {
        cout << "\nSolution exists! Here's one solution:";
        printBoard(board, n);
    }
    return 0;
}