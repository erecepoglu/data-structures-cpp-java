#include <iostream>

void insert(int arr[], int n){
    //O(log_n)
    int temp = arr[n], i = n;
    while(i>1 && temp > arr[i/2]){
        arr[i] = arr[i/2];
        i /= 2;
    }
    arr[i] = temp;
}
void createHeap(int arr[],int n){
    for(int i = 2; i <= n; i++){
        insert(arr,i);
    }
}
int main(){
    int array[] = {0,10,20,30,25,5,40,35};
    int size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    createHeap(array,size);
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
