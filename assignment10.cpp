#include <iostream>
using namespace std;

int n;
int minCost = 10000000;  
int answer[100][100];  // Stores multiple optimal paths
int answerCount = 0;   // Keeps track of the number of optimal paths

void solveTSP(int ds[], int adj[100][100], bool visited[], int index, int curPathSum) {
    // Base case: If we have visited all cities
    if (index == n) {
        int lastCity = ds[index - 1] - 1;
        
        // Check if there's a path back to the starting city
        if (adj[lastCity][0] != -1) {
            int finalPathCost = curPathSum + adj[lastCity][0];
            
            // If the found path cost is less than the current minimum cost
            if (finalPathCost < minCost) {
                minCost = finalPathCost;
                answerCount = 0;  // Clear the previous paths

                // Copy the current path into the answer array
                for (int i = 0; i < index; i++) {
                    answer[answerCount][i] = ds[i];
                }
                answer[answerCount][index] = 1;  // Add starting city at the end
                answerCount++;
            }
            // If the found path cost equals the current minimum cost, store it as another solution
            else if (finalPathCost == minCost) {
                for (int i = 0; i < index; i++) {
                    answer[answerCount][i] = ds[i];
                }
                answer[answerCount][index] = 1;  // Add starting city at the end
                answerCount++;
            }
        }
        return;
    }
    
    // Try visiting each city and backtrack
    for (int i = 1; i < n; i++) {
        if (!visited[i] && adj[ds[index - 1] - 1][i] != -1) {
            visited[i] = true;  // Mark the city as visited
            ds[index] = i + 1;  // Add city to the path
            
            // Recursively explore further
            solveTSP(ds, adj, visited, index + 1, curPathSum + adj[ds[index - 1] - 1][i]);
            
            visited[i] = false;  // Backtrack by marking it as unvisited
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    int adj[100][100];
    
    // Input adjacency matrix
    cout << "Enter adjacency matrix (enter -1 for no path between cities): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                adj[i][j] = -1;  // No path to itself
            } else {
                cout << "Cost to travel from " << i + 1 << " to " << j + 1 << ": ";
                cin >> adj[i][j];
            }
        }
    }

    int ds[100];  // Array to store the path
    bool visited[100] = {false};  // Array to keep track of visited cities
    ds[0] = 1;  // Start from the first city
    visited[0] = true;

    // Find minimum cost Hamiltonian path
    solveTSP(ds, adj, visited, 1, 0);

    // Output the minimum cost and optimal paths
    cout << "\nMinimum cost: " << minCost << endl;
    cout << "Optimal paths: " << endl;
    for (int i = 0; i < answerCount; i++) {
        for (int j = 0; j <= n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
