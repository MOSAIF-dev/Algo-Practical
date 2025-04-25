#include <iostream>
#include <vector>
using namespace std;



int countInversions(vector<int> arr) {
    int inversionCount = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversionCount++;
            }
        }
    }
    return inversionCount;
}

void SelectionSort(vector<int>& arr) {
    int n = arr.size();
    int com = 0;
    int swaps = 0;
    int pass = 0;
    
    int totalInversions = countInversions(arr);  

    for (int i = 0; i < n - 1; i++) {
        int minpos = i;  

        for (int j = i + 1; j < n; j++) {
            com++;  
            if (arr[j] < arr[minpos]) {
                minpos = j;
            }
        }

        if (i != minpos) {
            swap(arr[i], arr[minpos]);
            swaps++;
           
        }
        pass++;
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal Number of Comparisons: " << com;
    cout << "\nTotal Number of Inversions (Before Sorting): " << totalInversions;
    cout << "\nTotal Number of Swaps: " << swaps << "\n";
    cout<<"\nTotal Number of Passes: "<<pass;
}

int main() {
    vector<int> arr = {80,40,30,40,80,30,60,20,25,15};
    SelectionSort(arr);
    return 0;
}
