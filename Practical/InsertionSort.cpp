#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    int com = 0;
    int shift = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shift++;
            com++; 
        }
        if (j >= 0) com++; 
        arr[j + 1] = key;
    }

    cout << "\nTotal comparisons: " << com;
    cout << "\nTotal shifts: " << shift << "\n";
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 6, 1, 8, 6, 2, 1, 0, 3};

    insertionSort(arr);  
    printArray(arr);  

    return 0;
}
