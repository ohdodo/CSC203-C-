#include <iostream>
#include <cmath>
using namespace std;

void printArrayWithHighlight(int arr[], int n, int target, int start, int end) {
    for (int i = 0; i < n; i++) {
        if (i >= start && i <= end) {
            cout << "\033[31m" << arr[i] << " \033[0m";
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void printTargetWithHighlight(int arr[], int n, int target, int start, int end) {
    for (int i = 0; i < n; i++) {
        if (i >= start && i <= end) {
            cout << "\x1b[32m" << arr[i] << "\x1b[0m ";
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n); // Calculate the step based on the square root of the array n
    int start = 0;
    int end = min(step, n) - 1; // Initialize the end for the first jump

    cout << "\n\nSquare Root of " << n << " = " << step << endl << endl;

    int pass = 0; // Initialize pass count

    while (end < n) {
        printArrayWithHighlight(arr, n, target, start, end); // Highlight the current jump
        if (arr[end] >= target) {
            // Perform a linear search within the current jump
            for (int i = start; i <= end; i++) {
                if (arr[i] == target) {
                    printTargetWithHighlight(arr, n, target, i, i); // Highlight the found element
                    return i; // Element found at index 'i'
                }
            }
            return -1; // Element not found
        }
        start = end;
        end = min(end + step - 1, n - 1); // Calculate the end of the next jump
        pass++;
    }

    return -1; // Element not found
}

int main(int arr[], int n) {
     arr[n]; 
    int search;

    cout << "\t\t JUMP SEARCH\n\n";

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int x = 0; x < n; x++) {
        cin >> arr[x];
    }

    cout << "Array: ";
    for (int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }
    cout << "\n\n";

    cout << "Element to search: ";
    cin >> search;

    int result = jumpSearch(arr, n, search);

    if (result != -1) {
        cout << "Element " << search << " found at index " << result << endl;
    } else {
        cout << "Element " << search << " not found in the array." << endl;
    }

    return 0;
}
