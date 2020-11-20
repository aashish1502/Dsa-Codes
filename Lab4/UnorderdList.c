#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct ArrayList
{
    int capacity;
    int *array ;
    int rear;
};

struct ArrayList *CreateList(int size)
{
    struct ArrayList *List = malloc(sizeof(struct ArrayList));
    
    if(!List)
        return NULL;
    
    List->capacity = size;
    List->array = malloc(sizeof(int) * List->capacity);
    List->rear = -1;

}

int IsFullList(struct ArrayList *List)
{
    if(List->rear == List->capacity - 1)
        return 1;
    else
        return 0;
}

int IsEmptyList(struct ArrayList *List)
{
    if(List->rear == -1)
        return 1;
    else
        return 0;
}


void Insert(struct ArrayList *List,int data,int position)
{
    if(IsFullList(List))
    {
        printf("The List is full!!\n");
    }
    else if(position > List->rear+1)   
    {
        printf("The position does not exist in the list.");
    }
    else
    {
        int i = position;
        while(i<=List->rear+1 && i>=0)
        {
            List->array[i+1] = List->array[i];
            i++;
        }
        List->array[position] = data;

        List->rear = List->rear+1;

        printf("%i has been inserted in the List at %i position.\n",data,position);
        
    }
    

}


void Delete(struct ArrayList* List,int data)
{
    if(IsEmptyList(List))
    {
        printf("The List is Empty!!\n");
    }
    else
    {
        int i = 0;
        int status = 0; 
        for(i = 0 ; i <= List->rear ; i++)
        {
            if(List->array[i] == data)
            {
                status = 1;
                break;
            }
        }

        if(status == 0)
        {
            printf("The List does not have the element to be deleted!\n");
        }   
        else
        {
            for( ; i <= List->rear ; i++)
            {
                List->array[i] = List->array[i+1];
            }
            printf("The element has been deleted!\n");
            List->rear = List->rear-1;
        }
    }

}

void Search(struct ArrayList *List, int key)
{
    if(IsEmptyList(List))
    {
        printf("The List is Empty!!\n");
    }
    else
    {
        int i = 0;
        int found = 0;
        
        for (i = 0; i <= List->rear; i++)
        {
            if(List->array[i] == key)
            {
                printf("The element is present at the index %i .\n",i);
                found = 1;
            }

        }

        if(found==0)
        {
            printf("There is no such element present in the list.\n");
        }
        
    }
    
}

void DisplayList(struct ArrayList* List)
{
    if(IsEmptyList(List))
    {
        printf("The list is Empty!!\n");
    }
    else
    {
        printf("The elements in the sorted List are: \n");
        int i = 0;
        for(i = 0 ; i <= List->rear;i++)
        {
            printf("%i  ",List->array[i]);
        }
        
        printf("\n");
    }
}


int main(void)
{
    
    struct ArrayList* List = CreateList(MAX);

    int choice = -1;
    int data = 0;
    int position = 0;

    while(choice < 5)
    {
        printf("**********Unsorted List Program********\n");
        printf("\n");
        printf("----------Menu----------\n");
        printf("Select the following expressions to be performed on a Sorted List\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display List\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        

        printf("Please Eneter the choice of operation you would like to perform: ");
        scanf("%i",&choice);


        printf("------------------------\n");

        switch(choice)
        {
        case 1:
            printf("Enter the data to be inserted in the List: ");
            scanf("%i",&data);
            printf("Enter the position to be inserted in the List: ");
            scanf("%i",&position);
            printf("> \t");
            Insert(List,data,position-1);
            break;
        case 2:
            printf("Enter the data to be deleted in the List: ");
            scanf("%i",&data);
            printf("> \t");
            Delete(List,data);
            break;
        case 3:
            printf("> \t");
            DisplayList(List);
            break; 
        case 4:
            printf("Enter the data you want to find in the List: ");
            scanf("%i",&data);
            printf("> \t");
            Search(List,data);  
        }

        printf("------------------------\n");
        printf("\n \n");

    }
}

