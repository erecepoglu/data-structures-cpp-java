#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int* q;
};
void enqueue(struct Queue * queue, int x){
    if((queue->rear + 1) % queue->size == queue->front){
        printf("Queue is full");
    }else{
        queue->rear = (queue->rear + 1) % queue->size;
        queue->q[queue->rear] = x;
    }
}
int dequeue(struct Queue* queue){
    int x = -1;
    if(queue->front == queue->rear){
        printf("Queue is empty");
    }else{
        queue->front = (queue->front + 1) % queue->size;
        x = queue->q[queue->front];
    }
    return x;
}
void display(struct Queue * queue){
    int i = queue->front+1;
    do{
        printf("%d ", queue->q[i]);
        i = (i+1) % queue->size;
    }while(i != (queue->rear + 1) % queue->size);
    printf("\n");
}
void createQueue(struct Queue * queue, int size){
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->q = (int*)malloc(queue->size * sizeof(int));
}
int main(){
    struct Queue queue;
    createQueue(&queue,7);
    enqueue(&queue,2); 
    enqueue(&queue,3);
    enqueue(&queue,5); 
    display(&queue);

    printf("After deletion\n");
    dequeue(&queue);
    display(&queue);

}
