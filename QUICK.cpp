#include <iostream>
using namespace std;

void qprintArray(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void qprintSubArray(int arr[], int start, int end){
    for(int i = start; i <= end; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int qpartition(int arr[], int start, int end){
    // Pivot is the first element (index 0)
    int pivot = arr[start];

    // Initialize left and right pointers
    int left = start + 1;
    int right = end;

    cout << "\nPartitioning around pivot " << pivot << ":\n";
    cout << "Array: ";
    qprintSubArray(arr, start, end);

    while (true) {
        // Move the left pointer to the right until finding an element larger than the pivot
        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        // Move the right pointer to the left until finding an element smaller than the pivot
        while (left <= right && arr[right] > pivot) {
            right--;
        }

        // If the pointers have crossed, break out of the loop
        if (left > right) {
            break;
        }

        // Swap arr[left] and arr[right] to ensure smaller elements are on the left
        swap(arr[left], arr[right]);

        // Output the current state of the array after swapping
        cout << "Swap " << arr[left] << " and " << arr[right] << ": ";
        qprintSubArray(arr, start, end);
    }

    // Swap the pivot with the element at arr[right] to put it in its correct position
    swap(arr[start], arr[right]);
    cout << "Pivot " << pivot << " is in its correct position: ";
    qprintSubArray(arr, start, end);

    // Return the index of the pivot
    return right;
}

void quickSort(int arr[], int start, int end){
    // Base case
    if (start >= end)
        return;

    // partition the array, p is partition index
    int p = qpartition(arr, start, end);

    // Recursively sort the left and right parts
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int quickmain(){
    int n;
    cout << "Enter the number of Elements: ";
    cin >> n;
    int arr[n] = {};
    
    cout << "Enter" << n << " number of Elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "\nUnsorted array: ";
    qprintArray(arr, n);
    cout << "\nSorting:\n";
    quickSort(arr, 0, n - 1);
    cout << "\nSorted array: ";
    qprintArray(arr, n);
    return 0;
}
