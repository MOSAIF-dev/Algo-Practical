#include <iostream>
using namespace std;

class Array {
private:
    int *arr;
    int size;

public:
    Array(int Size) {
        size = Size;
        arr = new int[size];
    }

    ~Array() {
        delete[] arr; 
    }

    void QuickSort(int low, int high) {
        if (low < high) {
            int pivot = Partition(arr, low, high);
            QuickSort(low, pivot - 1);
            QuickSort(pivot + 1, high);
        }
    }

    int Partition(int arr[], int low, int high) {
        int pivot = arr[low];
        int i = low, j = high;

        do {
            do { i++; } while (i <= high && arr[i] <= pivot);
            do { j--; } while (arr[j] > pivot);
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        } while (i < j);

        swap(arr[low], arr[j]);
        return j;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << (i + 1) << ": ";
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Sorted Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int num;
    cout << "Enter the size of the array: ";
    cin >> num;

    if (num <= 0) {
        cout << "Invalid array size. Exiting program." << endl;
        return 0;
    }
    Array obj(num);
    obj.input();
    obj.QuickSort(0, num - 1);
    obj.display();
    return 0;
}
// Recurrence Relation : T(n) = T(n/2) + O(n). Same as Merge Sort but with a different approach. T(n) = O(n log n)
// Space Complexity : O(log n) due to recursive call stack. 
//  Time Complexity: O(n log n) on average, O(n^2) in the worst case

// Quick Sort Algo Property 
//  Stable :- No
//  In-Place :-Yes