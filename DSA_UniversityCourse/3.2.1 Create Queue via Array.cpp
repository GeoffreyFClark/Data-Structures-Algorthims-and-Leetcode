// ​Array-based Implementation of Queue

// Problem Statement
// A naive array-based implementation of a queue causes a rightward drift problem. 
// Rightward drift can cause a queue-full condition even when the queue contains few entries. 
// One possible solution to this problem is to shift array entries to the left after each removal from the queue. 
// However, shifting entries after each removal is not really satisfactory as it is not efficient. 
// A much more elegant solution is viewing the array as circular. 
https://ucarecdn.com/61008049-26f5-4c21-b16e-4ee377a62e5b/-/crop/306x300/47,34/-/preview/

// front: the index of the front entry. Its initial value is 0 when the queue is empty.
// back: the index of the back entry. Its initial value is CAPACITY - 1 when the queue is empty.
// CAPACITY: the maximum size of the queue.
// The following figure illustrates the effect of three queue operations on front, back, and the array. 
https://ucarecdn.com/8f158b8a-7e6b-4f6b-90a9-19be5985562d/

// Note that front and back advance clockwise around the array.
// When either front or back advances past CAPACITY, it should wrap around to 0. This wraparound eliminates the problem of rightward drift because the circular array has no end.
// You can obtain the wraparound effect of a circular queue by using % arithmetic operator in C++ when incrementing front and back. e.g. you can add new entry to the end of the queue by using the following statement:
// back = (back + 1) % CAPACITY;

// Implement the following operations of a queue using a circular array.
// isEmpty(): return whether the queue is empty.
// enqueue(x): add the element x to the back of queue.
// dequeue(): remove the element from the front of queue.
// peekFront(): get the front element in the queue.

// Note
// The CAPACITY of the circular array is defined. 
// You could directly use the CAPACITY as a constant in your implementation.
// You just need to complete the circular-array based implementation. 
// We will be testing your code and implementing the main( ) function. 

// Test Cases
// The first line of the input is the operation we will be calling on your CircularArrayQueue object.
// The second line of input is the parameters that are passed to the corresponding operation in Line 1.
// The Output is the return value of the function call to the corresponding operation in Line 1. 
// Null in output means the function doesn't return anything. They are of type void. 
// You may assume that all operations are valid (e.g. no dequeue or peekFront operations will be called on an empty queue)

// Sample Input:
// [enqueue,enqueue,dequeue,peekFront,isEmpty]
// [[23],[1],[],[],[],[]]

// Sample Output:
// [null, null, null, 1, false]