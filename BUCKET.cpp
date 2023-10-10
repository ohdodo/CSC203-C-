#include <iostream>
using namespace std;

// Function to perform the Bucket Sort
void bucketSort(int arr[], int n, int gap) {
    int max_value = arr[0];
    int min_value = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }

    int range = max_value - min_value + 1;
    int bucket_count = (range + gap - 1) / gap;
    int* buckets[bucket_count];

    // Initialize buckets
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = new int[n];
    }

    int bucket_sizes[bucket_count] = {0};

    // Scatter elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_value) / gap;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    cout << "Scatter Step:" << endl;
    for (int i = 0; i < bucket_count; i++) {
        int bucketMin = i * gap + min_value;
        int bucketMax = (i + 1) * gap + min_value -1;
         cout << "\033[31mBucket " << bucketMin << " - " << bucketMax << ":\033[0m";
        for (int j = 0; j < bucket_sizes[i]; j++) {
            cout << buckets[i][j] << "\t\t";
        }
        cout << endl;
    }

    // Sort individual buckets (using any sorting algorithm)
    for (int i = 0; i < bucket_count; i++) {
        // Use insertion sort for simplicity, you can replace it with other sorting algorithms
        for (int j = 1; j < bucket_sizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    cout << "\nSort Step:" << endl;
    for (int i = 0; i < bucket_count; i++) {
        int bucketMin = i * gap + min_value;
        int bucketMax = (i + 1) * gap + min_value -1;
       cout << "\x1b[32mBucket " << bucketMin << " - " << bucketMax << ":\x1b[0m";
        for (int j = 0; j < bucket_sizes[i]; j++) {
            cout << buckets[i][j] << "\t\t";
        }
        cout << endl;
    }

    // Gather sorted elements back into the original array
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        delete[] buckets[i];
    }

    cout << "\nGather Step:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int bucketmain() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int gap;
    cout << "Enter the gap per bucket: ";
    cin >> gap;

    bucketSort(arr, n, gap);

    cout << "\nSorted Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
