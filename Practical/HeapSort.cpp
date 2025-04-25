#include<iostream>
using namespace std;


//  Logic 

//  [i]  Bulid Max Heap for given array of "n" Elements
//  [ii]  Dlt max from max heap of arr[1,.....,i]  && place deleted element at a[i]  where i = n to 2 ;
//  HeapSort is only applicable for only Complete Binary Tree .
//  [Complete Binary Tree +  Parents >= All descendent  ]  For max Heap .

class Array {
public:
    int* arr;
    int size;
    int currentSize;

    Array(int Size) {
        size = Size;
        arr = new int[size];
        currentSize = 0;
    }
    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Enter value for index " << (i + 1) << ": ";
            cin >> arr[i];
        }
        currentSize = size;
    }
    void heapifyDown(int i, int n) {
        int largest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < n && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        if (rightChild < n && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest, n);
        }
    }

    void buildMaxHeap() {
        for (int i = (currentSize / 2) - 1; i >= 0; i--) {
            heapifyDown(i, currentSize);
        }
    }

    void heapSort() {
        buildMaxHeap();
        for (int i = currentSize - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyDown(0, i);
        }
    }
    void display() {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr(12);
    arr.input();
    
    cout << "\nBefore Sorting (Max Heap): ";
    arr.buildMaxHeap();
    arr.display();

    cout << "\nAfter Heap Sort: ";
    arr.heapSort();
    arr.display();

    return 0;
}

//  Time Complexity : O(n log n).
//  Space Complexity : O(1) (excluding the space required for the input array).
//  Heap Sort Property 
//  Stable :- No 
//  Inplace :- Yes