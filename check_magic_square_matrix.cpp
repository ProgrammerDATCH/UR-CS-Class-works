//Group members:
// 222008524 TUYISHIME David
// 222006273 BYUKUSENGE Immaculee
// 222010802 NYODUSENGA Florence


#include <iostream>
#include <vector>
using namespace std;
bool isMagicSquare(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Calculate the sum of the first row (and sum of all rows/columns/diagonals)
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += matrix[0][j];
    }

    // Check sums of rows
    for (int i = 1; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) {
            return false;
        }
    }

    // Check sums of columns
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += matrix[i][j];
        }
        if (colSum != sum) {
            return false;
        }
    }

    // Check sum of main diagonal
    int diagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        diagonalSum += matrix[i][i];
    }
    if (diagonalSum != sum) {
        return false;
    }

    // Check sum of secondary diagonal
    diagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        diagonalSum += matrix[i][n - 1 - i];
    }
    if (diagonalSum != sum) {
        return false;
    }

    // If all checks pass, it's a magic square
    return true;
}

int main() {
    vector<vector<int>> matrix(3, vector<int>(3));

    cout << "Enter the elements of the 3x3 matrix:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<"Enter Element at row "<<i+1<<" col "<<j+1<<": ";
            cin >> matrix[i][j];
        }
    }

    if (isMagicSquare(matrix)) {
        cout << "It's a magic square!" << endl;
    } else {
        cout << "It's not a magic square." << endl;
    }

    return 0;
}
