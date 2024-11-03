#include<iostream>
using namespace std;
int cnt=0;

bool possible(int node, int **arr, int n, int colors[], int color) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[node][i] == 1 && colors[i] == color) 
        {
            return false;
        }
    }
    return true;
}

void printSolution(int colors[], int n, string s[]) 
{
    cout << "Solution "<<cnt<<" :";
    for (int i = 0; i < n; i++) 
    {
        cout << s[colors[i]] << " ";
    }
    cout << endl;
}

bool graphColoring(int node, int **arr, int m, int n, int colors[], string s[], bool &solutionFound) 
{
    if (node == n) 
    {     
        cnt++;
        printSolution(colors, n, s);
        solutionFound = true;
        return false; 
    }

   
    for (int i = 0; i < m; i++) 
    {
        if (possible(node, arr, n, colors, i)) 
        {
            colors[node] = i; 

            
            graphColoring(node + 1, arr, m, n, colors, s, solutionFound);

            
            colors[node] = -1;
        }
    }

    return false; 
}

int main() 
{
    int m, n;
    cout << "Enter number of nodes: ";    
    cin >> n;

    int **arr = new int*[n];

    for (int i = 0; i < n; i++) 
    {
        arr[i] = new int[n];
    }

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << "Enter coordinate (" << i << j << ") : ";
            cin >> arr[i][j];            
        }
    }

    cout << "\nEnter number of colors: ";    
    cin >> m;

    string colorNames[m];
    cout << "\n\nEnter colors:\n";
    for (int i = 0; i < m; i++) 
    {
        cout << "\nEnter color " << i + 1 << " : ";
        cin >> colorNames[i];                    
    }

    int colors[n];
    for (int i = 0; i < n; i++) 
    {
        colors[i] = -1; 
    }

    bool solutionFound = false;
    cout << "\n\n";
    graphColoring(0, arr, m, n, colors, colorNames, solutionFound);

    if (!solutionFound) 
    {
        cout << "\n\nSolution does not exist.\n";
    }

    return 0;
}