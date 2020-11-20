#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct ArrayQueue{

    int front,rear;
    int capacity;
    int *array;

};

struct ArrayQueue *Queue(int size)
{
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    if(!Q)
        return NULL;
    
    Q->capacity = size;
    Q->front = -1;
    Q->rear = -1;
    Q->array = malloc(sizeof(int)*Q->capacity);

}

int IsEmptyQueue(struct ArrayQueue *Q)
{
    if(Q->front == -1)
        return 1;
    else
        return 0; 
}

int IsFullQueue(struct ArrayQueue *Q)
{
    if((Q->rear+1)%Q->capacity == Q->front)
        return 1; 
    return 0;  
}

int QueueSize(struct ArrayQueue *Q)
{
    return (Q->capacity - Q->front + Q->rear +1)%Q->capacity;
}

void EnQueue(struct ArrayQueue *Q, int data)
{
    if(IsFullQueue(Q))
    {
        printf("Queue Overflow has occured!\n");
    }
    else
    {
        Q->rear = (Q->rear+1)%Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
        {
            Q->front = Q->rear;
        }
    }
}

void DeQueue(struct ArrayQueue *Q)
{
    int data = 0;
    if(IsEmptyQueue(Q))
    {
        printf("The Queue is empty!\n");
    }
    else
    {
        data = Q->array[Q->front];
        
        if(Q->front == Q-> rear)
        {
            Q->front = Q->rear = -1;
        }
        else
        {
            Q->front = (Q->front+1) % Q->capacity;
        }
        
        printf("The value of the DeQueued Element is : %d \n",data);

    }
    
}

void DisplayQueue(struct ArrayQueue* Q)
{
    if(IsEmptyQueue(Q))
    {
        printf("The queue is empty!\n");
    }
    else
    {
        int i = Q->front;
        printf("The values in the Queue are: ");
        while( i <= Q->rear)
        {
            printf("%i ",Q->array[i]);
            i = (i+1)% Q->capacity;
        }
        printf("\n");
    }
    
}

int main(void)
{

    struct ArrayQueue* Q = Queue(MAX);

    int choice = -1;
    int data = 0;

    while(choice < 4)
    {
        printf("**********Queue Program********\n");
        printf("\n");
        printf("----------Menu----------\n");
        printf("Select the following expressions to be performed on a Queue\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        

        printf("Please Eneter the choice of operation you would like to perform: ");
        scanf("%i",&choice);


        printf("------------------------\n");

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted in the queue: ");
            scanf("%i",&data);
            EnQueue(Q,data);
            break;
        case 2:
            DeQueue(Q);
            break;
        case 3:
            DisplayQueue(Q);
            break;   
        }

        printf("------------------------\n");
        printf("\n \n");

    }
    
}