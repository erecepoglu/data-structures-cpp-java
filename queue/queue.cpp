#include <iostream>

template<typename T>
class Queue{
private:
    int front;
    int rear;
    int size;
    T* arr;
public:
    Queue(){
        front = rear = -1;
        size = 7;
        arr = new T[size];
    }
    Queue(int size){
        front = rear = -1;
        this->size = size;
        arr = new T[size];
    }
    ~Queue(){
        delete[] arr;
    }
    void enqueue(T item);
    T dequeue();
    void display();
};
template<typename T>
void Queue<T>::enqueue(T item){
    if(rear == size - 1){
        std::cout << "Queue full" << std::endl;
    }else{
        arr[++rear] = item;
    }
}
template<typename T>
T Queue<T>::dequeue(){
    T item;
    if(front == rear){
        std::cout << "Queue is empty"<< std::endl;
    }else{
        item = arr[front++];
    }
    return item;
}
template<typename T>
void Queue<T>::display(){
    for(int i = front + 1; i <=rear; i++){
        std::cout<<arr[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    Queue<int> queue(9);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.display();

    std::cout << "After dequeuing" << std::endl;
    queue.dequeue();
    queue.display();

}