#include <iostream>
#include <cmath>
using namespace std;

int input(int arr[], int n){
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
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
    }
        cout << "\nSorted array: ";
        for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        }
        cout << endl;

}

int linearmain(int arr[],int n){

    cout<<"\n\t\tLINEAR SEARCH\n\n";

    arr[n];
    int search;

    cout<<"\nArray: "<<endl;
        for(int x = 0; x<n; x++){
        cout<<arr[x]<<" ";
         }

        cout<<"\n\nElement to search: "; cin>>search;
        for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
        }

    for(int i=0; i<n; i++){
    cout<<"\n\n";
        if(arr[i] == search){
            cout<<search<<" == "<<arr[i]<<":\t\t\t";

              for(int x=0; x<n; x++){
                if(arr[i] == arr[x])
                    cout<<"\033[32m"<<arr[x]<<"\033[0m ";

                else cout<<arr[x]<<" ";
             }
            cout<<"\n\n\t"<<search<<" is found at index "<< i <<endl;
            return 0;
        }
        else if (arr[i] != search){
            cout<<arr[i] << " != "<<search<<":\t\t";
            for(int x=0; x<n; x++){
                if(arr[i] == arr[x]){
                    cout<<"\033[31m"<<arr[x]<<"\033[0m ";
                } else cout<<arr[x]<<" ";
             }
        }
    }
         cout<<"\n\n\t"<<search<<" is not found in the array" << endl;
}

