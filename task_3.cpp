  

// bool isSafe(int row, int col, const vector<vector<int>>& board, int val) {
//     for (int i = 0; i < board.size(); i++) {
//         if (board[row][i] == val || board[i][col] == val) {
//             return false;
//         }
//         if (row / 3 * 3 + i / 3 < board.size() / 3 && col / 3 * 3 + i % 3 < board.size() / 3 && board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == val) {
//             return false;
//         }
//     }
//     return true;
// }

#include <iostream>
#include <vector>
using namespace std;

// Check whether a given value can be placed in a cell without violating the Sudoku rules
bool isSafe(int row, int col, const vector<vector<int>>& board, int val) {
    for (int i = 0; i < board.size(); i++) {
        if (board[row][i] == val || board[i][col] == val) {
            return false;
        }
        if (row / 3 * 3 + i / 3 < board.size() / 3 && col / 3 * 3 + i % 3 < board.size() / 3 && board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == val) {
            return false;
        }
    }
    return true;
}

// Recursively fill in the empty cells of the board
bool solve(vector<vector<int>>& board) {
    if (board.empty()) {
        return true;
    }
    int n = board.size();
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        if (solve(board)) {
                            return true;
                        }
                        board[row][col] = 0; // backtrack
                    }
                }
                return false; // return false if no value can be placed
            }
        }
    }
    return true; // return true if all cells have been filled
}

// Print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    int n = board.size();
    for (int row = 0; row < n; row++) {
        if (row != 0) {
            cout << endl;
        }
        for (int col = 0; col < n; col++) {
            if (col != 0) {
                cout << " ";
            }
            cout << board[row][col];
        }
    }
    cout << endl;
}

int main() {
    // Initialize the Sudoku board
    vector<vector<int>> board = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 1, 0, 0}
    };

    // Solve the Sudoku board
    if (solve(board)) {
        // Print the solved Sudoku board
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}