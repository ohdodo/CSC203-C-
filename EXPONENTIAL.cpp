#include <iostream>
using namespace std;

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
            }
            else if(arr[i] > target){
                 cout<<"arr["<< i <<"]  > key " << " ?  "<<  "\x1b[32m" <<  arr[i] << "\x1b[0m" <<" > " << "\x1b[32m" << target << "\x1b[0m" << ", YES"<<endl;
             return expBinarySearch(arr, i / 2, (i < n) ? i : n - 1, target);

            }
            else{
                 cout<<"arr["<< i <<"]  > key " << " ?  "<< "\033[31m" << arr[i] << "\033[0m" <<" > " << "\033[31m" << target << "\033[0m" <<", NO"<<endl;
            }
             i *= 2;

            }
    }
        

}

int exponentialmain(int arr[], int n) {
    int target;
    arr[n];

    cout << "\t\tEXPONENTIAL SEARCH\n\n";

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
    } else {
        cout << "\nElement " << "\033[31m" << target << "\033[0m" << " not found in the array." << endl;
    }
    return 0;
}