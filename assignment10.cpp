#include <iostream>
#include <climits>

using namespace std;

const int MAX_CITIES = 10; 
int dist[MAX_CITIES][MAX_CITIES]; 
int bestPath[MAX_CITIES]; 
int tempPath[MAX_CITIES]; 

void tspBranchAndBound(int city, int costSoFar, int count, bool visited[], int& minCost, int N) {
    if (count == N && dist[city][0] != 0) { 
        int totalCost = costSoFar + dist[city][0];
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < N; i++) {
                bestPath[i] = tempPath[i]; 
            }
            bestPath[N] = 0; 
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[city][i] != 0) { 
            visited[i] = true;
            tempPath[count] = i; 
            tspBranchAndBound(i, costSoFar + dist[city][i], count + 1, visited, minCost, N);
            visited[i] = false; // Backtrack
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of cities: ";
    cin >> N;

    if (N > MAX_CITIES) {
        cout << "The maximum supported number of cities is " << MAX_CITIES << endl;
        return 1;
    }

    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }
    }

    bool visited[MAX_CITIES] = {false};
    visited[0] = true; 
    tempPath[0] = 0;
    int minCost = INT_MAX;

    tspBranchAndBound(0, 0, 1, visited, minCost, N);

    cout << "The minimum cost of the tour is: " << minCost << endl;
    cout << "The path of the tour is: ";
    for (int i = 0; i <= N; i++) {
        cout << bestPath[i] << " ";
    }
    cout << endl;

    return 0;
}
