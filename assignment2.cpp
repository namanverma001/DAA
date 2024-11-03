/*Develop a program to design a class for Concurrent Quick Sort Using 
Divide and Conquer Strategies. Also Compute it's time complexity. */

#include <iostream>
using namespace std;

void printArray(const int arr[], int size) {  
    for (int i = 0; i < size; i++) {  
        cout << arr[i] << " ";  
    }  
    cout << "\n";  
}

int partition(int arr[], int low, int high) {  
    int pivot = arr[high];  
    int i = low - 1;        
 
    for (int j = low; j < high; j++) {  
        if (arr[j] <= pivot) {  
            i++;  
            swap(arr[i], arr[j]);  
        }  
    }  
 
    swap(arr[i + 1], arr[high]);  
   
    cout << "Partitioned with pivot " << pivot << ": ";
    printArray(arr, high - low + 1);
 
    return i + 1;  
}  
 
void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        cout << "Low = " << low << ", High = " << high << ": ";
        printArray(arr, high - low + 1);

        int pivotIndex = partition(arr, low, high);  
 
        quickSort(arr, low, pivotIndex - 1);  
        quickSort(arr, pivotIndex + 1, high);  
    }  
}  
 
int main() {  
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    cout << "Original Array: ";  
    printArray(arr, n);  
 
    quickSort(arr, 0, n - 1);  
 
    cout << "Sorted Array: ";  
    printArray(arr, n);  
 
    return 0;  
}