#include <iostream>
#include <algorithm>

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
void deleteHeap(int arr[], int n){
    int x,i,j;
    x = arr[n];
    arr[1] = arr[n];
    i = 1, j = 2 * i;
    while(j <    n -1){
        if(arr[j+1] > arr[j]){
            j = j+1;
        }
        if(arr[i] > arr[j]){
            //std::swap(arr[i],arr[j]);
            swap(&arr[i],&arr[j]);
            i = j;
            j *= 2;
        }else break;
    }
}
void swap(int *num1, int *num2){
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
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
    int num1 = 2, num2 = 3;
    std::cout << "Before swapping using bitwise: \n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    swap(&num1,&num2);
    std::cout << "After swapping using bitwise: \n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
}
