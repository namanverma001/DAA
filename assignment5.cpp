/*Develop a program to implement 0/1 Knapsack problem using Dynamic 
Programming.*/

#include <iostream>
using namespace std;


int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; 
            }
            else if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    
    cout << "\nDP Table:\n";
    cout << "\ti\\W\t";  
    for (int w = 0; w <= W; w++) {
        cout << w << "\t";
    }
    cout << "\n";
    
    for (int i = 0; i <= n; i++) {
        cout << "\t" << i << "\t";  
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << "\n";
    }

    return dp[n][W];
}

int main() {
    int n, W;

    
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n];

    
    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Value of item " << i+1 << ": ";
        cin >> val[i];
    }

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i+1 << ": ";
        cin >> wt[i];
    }

    
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    
    int maxVal = knapsack(W, wt, val, n);
    
    
    cout << "\nMaximum value in Knapsack: " << maxVal << endl;

    return 0;
}
