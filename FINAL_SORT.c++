#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

//for tournament sort
double negative_infinity = -std::numeric_limits<double>::min();

int input(int arr[], int n){
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Compare and swap elements of arr[0..i-1] with key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            

            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;      

            j--;      
            
            // Print the current state of the array during comparison
             arr[j + 1] = key;
             
           if (key < arr[j + 2]){
                cout << arr[j+2] << " > " << key << " , so swap\t\t\t\t";
             } else if (key > arr[j + 2]){
                cout << arr[j+2] << " < " << key << " , so swap\t\t\t\t";
             }


            for (int k = 0; k < n; k++) {
                if (k == j + 1) {
                    cout << "[\033[31m" << arr[k] << "\033[0m]";
                } else if (k == j + 2) {
                    cout << "[\033[31m" << arr[k] << "\033[0m]";
                }
                else {
                    cout << arr[k] << " ";
                }
            }
            cout << endl;
        }


        // Print the current state of the array after placing key in its correct position
        cout << "No Swap\t\t\t\t\t\t";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int insertionmain(int arr[],int n){
    cout << "\t\tInsertion Sort\n";
    arr[n];

    insertionSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << "[" << arr[i] << "]" << " ";
    }
    cout << endl;

    return 0;
}

void merge(int arr[], int left, int mid, int right){
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

void mergeprintArray(int arr[], int left, int right, string label){
    cout << label << " sub-array: ";
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int left, int right, string label){
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Display the current sub-array being divided
        mergeprintArray(arr, left, right, label);

        // Sort the two halves
        mergeSort(arr, left, mid, label + " (Left)");
        mergeSort(arr, mid + 1, right, label + " (Right)");

        // Merge the sorted halves
        merge(arr, left, mid, right);

        // Display the current sub-array being merged
        mergeprintArray(arr, left, right, label);
    }
}

int mergemain(int arr[], int n) {
    cout << "\t\tMerge Sort\n";
    arr[n];

    cout << "Original Array: ";
    mergeprintArray(arr, 0, n - 1, "Main");

    mergeSort(arr, 0, n - 1, "Main");

    cout << "Sorted Array: ";
    mergeprintArray(arr, 0, n - 1, "Main");

    return 0;
}

