#include <iostream>
using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int maxIndex = i;

        // Find the maximum element in the unsorted part of the array
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        // Swap the found maximum element with the current element
        swap(arr[i], arr[maxIndex]);

        // Display the current state of the array with the largest element highlighted
        cout << arr [i] << " is the largest:\t\t\t";
        for (int k = 0; k < n; k++) {
            if (k == i)
                cout << "\033[31m"<< arr[k] <<" \033[0m";
            else
                cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int selectionmain() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform selection sort
    selectionSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
