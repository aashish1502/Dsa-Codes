#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *Front;
    struct Node *Rear;
};

struct Queue* CreateQueue()
{
    struct Queue *Q = malloc(sizeof(struct Queue));
    
    if(!Q)
    {
        printf("Memory Error has occured\n");
    }
    else
    {
        Q->Front = Q->Rear = NULL;
    }

}

void Enqueue(struct Queue* Q , int data )
{
    
    struct Node* temp;
    temp = malloc(sizeof(struct Node));
    
    temp -> data = data;
    temp -> next = NULL;

    if(Q->Front == NULL && Q->Rear == NULL)
    {
        Q->Front = temp;
        Q->Rear = temp;
    }
    else
    {
        Q->Rear->next  = temp;
        Q->Rear = temp;
    }

    printf("The value %i has been Enqueued in the queue\n",data);

}

int IsEmptyQueue(struct Queue* Q)
{
    return !(Q->Front);
}

void Dequqe(struct Queue* Q)
{
    if(IsEmptyQueue(Q))
    {
        printf("The queue is Empty!!\n");
    }
    else
    {
        struct Node* temp;
        int data;
        temp = malloc(sizeof(struct Node));
        temp = Q->Front;
        data = Q->Front->data;
        printf(" Value dequeued is %i\n",Q->Front->data);
        Q->Front = Q->Front->next;
        free(temp);
    }
    
}

void DisplayQueue(struct Queue* Q)
{
    if(IsEmptyQueue(Q))
    {
        printf("The queue is Empty!\n");
    }
    else
    {
        struct Node *temp = Q->Front;

        while(temp!=NULL)
        {
            printf("%i ",temp->data);
            temp = temp->next;
        }
        printf("\n");
        
    }
}

void FrontQueue(struct Queue *Q)
{
    
    if(IsEmptyQueue(Q))
        printf("The queue is Empty!\n");
    else
        printf("The Element in the front of the Queue is: %i\n",Q->Front->data);

}


int main()
{

    struct Queue *Q = CreateQueue();
    
    int choice = -1;
    int data = 0;

    while(choice < 5)
    {
        printf("**********Queue using Linked List Program********\n");
        printf("\n");
        printf("----------Menu----------\n");
        printf("Select the following expressions to be performed on a Stack\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front Element\n");
        printf("4. Dispaly Queue\n");
        printf("5. Exit\n");
        

        printf("Please Eneter the choice of operation you would like to perform: ");
        scanf("%i",&choice);


        printf("------------------------\n");

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted in the queue: ");
            scanf("%i",&data);
            Enqueue(Q,data);
            break;
        case 2:
            Dequqe(Q);
            break;
        case 3:
            FrontQueue(Q);
            break;   
        case 4:
            DisplayQueue(Q);
            break;
         }
        
        printf("------------------------\n");
        printf("\n \n");

    }
}