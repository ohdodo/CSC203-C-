#include <iostream>
#include <iomanip>
using namespace std;

// Function to find the maximum element in the array
int findradixMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void radixPrint(int arr[], int n){
    int maxNum = 1;
    int maxVal = findradixMax(arr,n);
    while (maxVal >= 10){
        maxVal /= 10;
        maxNum++;
    }

    for (int i = 0; i < n;i++){
        cout << setw (maxNum) <<setfill('0') << arr[i] << endl;
    }
}

void radixPrintArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

// Function to perform counting sort on the specified digit
void radixCountingSort(int arr[], int n, int exp) {
    const int radix = 10;
    int output[n];
    int count[radix] = {0};

    for (int i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < radix; i++){
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
    cout << "\033[31m" << exp <<"'s " << "\033[0m "<< endl;

    radixPrint(arr,n);
    cout << endl;
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int max = findradixMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        radixCountingSort(arr, n, exp);
    }
}

int radixmain() {
    int n;
    cout << "\t\tRadix Sort\t\t\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Unsorted Array: " << endl;
    radixPrintArray(arr,n);
    cout <<"\n\n";

    radixSort(arr, n);

    cout << "Sorted array: ";
    
    radixPrintArray(arr,n);

    return 0;
}
