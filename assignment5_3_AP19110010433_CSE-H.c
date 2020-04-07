
//Implement a queue using two stacks
#include <stdio.h> 
#include <stdlib.h> 
  

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Push function prototype
void push(struct Node** top, int new_data); 
  
//Pop function prototype
int pop(struct Node** top); 
  
//structure of queue 
struct queue { 
    struct Node* stack_1; 
    struct Node* stack_2; 
}; 
  
//Function to insert an item into queue 
void enQueue(struct queue* q, int x) 
{ 
    push(&q->stack_1, x); 
} 
  
//Function to delete an item from queue 
int deQueue(struct queue* q) 
{ 
    int x; 
    if (q->stack_1 == NULL && q->stack_2 == NULL) { 
        printf("Queue is empty"); 
        getchar(); 
        exit(0); 
    } 
  
    if (q->stack_2 == NULL) { 
        while (q->stack_1 != NULL) { 
            x = pop(&q->stack_1); 
            push(&q->stack_2, x); 
        } 
    } 
  
    x = pop(&q->stack_2); 
    return x; 
} 
  
//Function to push an item into stack
void push(struct Node** top, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    if (new_node == NULL) { 
        printf("Stack overflow \n"); 
        getchar(); 
        exit(0); 
    } 
  
    new_node->data = new_data; 
    new_node->next = (*top); 
  
    (*top) = new_node; 
} 
  
//Function to pop an item from stack
int pop(struct Node** top) 
{ 
    int res; 
    struct Node* top_1; 
 
    if (*top == NULL) { 
        printf("Stack underflow \n"); 
        getchar(); 
        exit(0); 
    } 
    else { 
        top_1 = *top; 
        res = top_1->data; 
        *top= top_1->next; 
        free(top_1); 
        return res; 
    } 
} 
  

int main() 
{ 
    struct queue* q = (struct queue*)malloc(sizeof(struct queue)); 
    q->stack_1 = NULL; 
    q->stack_2 = NULL; 
    enQueue(q, 12); 
    enQueue(q, 24); 
    enQueue(q, 36);
    enQueue(q, 48);
    enQueue(q, 60); 
  
    // Dequeue items
    printf("%d ", deQueue(q)); 
    printf("%d ", deQueue(q)); 
    printf("%d ", deQueue(q)); 
   printf("%d ", deQueue(q));
   printf("%d ", deQueue(q));
    return 0; 
} 

