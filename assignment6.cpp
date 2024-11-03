#include <iostream>
#include <climits>
using namespace std;

float w[10][10] = {0}; // Initialize arrays to 0
float c[10][10] = {0};
int r[10][10] = {0};

int find(int i, int j) {
    int l = 0;
    float min = INT_MAX;
    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
        if ((c[i][m - 1] + c[m][j]) < min) {
            min = c[i][m - 1] + c[m][j];
            l = m;
        }
    }
    return l;
}

void OBST(float p[], float q[], int n) {
    for (int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
        if (i < n) {
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = w[i][i + 1];
        }
    }

    for (int m = 2; m <= n; m++) {
        for (int i = 0; i <= n - m; i++) {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int k = find(i, j);
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }

    cout << "Matrix :" << endl;
    cout << "Weight,Cost,Root" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << w[i][j] << "," << c[i][j] << "," << r[i][j] << "\t";
        }
        cout << endl;
    }

    // Display the total cost of the optimal binary search tree
    cout << "Total Cost of OBST: " << c[0][n] << endl;
}

int main() {
    float p[10], q[10];
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter probability of successful nodes: ";
    for (int i = 1; i <= n; i++) { // Start from 1
        cin >> p[i];
    }

    cout << "Enter probability of unsuccessful nodes: ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    OBST(p, q, n);
    return 0;
}