int binarymain(int arr[], int n) {
    cout << "\n\t\t BINARY SEARCH\n\n";
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

        cout << "\n\nmid = " << low << " + (" << high << " - " << low << ") / 2" << endl;
        cout << "mid = index " << mid << endl;
        cout << "mid = " << arr[mid] << ":\n";

        if (arr[mid] == search) {
            cout << "\t" << arr[mid] << " == " << search << "\t\t";

            for (int i = 0; i < n; i++) {
                if (arr[i] == arr[mid]) {
                    cout << "\x1b[32m" << arr[i] << "\x1b[0m";
                } else {
                    cout << arr[i] << " ";
                }
            }

            cout << "\n\n" << search << " is found at index " << mid;
            return 0;
        } else {
            cout << "\t" << arr[mid] << " != " << search << "\t\t\t";

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
        for (int i = 1; i < n; i++){
            cout << "\nJump " << i << endl;
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
}

int jumpmain(int arr[], int n) {
    arr[n]; 
    int search;

    cout << "\n\t\t JUMP SEARCH\n\n";

    cout << "Array: ";
    for (int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }
    cout << "\n\n";

    cout << "Element to search: ";
    cin >> search;

    int result = jumpSearch(arr, n, search);

    if (result != -1) {
        cout << "\nElement " << search << " found at index " << result << endl;
    } else {
        cout << "\nElement " << search << " not found in the array." << endl;
    }

    return 0;
}

int interpolationSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int pos;

    do{
        pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        cout << "\nPosition = [(end - start) / (A[end] - A[start]) * (e - A[start]) ]";
        cout << "\nPosition = [(" << high << " - " << low << ") / (" << arr[high] << " - " << arr[low] << ") * (" << target << " - " << arr[low] << ")]" << endl;
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
            return pos;
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    } while (low <= high && target >= arr[low] && target <= arr[high]);

    return -1;
}

int interpolationmain(int arr[], int n) {
    int target;
    arr[n];

    cout << "\n\t\tINTERPOLATION SEARCH\n\n";
    
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
           cout <<"\n\n" << target << " < " << arr[mid1];
            cout << "\nSearching in the left segment\n\n";
            return ternarySearch(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            cout << "\n\n" << target << " > " << arr[mid2];
            cout << "\nSearching in the right segment\n";
            return ternarySearch(arr, mid2 + 1, right, target);
        } else {
             cout << "\n\n" << arr[mid1] << " < " <<  target << " < " << arr[mid2];
            cout << "\nSearching in the middle segment\n\n";
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }

    return -1;
}

int ternarymain(int arr[], int n) {
    int target;
    arr[n];

    cout << "\n\t\tTERNARY SEARCH\n\n";
    
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

int expBinarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "\nmid = low + (high - low) / 2" << endl;
        cout << "mid = " << left << " + (" << right << " - " << left << ") / 2" << endl;
        cout << "mid = " << mid << endl << endl;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int target) {
  
    int i = 0;
         if(i == 0) {
            if(arr[0] == target){
                cout<<"arr["<< i <<"] == key " << " ?  "<< "\x1b[32m" <<  arr[i] << "\x1b[0m" << " == " << "\x1b[32m" << target<< "\x1b[0m" << ", YES"<<endl;
                return 0;
          }
          else {
                 cout<<"arr["<< i <<"] == key " << " ?  "<< "\033[31m" << arr[i] << "\033[0m" <<" == " << "\033[31m" << target << "\033[0m" <<", NO"<<endl;
          }
         }


     i = 1;
    while (i < n){
         if( i > 0) { 
            if(arr[i] == target){
                cout<<"arr["<< i <<"]  > key " << " ?  " << "\033[31m" << arr[i] << "\033[0m" << " > " << "\033[31m" << target << "\033[0m" <<", NO"<<endl;
                 return i;
            }else if(arr[i] > target){
                 cout<<"arr["<< i <<"]  > key " << " ?  "<<  "\x1b[32m" <<  arr[i] << "\x1b[0m" <<" > " << "\x1b[32m" << target << "\x1b[0m" << ", YES"<<endl;
             return expBinarySearch(arr, i / 2, (i < n) ? i : n - 1, target);
            }
            else{
                 cout<<"arr["<< i <<"]  > key " << " ?  "<< "\033[31m" << arr[i] << "\033[0m" <<" > " << "\033[31m" << target << "\033[0m" <<", NO"<<endl;
            }
             i *= 2;
            }
    } while (i > n){
         cout << "arr[" << i <<"] is not found in the array\n\n";
         return -1;
    }

}

int exponentialmain(int arr[], int n) {
    int target;
    arr[n];

    cout << "\n\t\tEXPONENTIAL SEARCH\n\n";

    cout << "Array: ";
    for (int x = 0; x < n; x++) {
        cout << arr[x] << " ";
    }
    cout << "\n\n";

    cout << "Enter the element to search: ";
    cin >> target;

    int result = exponentialSearch(arr, n, target);

    if (result != -1) {
        cout << "\nElement " << "\x1b[32m" << target << "\x1b[0m" <<  " found at index " << "\x1b[32m"<< result << "\x1b[0m" << endl;
    } else{
        cout << "\nElement " << "\033[31m" << target << "\033[0m" << " not found in the array." << endl;
    }
    return 0;
}

int main(){
    int n;
    cout << "Input the amount of elements in the array: ";
    cin >> n;

    int arr[n];
    int choice;
    input(arr, n);

    while (choice != 0 ){ 
    cout << "\n\n\t\tSearching ALGORITHMS\t\t\n";
    cout << "\n\t\tPress 0 to Terminate Program!\t\t\n";
    cout << "\t\t[1] Linear Search\t\t\n";
    cout << "\t\t[2] Binary Search\t\t\n";
    cout << "\t\t[3] Jump Search\t\t\n";
    cout << "\t\t[4] Interpolation Search\t\t\n";
    cout << "\t\t[5] Ternary Search\t\t\n";
    cout << "\t\t[6] Exponential Search\t\t\n";
    cout << "\t\t[0] Terminate Program\t\t\n";

    cout << "Insert the number you want to perform: ";
    cin >> choice;

    switch (choice){
        case 1:
        linearmain(arr, n);
        break;
        case 2:
        binarymain(arr, n);
        break;
        case 3:
        jumpmain(arr, n);
        break;
        case 4:
        interpolationmain(arr, n);
        break;
        case 5:
        ternarymain(arr, n);
        break;
        case 6:
        exponentialmain(arr, n);
        break;
    }
    }
        
        cout << "Thank You for using this program. Exiting now.";
        system("Cls");
        return 0;
}