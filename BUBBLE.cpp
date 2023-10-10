#include <iostream>
using namespace std;

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
            cout << "\x1b[32m" << arr[k]<<"\x1b[0m ";
        } else if(k == x+1){
            cout << "\x1b[32m" << arr[k]<<"\x1b[0m ";
        } else{
            cout<< arr[k]<<" ";
        }
    }
        cout<<endl;
}
int bubblemain(){
        const int MAX_SIZE = 1000;
        int arr[MAX_SIZE], n;

        cout << "\t\tBubble Sort\n";
        cout<<"Number of elements in an array: ";
        cin>>n;

    cout<<"Enter "<< n <<" elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
}
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