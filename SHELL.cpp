#include <iostream>
using namespace std;

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    int gap = n;

    cout << "Initial Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    while (gap > 1) {
        gap = gap / 2; // Divide by 2 for the gap sequence
        if ((gap/2 != 0)){
            cout << "n/2 = " << gap << " / 2 = " << (gap/2) << "\n\n";
        } else{
            cout << "Since Gap = 1, Perform Insertion Sort: " << "\n\n";
        }
        
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            cout << "Pass with gap " << gap << ": ";
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    cout << "[" << arr[k] << "] ";
                } else {
                    cout << arr[k] << " ";
                }
            }
            cout << endl;
        }
    }
}

int shellmain() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shellSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
