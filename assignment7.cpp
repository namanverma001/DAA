#include <iostream>
using namespace std;


void printSolution(int board[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

bool isSafe(int board[][10], int row, int col, int n) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[][10], int col, int n) {

    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {


        if (isSafe(board, i, col, n)) {

            board[i][col] = 1;

            if (solveNQUtil(board, col + 1, n))
                return true;


            board[i][col] = 0; // BACKTRACK
        }
    }


    return false;
}

bool solveNQ(int n) {
    int board[10][10] = {0};  

    if (!solveNQUtil(board, 0, n)) {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(board, n);
    return true;
}

int main() {
    int n;
    cout << "Enter the number of queens (and the board size): ";
    cin >> n;

    if (n > 10) {
        cout << "Maximum allowed size is 10.\n";
        return 0;
    }

    solveNQ(n);
    return 0;
}
