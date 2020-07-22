#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
struct Queue { 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*)malloc( 
        sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
  
    queue->rear = capacity - 1; 
    queue->array = (int*)malloc( 
        queue->capacity * sizeof(int)); 
    return queue; 
} 
  
void push(struct Queue* queue, int item) 
{ 
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
} 
  

int pop(struct Queue* queue) 
{ 
    
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  

int main()
{
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    if(n == 1){
        printf("1");
        return 0;
    }
    struct Queue* q1 = createQueue(n+1);
    if(c==0){
        for(int i = 1; i <= n; i++){
            push(q1,i);
        }
    }
    else{
        push(q1,1);
        for(int i = n; i > 1; i--){
            push(q1,i);
        }
    }

    while(q1->size != 1){
        for(int i = 0; i < m-1; i++){
            int x = pop(q1);
            push(q1,x);
        }
        pop(q1);
    }
    printf("%d",pop(q1));
}