#include <iostream>
using namespace std;

int binarymain(int arr[], int n) {
    cout << "\t\t BINARY SEARCH\n\n";
    arr[n];
    int search;

    cout << "\nArray: " << endl;
    for (int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }

    cout << "\n\nElement to search: ";
    cin >> search;

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        cout << "mid = " << low << " + (" << high << " - " << low << ") / 2" << endl;
        cout << "nmid = " << arr[mid] << ":\n";

        if (arr[mid] == search) {
            cout << "\t" << arr[mid] << " == " << search << "\t\t";

            for (int i = 0; i < n; i++) {
                if (arr[i] == arr[mid]) {
                    cout << "\033[31m" << arr[i] << "\033[0m ";
                } else {
                    cout << arr[i] << " ";
                }
            }

            cout << "\n\n" << search << " is found at index " << mid;
            return 0;
        } else {
            cout << "\t" << arr[mid] << " != " << search << "\t\t";

            for (int i = 0; i < n; i++) {
                if (arr[i] == arr[mid]) {
                    cout << "\033[31m" << arr[i] << "\033[0m ";
                } else {
                    cout << arr[i] << " ";
                }
            }
        }

        if (arr[mid] < search)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << endl << endl << search << " is not found in the array" << endl;
    return 0;
}