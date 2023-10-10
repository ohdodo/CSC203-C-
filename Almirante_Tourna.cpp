#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to perform a single pass of tournament sort
void tournamentSortPass(vector<int>& originalArray, vector<int>& sortedArray) {
    int n = originalArray.size();
    vector<int> array = originalArray;
    vector<int> tempArray;
    bool isEliminating = true;
    
    while (sortedArray.size() != n) {
        isEliminating = true;
        array = originalArray;
        
        cout << endl << "PASS ";
        static int iterations = 0;
        iterations++;
        cout << iterations << " (Comparisons and Tree)" << endl << endl;

        int level = 0;
        
        while (isEliminating) {
            int tempArraySize = array.size();
            
            for (int i = 0; i < tempArraySize; i += 2) {
                if (i + 1 < tempArraySize) {
                    if (array[i] > array[i + 1]) {
                        tempArray.push_back(array[i]);
                        cout << "Comparison: " << array[i] << " > " << array[i + 1] << " => Winner: " << array[i] << endl;
                    } else {
                        tempArray.push_back(array[i + 1]);
                        cout << "Comparison: " << array[i] << " < " << array[i + 1] << " => Winner: " << array[i + 1] << endl;
                    }
                } else {
                    tempArray.push_back(array[i]);
                    cout << "Single element: " << array[i] << " (Leaf node)" << endl;
                }
            }
            
            array = tempArray;
            tempArray.clear();
            
            if (array.size() == 1) {
                isEliminating = false;
            }
            
            level++;
        }
        
        int maxVal = array[0];
        sortedArray.push_back(maxVal);
        
        // Replace the max value in the original array with negative infinity
        for (int i = 0; i < n; i++) {
            if (originalArray[i] == maxVal) {
                originalArray[i] = -numeric_limits<int>::infinity();
                break;
            }
        }
    }
}

// Function to run the tournament sort algorithm
void runTournamentSort(vector<int>& array) {
    vector<int> sortedArray;
    
    cout << "Array before sorting: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl << endl;
    
    tournamentSortPass(array, sortedArray);
    
    cout << endl << "Tournament Sort Summary:" << endl;
    cout << "Array after sorting: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> array(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    runTournamentSort(array);
    
    return 0;
}
