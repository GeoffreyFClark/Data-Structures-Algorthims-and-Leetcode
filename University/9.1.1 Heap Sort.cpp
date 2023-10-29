// Heapsort

// Problem Statement
// Heapsort is one of the main log-linear (average run-time of O(nlogn)) sorting algorithms. 
// It's based on, as its name suggests, the heap data structure that you worked with earlier in the course.

// The algorithm is as follows:
// 1. Construct a heap (either max or min depending on if you want to sort in ascending/descending order) from input.
// 2. While the size of the heap is greater than 1, swap the root with the last element and reduce the size of our heap by 1 (we will no longer consider the last element we just swapped with as apart of our heap- because it is already sorted).
// 3. Ensure our remaining heap is actually a heap, as the new root could have broken the heap property.
// 4. Go back to step 2

// Your goal for this stepik assignment is to implement the heapify part of the algorithm (step 3) with an array-based implementation of a max heap. 
// Your inputs to the function will be a reference to the original data set, the size of the heap, and additional integer parameter that serves as the index of a node.
// You MUST make a recursive solution that uses all of these parameters in order to ensure your code will work with the test cases.

// Test Cases
// Different sets of integers will be inputted 
// The output is just expecting the array to be correctly sorted afterwards

// Note
// You are only being asked to build the heapify part of heapsort.
// IMPORTANT: Due to the way this problem's back end was built, you MUST implement a recursive solution that uses the root variable.

// Sample Input:
// 1 7 5 2 3 8 9 10 4 6

// Sample Output:
// 1 2 3 4 5 6 7 8 9 10 

void heapify_down(vector<int>& arr, int size, int root) {
    // assume root is largest (max heap)
    int largest = root;
    // set children indices
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    // Check if L child exists and greater than largest
    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    // Check if R child exists and greater than largest
    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    // If largest is not root, swap. Then heapify again @ subtree affected by swap
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify_down(arr, size, largest);
    }
}
