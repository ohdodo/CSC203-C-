#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        cout << " ";
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

void printTree(int arr[], int N, int pass, int current, int maxIndex) {
    int levels = log2(pass);
    int index = 0;
    int level = 0;
    vector<int> printedNodes(N, false);

    while (index <= maxIndex || level == levels) {
        int elementsInLevel = 1 << level;
        int elementsInNextLevel = 1 << (level + 1);
        int spacing = (20 / elementsInLevel) - 1;
        int initialSpacing = (40 / elementsInNextLevel) - 1;

        for (int i = 0; i < elementsInLevel && index <= maxIndex; i++) {
            if (!printedNodes[index]) {
                cout << setw(initialSpacing) << " ";
                if (index == current || (level == 0 && i == 0)) {
                    cout << "[" << arr[index] << "]";
                } else {
                    cout << " " << arr[index] << " ";
                }
                cout << setw(spacing) << " ";
                printedNodes[index] = true;
            }
            index++;
        }
        cout << endl << endl;
        level++;
    }
    cout << "\n\n\n\n\n\n";
}

void heapify(int arr[], int N, int i, bool maxHeap, int pass) {
    int largestOrSmallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N) {
        if ((maxHeap && arr[left] > arr[largestOrSmallest]) ||
            (!maxHeap && arr[left] < arr[largestOrSmallest])) {
            largestOrSmallest = left;
        }
    }

    if (right < N) {
        if ((maxHeap && arr[right] > arr[largestOrSmallest]) ||
            (!maxHeap && arr[right] < arr[largestOrSmallest])) {
            largestOrSmallest = right;
        }
    }

    if (largestOrSmallest != i) {
        swap(arr[i], arr[largestOrSmallest]);
        printTree(arr, N, pass, i, N - 1);
        heapify(arr, N, largestOrSmallest, maxHeap, pass);
    }
}

void heapSort(int arr[], int N, bool maxHeap) {
    int pass = 1;
        printTree(arr, N, pass, 0, N - 1);


    // Build the heap from the array
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i, maxHeap, pass);
    }


    for (int i = N - 1; i > 0; i--) {
        printTree(arr, N, pass, 0, i); // Display the tree after swapping
        swap(arr[0], arr[i]);
        pass++;
        heapify(arr, i, 0, maxHeap, pass);
    }

    // Display the last remaining element before it's removed
    printTree(arr, N, pass, 0, 0);

    // Display the sorted array
    cout << "Sorted array is:\n";
    if (maxHeap) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = N - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}



int heapmain(int arr[], int N) {
    int size, pass;
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = -1; // Initialize with -1 to indicate empty nodes
    }

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bool maxHeap;
    cout << "\n\t[0] Min Heap Sort\n\t[1] Max Heap Sort\n";
    cin >> maxHeap;

    if(maxHeap == 1 ) cout<<"\n\t\tMAX HEAP SORT\n\n";
    else cout<<"\n\t\tMIN HEAP SORT\n\n";


    // Function call
    cout << "\nHeap Sort Steps:" << endl;
    heapSort(arr, size, maxHeap);

    return 0;
}