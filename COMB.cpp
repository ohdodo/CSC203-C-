#include <iostream>
using namespace std;

// Function to perform Shell Sort
void combSort(int arr[], int n) {
    int gap = n;
    cout << "Initial Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    while (gap > 0) {
        gap = ((gap*10)/13); // Divide by 1.3 for the gap sequence
        if (((gap*10)/13) != 0){
            cout << "\nn/1.3 = " << gap << " / 1.3 = " << ((gap*10)/13) << "\n\n";
        } else{
            cout << "\nSince Gap = 1, Perform Bubble Sort: " << "\n\n";
        }
        
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            cout << "Pass with gap " << ((gap*10)/13) << ": ";
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

int combmain(){
    int n;
    cout << "\t\tComb Sort\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    combSort(arr, n);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
