/*Develop a program to design a function for Binary Search using Divide   
and Conquer Strategies. Also compute it's time complexity. */



#include<iostream>
using namespace std;

class binarysearch {
public:
    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void itterativebinarysearch(int a[], int n) {
        bubbleSort(a, n);  
        int low = 0;
        int high = n - 1;
        int flag = 0;
        int key;
        int mid;
        cout << "Enter the key value: ";
        cin >> key;
        cout << "Low" << "\t" << "High" << "\t" << "Mid" << endl;

        while (low <= high) {
            mid = low + (high - low) / 2;
            cout << low << "\t" << high << "\t" << mid << endl;

            if (a[mid] == key) {
                flag = 1;
                break;
            } else if (key < a[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (flag == 1) {
            cout << "The element is found at index: " << mid << endl;
        } else {
            cout << "Element not found." << endl;
        }
    }

    int recursivebinarysearch(int arr[], int left, int right, int x) {
        if (right >= left) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return recursivebinarysearch(arr, left, mid - 1, x);

            return recursivebinarysearch(arr, mid + 1, right, x);
        }

        return -1;
    }
};

int main() {
    binarysearch b;
    int number;

    do {
        cout << "1. Iterative Binary Search\n2. Recursive Binary Search\n3. Exit\n";
        cin >> number;
        switch (number) {
            case 1: {
                int arr[50];
                int n;
                cout << "Enter the number of elements: ";
                cin >> n;

                cout << "Enter the unsorted elements in the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                b.itterativebinarysearch(arr, n);
                break;
            }
            case 2: {
                int n, x;
                cout << "Enter the number of elements in the array: ";
                cin >> n;
                int arr[n];
                cout << "Enter the unsorted elements of the array: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                b.bubbleSort(arr, n);  

                cout << "Enter the element to search: ";
                cin >> x;

                int result = b.recursivebinarysearch(arr, 0, n - 1, x);
                if (result != -1) {
                    cout << "Element is present at index " << result << endl;
                } else {
                    cout << "Element is not present in array" << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option, please try again." << endl;
        }
    } while (number != 3);

    return 0;
}
