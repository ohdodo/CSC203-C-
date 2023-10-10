#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INT_MAX = 1000;

// Function to read input elements
vector<int> readElements() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0 || n > 1000) {
        cout << "Invalid input for the number of elements." << endl;
        exit(1);
    }

    vector<int> elements(n);

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    return elements;
}

// Function to sort elements using selection sort
void selectionSort(vector<int>& elements) {
    const int INF = INT_MAX;
    int n = elements.size();

    for (int i = 0; i < n; i++) {
        int minValue = INF;
        int minIndex = -1;

        for (int j = i; j < n; j++) {
            if (elements[j] < minValue) {
                minValue = elements[j];
                minIndex = j;
            }
        } 

        swap(elements[i], elements[minIndex]);
    }
}

// Function to display sorted array and element positions
void displayResults(const vector<int>& elements) {
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }
    cout << endl;

    cout << "Element positions:" << endl;
    for (int i = 0; i < elements.size(); i++) {
        int index = find(elements.begin(), elements.end(), elements[i]) - elements.begin();
        cout << elements[i] << " is in line " << index + 1 << endl;
    }
}

int main() {
    vector<int> elements = readElements();

    selectionSort(elements);

    displayResults(elements);

    return 0;
}
