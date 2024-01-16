//Group members:
// 222008524 TUYISHIME David
// 222006273 BYUKUSENGE Immaculee
// 222010802 NYODUSENGA Florence


#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check horizontally
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check vertically
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i + k][j] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonally (from bottom left to top right)
    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i - k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonally (from top left to bottom right)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            bool win = true;
            for (int k = 0; k < 4; ++k) {
                if (board[i + k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, '.'));

    char currentPlayer = 'X';
    int moves = 0;

    while (true) {
        printBoard(board);

        int col;
        cout << "Player " << currentPlayer << ", enter your column (0-" << COLS - 1 << "): ";
        cin >> col;

        if (col < 0 || col >= COLS) {
            cout << "Invalid column. Try again." << endl;
            continue;
        }

        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == '.') {
                board[i][col] = currentPlayer;
                break;
            }
            if (i == 0) {
                cout << "Column is full. Try again." << endl;
                continue;
            }
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;

        if (moves == ROWS * COLS) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
