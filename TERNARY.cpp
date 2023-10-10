#include <iostream>
using namespace std;

// Function to print the array with brackets around mid1 and mid2
void printArray(int arr[], int left, int right, int mid1, int mid2) {
    for (int i = left; i <= right; i++) {
        if (i == mid1 || i == mid2) {
            cout << "\033[31m" << arr[i] << "\033[0m";
        } else {
            cout << arr[i];
        }

        if (i < right) {
            cout << " ";
        }
    }
}

int ternarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {

        int mid1 = (right - left) / 3 + left;
        int mid2 = 2 * (right - left) / 3 + left;

        cout << "\nSearching in range [" << left << " to " << right << "]\n\n";
        cout << "Mid 1 = (high - low) / 3 + low" << endl;
        cout << "Mid 1 = (" << right << " - " << left << ") / 3 + " << left << endl;
        cout << "Mid 1 = " << mid1 <<endl << endl;
        cout << "Mid 2 = 2 * (high - low) / 3 + low" << endl;
        cout << "Mid 2 = 2 * (" << right << " - " << left << ") / 3 + " << left << endl;
        cout << "Mid 2 = " << mid2 <<endl;
        cout << "Midpoints: (" << arr[mid1] << ") and (" << arr[mid2] << ")\n\n";
        cout << "Array: \t";
        printArray(arr, left, right, mid1, mid2);
    
        if (arr[mid1] == target) {
            return mid1;
        } if (arr[mid2] == target) {
            return mid2;
        }

        if (target < arr[mid1]) {
           cout <<"\n" << target << " < " << arr[mid1];
            cout << "\nSearching in the left segment\n\n";
            return ternarySearch(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            cout << "\n" << target << " > " << arr[mid2];
            cout << "\nSearching in the right segment\n";
            return ternarySearch(arr, mid2 + 1, right, target);
        } else {
             cout << "\n" << arr[mid1] << " < " <<  target << " < " << arr[mid2];
            cout << "\nSearching in the middle segment\n\n";
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }

    return -1;
}

int ternarymain(int arr[], int n) {
    int target;
    arr[n];

    cout << "\t\tTERNARY SEARCH\n\n";
    
    cout << "Array: ";
    for (int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }
    cout << "\n\n";
    
    cout << "\nEnter the element to search: ";
    cin >> target;

    int result = ternarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "\nElement " << "\x1b[32m" << target << "\x1b[0m" <<  " found at index " << "\x1b[32m"<< result << "\x1b[0m" << endl;
    } else {
        cout << "\nElement " << "\033[31m" << target << "\033[0m" << " not found in the array." << endl;
    }

    return 0;
}
