#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeprintArray(int arr[], int left, int right, string label) {
    cout << label << " sub-array: ";
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int left, int right, string label) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Display the current sub-array being divided
        // cout << "Dividing " << label << " sub-array from index " << left << " to " << right << ": ";
        mergeprintArray(arr, left, right, label);

        // Sort the two halves
        mergeSort(arr, left, mid, label + " (Left)");
        mergeSort(arr, mid + 1, right, label + " (Right)");

        // Merge the sorted halves
        merge(arr, left, mid, right);

        // Display the current sub-array being merged
        // cout << "Merging " << label << " sub-array from index " << left << " to " << right << ": ";
        mergeprintArray(arr, left, right, label);
    }
}

int mergemain() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    mergeprintArray(arr, 0, n - 1, "Main");

    mergeSort(arr, 0, n - 1, "Main");

    cout << "Sorted Array: ";
    mergeprintArray(arr, 0, n - 1, "Main");

    return 0;
}
