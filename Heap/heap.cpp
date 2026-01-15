#include <iostream>
#include <algorithm> // for std::swap

// Standard Sift-Up for Max Heap
void insert(int arr[], int n){
    int temp = arr[n];
    int i = n;
    while(i > 1 && temp > arr[i/2]){
        arr[i] = arr[i/2];
        i /= 2;
    }
    arr[i] = temp;
}

void createHeap(int arr[], int n){
    // i starts at 2 because a single element (index 1) is already a heap
    for(int i = 2; i <= n; i++){
        insert(arr, i);
    }
}

// Function to delete root and place it at the end (Heap Sort step)
void deleteHeap(int arr[], int n){
    int val = arr[1];  // Save the max value
    arr[1] = arr[n];   // Move last element to root
    arr[n] = val;      // Store max value at the end (optional, for sorting)
    
    // Logic to fix the heap (Sift-Down)
    int i = 1;
    int j = 2 * i;
    
    // FIX: Condition must allow reaching the last valid index
    // Using (n-1) here because the nth element is now "sorted/removed"
    // We only sift down within the remaining active heap (1 to n-1)
    int currentHeapSize = n - 1; 

    while(j <= currentHeapSize){
        // Find the larger child
        // Ensure (j+1) exists before comparing
        if(j < currentHeapSize && arr[j+1] > arr[j]){
            j = j + 1;
        }
        
        // Compare Parent with Largest Child
        if(arr[i] < arr[j]){
            std::swap(arr[i], arr[j]); // Use std::swap
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

int main(){
    // Array size is 8. Indices 0..7.
    // We treat Index 0 as dummy. Data is 1..7.
    int array[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int size = sizeof(array)/sizeof(array[0]); 
    
    // Valid heap data is indices 1 to 7. 
    // "n" should be 7 (the number of active elements).
    int n = size - 1; 

    std::cout << "Original: ";
    for(int i = 1; i <= n; i++) std::cout << array[i] << " ";
    std::cout << "\n";

    createHeap(array, n);

    std::cout << "Max Heap: ";
    for(int i = 1; i <= n; i++) std::cout << array[i] << " ";
    std::cout << "\n";

    // Delete Max (Logic essentially performs one step of Heap Sort)
    deleteHeap(array, n);

    std::cout << "After Delete (Max moved to end): ";
    for(int i = 1; i <= n; i++) std::cout << array[i] << " ";
    std::cout << "\n";
    
    return 0;
}