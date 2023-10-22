// Problem Statement

// Write C++ code for a function, extractMax() that takes as input a max heap, arr represented as an integer array and the size of the array, size. 
// The function deletes the maximum element in the max heap and returns the new max heap array after deletion.

// Constraints
// size >= 1
// The array passed into the extractMax() satisfies the max heap constraints.
// All elements are unique.

// Sample Input
// 3
// 9 8 7

// Sample Output
// 8 7

// Explanation
// Input: Line 1 denotes the number of elements, size in the heap. Line 2 denotes the contents of the max heap that is passed into extractMax() function.
// Output: Output is the max heap after deletion.


#include <iostream>

void maxHeapify(int arr[], int size, int i) {
    // i == current node index, initially assumed as largest
    // Also initialize indices of largest's left and right children
    int largest = i; 
    int left = 2*i + 1;
    int right = 2*i + 2;

    // If left child exists and is greater than largest, set as largest
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // If right child exists and is greater than largest, set as largest
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is no longer i, then max-heap constraints violated at node i
    // Swap current node with largest child to fix
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // After swap, the subtree of largest child may violate max-heap constraints
        // Recursively call maxHeapify on it to fix subtree
        maxHeapify(arr, size, largest);
    }
}

// Can't simply delete the root and return array as this could of course violate max-heap property
int* extractMax(int arr[], int size) {
    if (size == 1) {        
        // The main function in this lab evidently takes care of excluding the last element
        return arr;
    }

    // Delete first element (largest one) by replacing with the last element of the array.
    arr[0] = arr[size - 1];

    // maxHeapify helper function to restore max-heap property starting from the root.
    maxHeapify(arr, size - 1, 0);
	
    return arr; 
}
