#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    int pos;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        cout << "Position = " << pos << ":\t";
        for (int x = 0; x < size; x++) {
            if (x == pos) {
                cout << "\033[32m" << arr[x] << "\033[0m ";
            } else {
                cout << arr[x] << " ";
            }
        }
        cout << endl;

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    const int size = 50;
    int target, len;
    int arr[size];

    cout << "\t\tINTERPOLATION SEARCH\n\n";

    cout << "Enter the size of the array: ";
    cin >> len;

    cout << "\nEnter the elements:" << endl;
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    cout << "\nEnter the element to search: ";
    cin >> target;

    int result = interpolationSearch(arr, len, target);

    if (result != -1) {
        cout << "\nElement " << target << " found at index " << result << endl;
    } else {
        cout << "\nElement " << target << " not found in the array." << endl;
    }

    return 0;
}