#include <iostream>
using namespace std;


int linearmain(int arr[],int n){

cout<<"\t\tLINEAR SEARCH\n\n";

int arr [n];
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
            cout<<search<<" == "<<arr[i]<<":\t\t";

              for(int x=0; x<n; x++){
                if(arr[i] == arr[x])
                    cout<<"\033[32m"<<arr[x]<<"\033[0m ";

                else cout<<arr[x]<<" ";
             }

            cout<<endl<<endl<<search<<" is found at index "<<i;
            break;
        }
        else{
            cout<<arr[i] << " != "<<search<<":\t\t";
            for(int x=0; x<n; x++){
                if(arr[i] == arr[x])
                    cout<<"\033[31m"<<arr[x]<<"\033[0m ";
                else cout<<arr[x]<<" ";
             }
        }
    }
}