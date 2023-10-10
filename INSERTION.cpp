#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Compare and swap elements of arr[0..i-1] with key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            

            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;      

            j--;      
            
            // Print the current state of the array during comparison
             arr[j + 1] = key;
             
           if (key < arr[j + 2]){
                cout << arr[j+2] << " > " << key << " , so swap\t\t\t";
             } else if (key > arr[j + 2]){
                cout << arr[j+2] << " < " << key << " , so swap\t\t\t";
             }


            for (int k = 0; k < n; k++) {
                if (k == j + 1) {
                    cout << "[" << arr[k] << "]";
                } else if (k == j + 2) {
                    cout << "[" << arr[k] << "]";
                }
                else {
                    cout << arr[k] << " ";
                }
            }
            cout << endl;
        }


        // Print the current state of the array after placing key in its correct position
        cout << "No Swap\t\t\t\t\t";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int insertionmain() {
    cout << "\t\tInsertion Sort\n";
    
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
