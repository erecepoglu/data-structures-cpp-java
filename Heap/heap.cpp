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
int main(){

}
