#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int pos;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        cout << "\nPosition = [(end - start) / (A[end] - A[start]) * (e - A[start]) ]";
        cout << "\nPosition = [(" << low << " - " << high << ") / (" << arr[high] << " - " << arr[low] << ") * (" << target << " - " << arr[low] << ") ]" << endl;
        cout << "Position = " << pos << ":\t";
        for (int x = 0; x < n; x++) {
            if (x == pos) {
                cout << "\033[31m" << arr[x] << "\033[0m ";
            } else {
                cout << arr[x] << " ";
            }
        }
        cout << endl;

        if (arr[pos] == target)
            // cout << "\n\x1b[32m" << arr[pos]  << "\x1b[0m" << " == " << target << endl; 
            return pos;
        if (arr[pos] < target) {
            // cout << "\n\033[31m" << arr[pos] << "\033[0m" << " != " << target << endl;
            low = pos + 1;
        } else {
            // cout << "\n\033[31m" << arr[pos] << "\033[0m" << " != " << target << endl;
            high = pos - 1;
        }
    }

    return -1;
}

int interpolationmain(int arr[], int n) {
    int target;
    arr[n];

    cout << "\t\tINTERPOLATION SEARCH\n\n";
    
    cout << "Array: ";
    for (int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }
    cout << "\n\n";

    cout << "\nEnter the element to search: ";
    cin >> target;

    int result = interpolationSearch(arr, n, target);

    if (result != -1) {
        cout << "\nElement " << "\x1b[32m" << target << "\x1b[0m" <<  " found at index " << "\x1b[32m"<< result << "\x1b[0m" << endl;
    } else {
        cout << "\nElement " << "\033[31m" << target << "\033[0m" << " not found in the array." << endl;
    }

    return 0;
}