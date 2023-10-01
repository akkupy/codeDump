#include <iostream>
#include <vector>

using namespace std;

const int GRID_SIZE = 9;

class SudokuSolver {
public:
    SudokuSolver(vector<vector<int>> board) : board_(board) {}

    bool Solve() {
        for (int row = 0; row < GRID_SIZE; ++row) {
            for (int col = 0; col < GRID_SIZE; ++col) {
                if (board_[row][col] == 0) {
                    for (int num = 1; num <= GRID_SIZE; ++num) {
                        if (IsValid(row, col, num)) {
                            board_[row][col] = num;
                            if (Solve()) {
                                return true;
                            }
                            board_[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool IsValid(int row, int col, int num) {
        for (int i = 0; i < GRID_SIZE; ++i) {
            if (board_[row][i] == num || board_[i][col] == num) {
                return false;
            }
        }

        int box_row = row / 3;
        int box_col = col / 3;
        for (int i = box_row * 3; i < box_row * 3 + 3; ++i) {
            for (int j = box_col * 3; j < box_col * 3 + 3; ++j) {
                if (board_[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    vector<vector<int>> board_;
};

int main() {
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    SudokuSolver solver(board);
    if (solver.Solve()) {
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