void qprintArray(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void qprintSubArray(int arr[], int start, int end, int highlight = -1) {
    for (int i = start; i <= end; i++) {
        if (i == highlight) {
            cout << "[" << arr[i] << "] ";
        } else {
            cout << arr[i] << ' ';
        }
    }
    cout << '\n';
}

int qpartition(int arr[], int start, int end) {
    // Pivot is the first element (index 0)
    int pivot = arr[start];

    // Initialize left and right pointers
    int left = start + 1;
    int right = end;

    cout << "\nPartitioning around pivot " << pivot << ":\n";
    cout << "Array: \n";
    qprintSubArray(arr, start, end);

    while (true) {
        // Move the left pointer to the right until finding an element larger than the pivot
        while (left <= right && arr[left] <= pivot) {
            left++;
            qprintSubArray(arr, start, end, left);
        }

        // Move the right pointer to the left until finding an element smaller than the pivot
        while (left <= right && arr[right] > pivot) {
            right--;
            qprintSubArray(arr, start, end, right);
        }

        // If the pointers have crossed, break out of the loop
        if (left > right) {
            break;
        }

        // Output the current state of the array after swapping
        swap(arr[left], arr[right]);
        qprintSubArray(arr, start, end, left);

    }

    // Swap the pivot with the element at arr[right] to put it in its correct position
    swap(arr[start], arr[right]);
    cout << "Pivot " << pivot << " is in its correct position: ";
    qprintSubArray(arr, start, end, right);

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

int quickmain(int arr[], int n){
    cout << "\t\tQuick Sort\n";
    arr[n];

    cout << "\nUnsorted array: ";
    qprintArray(arr, n);
    cout << "\nSorting:\n";
    quickSort(arr, 0, n - 1);
    cout << "\nSorted array: ";
    qprintArray(arr, n);
    return 0;
}

void selectionSort(int arr[], int n){
    for (int i = n - 1; i > 0; i--) {
        int maxIndex = i;

        // Find the maximum element in the unsorted part of the array
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        // Swap the found maximum element with the current element
        swap(arr[i], arr[maxIndex]);

        // Display the current state of the array with the largest element highlighted
        cout << arr [i] << " is the largest:\t\t\t";
        for (int k = 0; k < n; k++) {
            if (k == i)
                cout << "\033[31m"<< arr[k] <<" \033[0m";
            else
                cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int selectionmain(int arr[],int n){
    cout << "\t\tSelection Sort\n";
    arr[n];
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform selection sort
    selectionSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void shellSort(int arr[], int n){
    int gap = n;

    cout << "Initial Array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    while (gap > 1){
        gap = gap / 2; // Divide by 2 for the gap sequence
        if ((gap/2 != 0)){
            cout << "n/2 = " << gap << " / 2 = " << (gap/2) << "\n\n";
        } else{
            cout << "Since Gap = 1, Perform Insertion Sort: " << "\n\n";
        }
        
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            cout << "Pass with gap " << gap << ": ";
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    cout << "[" << arr[k] << "] ";
                } else {
                    cout << arr[k] << " ";
                }
            }
            cout << endl;
        }
    }
}

int shellmain(int arr[], int n){
    cout << "\t\tShell Sort\n";
    arr[n];

    shellSort(arr, n);

    cout << "\n\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

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

    cout << "Scatter Step: " << endl;
    for (int i = 0; i < bucket_count; i++) {
        int bucketMin = i * gap + min_value;
        int bucketMax = (i + 1) * gap + min_value -1;
         cout << "\033[31mBucket [" << bucketMin << " - " << bucketMax << "] :\033[0m ";
        for (int j = 0; j < bucket_sizes[i]; j++) {
            cout << " " << buckets[i][j] << " ";
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

    cout << "\nSort Step: " << endl;
    for (int i = 0; i < bucket_count; i++) {
        int bucketMin = i * gap + min_value;
        int bucketMax = (i + 1) * gap + min_value -1;
       cout << "\x1b[32mBucket [" << bucketMin << " - " << bucketMax << "] :\x1b[0m ";
        for (int j = 0; j < bucket_sizes[i]; j++) {
            cout << "   " << buckets[i][j] << " ";
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

    cout << "\nGather Step: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int bucketmain(int arr[], int n) {
    arr[n];
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

void bblprintArray(int arr[], int n){
        for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
cout<<endl;
}

void bblprintClrTxtS(int arr[], int n, int x){
      for (int k = 0; k < n; k++){
        if(k==x ){
            cout << "\033[31m" << arr[k]<<"\033[0m ";
        } else if(k == x+1){
            cout << "\033[31m" << arr[k]<<"\033[0m ";
        } else{
            cout<< arr[k]<<" ";
        }
    }
        cout<<endl;
}

void bblprintClrTxtNS(int arr[], int n, int x){
      for (int k = 0; k < n; k++){
        if(k==x ){
            cout << "\x1b[32m" << arr[k] << "\x1b[0m ";
        } else if(k == x+1){
            cout << "\x1b[32m" << arr[k] << "\x1b[0m ";
        } else{
            cout<< arr[k]<<" ";
        }
    }
        cout<<endl;
}

int bubblemain(int arr[], int n){
        cout << "\t\tBubble Sort\n";
       arr[n];

        cout<<"Unsorted: ";
        bblprintArray(arr, n);
        bool sorted = false;

        int i = 0; //pass
            while(!sorted){
                sorted = true;
                 cout<<"\n Pass "<<i+1<<": \n\n";

            for(int x =0; x<(n-1); x++){
                if(arr[x] > arr[x+1]){ 
                cout<<arr[x]<<" > "<<arr[x+1] << ", swap"<< "\t\t";
                swap(arr[x], arr[x+1]);
                bblprintClrTxtS(arr, n, x);
                  sorted = false;
            } else if(arr[x] < arr[x+1]){
                cout<<arr[x]<<" < "<<arr[x+1] << ", no swap" << "     \t";
                bblprintClrTxtNS(arr, n, x);
           } 
        }
            if(sorted) break;
             i++;
            }
        cout<<"\nSorted: ";
        bblprintArray(arr, n);

    return 0;
}

void combSort(int arr[], int n) {
    int gap = n;
    cout << "Initial Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    while (gap > 0) {
        gap = ((gap*10)/13); // Divide by 1.3 for the gap sequence
        if (((gap*10)/13) != 0){
            cout << "\nn/1.3 = " << gap << " / 1.3 = " << ((gap*10)/13) << "\n\n";
        } else{
            cout << "\nSince Gap = 1, Perform Bubble Sort: " << "\n\n";
        }
        
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            cout << "Pass with gap " << ((gap*10)/13) << ": ";
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    cout << "[" << arr[k] << "] ";
                } else {
                    cout << arr[k] << " ";
                }
            }
            cout << endl;
        }
    }
}

int combmain(int arr[], int n){
    cout << "\t\tComb Sort\n";
    arr[n];

    combSort(arr, n);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

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
    cout << "\033[31m" << exp <<"'s " << "\033[0m"<< endl;

    radixPrint(arr,n);
    cout << endl;
}

void radixSort(int arr[], int n) {
    int max = findradixMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        radixCountingSort(arr, n, exp);
    }
}

int radixmain(int arr[], int n) {
    cout << "\t\tRadix Sort\t\t\n";
    arr[n];
    
    cout << "Unsorted Array: " << endl;
    radixPrintArray(arr,n);
    cout <<"\n\n";

    radixSort(arr, n);

    cout << "Sorted array: ";
    
    radixPrintArray(arr,n);

    return 0;
}

void heapPrintSpaces(int N) {
    for (int i = 0; i < N; i++)
        cout << " ";
}

void heapPrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

void heapPrintTree(int arr[], int n, int pass, int current, int maxIndex) {
    int levels = log2(pass);
    int index = 0;
    int level = 0;
    vector<int> printedNodes(n, false);

    while (index <= maxIndex || level == levels) {
        int elementsInLevel = 1 << level;
        int elementsInNextLevel = 1 << (level + 1);
        int spacing = (20 / elementsInLevel) - 1;
        int initialSpacing = (40 / elementsInNextLevel) - 1;
        for (int i = 0; i < elementsInLevel && index <= maxIndex; i++) {
            if (!printedNodes[index]) {
                cout << setw(initialSpacing) << " ";
                if (index == current || (level == 0 && i == 0)) {
                    cout << "" << arr[index] << " ";
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

void heapify(int arr[], int n, int i, bool maxHeap, int pass) {
    int largestOrSmallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        if ((maxHeap && arr[left] > arr[largestOrSmallest]) ||
            (!maxHeap && arr[left] < arr[largestOrSmallest])) {
            largestOrSmallest = left;
        }
    }

    if (right < n) {
        if ((maxHeap && arr[right] > arr[largestOrSmallest]) ||
            (!maxHeap && arr[right] < arr[largestOrSmallest])) {
            largestOrSmallest = right;
        }
    }

    if (largestOrSmallest != i) {
        heapPrintTree(arr, n, pass, i, n - 1);
        swap(arr[i], arr[largestOrSmallest]);
        heapify(arr, n, largestOrSmallest, maxHeap, pass);
    }
}

void heapSort(int arr[], int n, bool maxHeap) {
    int pass = 1;
        heapPrintTree(arr, n, pass, 0, n - 1);
    // Build the heap from the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, maxHeap, pass);
    }

    for (int i = n - 1; i > 0; i--) {
        heapPrintTree(arr, n, pass, 0, i); // Display the tree after swapping
        swap(arr[0], arr[i]);
        pass++;
        heapify(arr, i, 0, maxHeap, pass);
    }

    // Display the last remaining element before it's removed
    heapPrintTree(arr, n, pass, 0, 0);

    // Display the sorted array
    cout << "Sorted array is:\n";
    if (maxHeap) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}

int heapmain(int arr[], int n) {
    int pass;
    arr[n];

    for (int i = 0; i < n; i++) {
        arr[i];
    }
    bool maxHeap;
    cout << "\n\tPlease chose the operation you want!\n\t" << "\x1b[35m[0] Min Heap Sort\n\t\x1b[0m" << "\033[31m[1] Max Heap Sort\n\n\t\t\x1b[0m";
    cin >> maxHeap;

    if(maxHeap == 1 ){ 
        cout<< "\033[31m[1] MAX HEAP SORT\n\n\t\t\x1b[0m";
    }else{ 
        cout<< "\x1b[35m[0] MIN HEAP SORT\n\t\x1b[0m";
    }

    cout << "\nHeap Sort Steps:\n" << endl;
    heapSort(arr, n, maxHeap);

    return 0;
}

struct Node {
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item) {
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Stores inorder traversal of the BST in arr[]
void storeSorted(Node *root, int arr[], int &i) {
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

/* A utility function to insert a new Node with given key in BST */
Node *insert(Node *node, int key) {
    /* If the tree is empty, return a new Node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) Node pointer */
    return node;
}

// Function to print the BST in ASCII tree form
void printBST(Node *root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process the right child first
    printBST(root->right, space);

    // Print current node after appropriate spaces
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    // Process the left child
    printBST(root->left, space);
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n) {
    struct Node *root = NULL;

    // Construct the BST
    root = insert(root, arr[0]);
    cout << "Insert" << "\033[31m"<< arr[0] << "\033[0m " << " into the tree: " << endl;
    printBST(root, 0);
    cout << endl;

    for (int i = 1; i < n; i++)
    {
        root = insert(root, arr[i]);
        cout << "Insert" << "\033[31m" << arr[i] << "\033[0m " << " into the tree: " << endl;
        printBST(root, 0);
        cout << endl;
    }

    // Store inorder traversal of the BST in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}

// Driver Program to test above functions
int treemain( int arr[], int n){

    arr[n];
    Node* tree = NULL;
    treeSort(arr, n);

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    return 0;
}

int greatherThan(int i, int j) {
  if (i > j) return i;
  else return j;
}

void printingTree(int arr[], int n, int space) {

    cout << endl << endl;

    for (int i=0; i<space; i++) cout << " ";
    for (int i=0; i<n; i++) {
        if(arr[i] == negative_infinity){
            cout << "-inf";
        } else{
        cout << arr[i] << " ";
        }
        for (int i=0; i<space/2; i++){
        cout << " ";
    }  
    }

}

void arrayInfinity(int arr[], int n, int maximum) {
    cout << endl << endl;
    for (int i=0; i<n; i++) {
        if (arr[i] == maximum)
            arr[i] = negative_infinity;
    }

}

int buildTournamentTree (int arr[], int n, int space) {

    if (n == 1) return arr[n-1];

    if (n%2 != 0 ) {
        n = n + 1;
        arr[n-1] = negative_infinity;
    }

    space = space + n/2;

    int *temp = new int[n/2];
    int index = 0;

    for (int i=0; i<n; i+=2) {
        int greater = greatherThan(arr[i], arr[i+1]);
        temp[index] = greater; index++; 
    }

    int max = buildTournamentTree(temp, n/2, space);
    printingTree(temp, n/2, space*2);
    return max;

}

void tournamentSort(int arr[], int n) {

    int *sortedArray = new int[n];
    for (int i=0; i<n; i++) {

        int maximum = buildTournamentTree(arr, n, 0);
        printingTree(arr, n, n/2);

        sortedArray[i] = maximum;
        arrayInfinity(arr, n, maximum);
    }

    for (int j=0; j<n; j++) {
        arr[j] = sortedArray[j];
    }


}

int tournamentmain(int arr[], int n) {

   arr[n];

    tournamentSort(arr, n);

    cout << "Sorted Array: ";
    for (int i=0; i<n; i++) {
        cout << "\x1b[32m"  << arr[i] << " " << "\x1b[0m" ;
    }

    return 0;
}

int main(){
    int n;
    cout << "Input the amount of elements in the array!" << endl;
    cin >> n;
    int arr[n];
    int choice;
    input(arr, n);

    while (choice != 0 ){ 
    cout << "\n\t\tSORTING ALGORITHMS\t\t\n";
    cout << "\n\t\tPress 0 to Terminate Program!\t\t\n";
    cout << "\t\t[1] Insertion Sort\t\t\n";
    cout << "\t\t[2] Merge Sort\t\t\n";
    cout << "\t\t[3] Quick Sort\t\t\n";
    cout << "\t\t[4] Selection Sort\t\t\n";
    cout << "\t\t[5] Shell Sort\t\t\n";
    cout << "\t\t[6] Bucket Sort\t\t\n";
    cout << "\t\t[7] Bubble Sort\t\t\n";
    cout << "\t\t[8] Comb Sort\t\t\n";
    cout << "\t\t[9] Radix Sort\t\t\n";
    cout << "\t\t[10] Heap Sort\t\t\n";
    cout << "\t\t[11] Tree Sort\t\t\n";
    cout << "\t\t[12] Tournament Sort\t\t\n";

    cout << "\t\t[0] Terminate Program\t\t\n";


    cout << "Insert the number you want to perform: ";
    cin >> choice;

    switch (choice){
        case 1:
        insertionmain(arr, n);
        break;
        case 2:
        mergemain(arr, n);
        break;
        case 3:
        quickmain(arr, n);
        break;
        case 4:
        selectionmain(arr, n);
        break;
        case 5:
        shellmain(arr, n);
        break;
        case 6:
        bucketmain(arr, n);
        break;
        case 7:
        bubblemain(arr, n);
        break;
        case 8:
        combmain(arr, n);
        break;
        case 9:
        radixmain(arr, n);
        break;
        case 10:
        heapmain(arr, n);
        break;
        case 11:
        treemain(arr, n);
        break;
        case 12:
        tournamentmain(arr, n);
        break;
    }
    }
        
        cout << "Thank You for using this program. Exiting now.";
        system("Cls");
        return 0;
}
