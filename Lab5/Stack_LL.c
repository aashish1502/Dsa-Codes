#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Stack *next;
};

struct Stack{
    struct Node *top;
};

struct Stack* CreateStack()
{
    struct Stack *stk;
    stk = malloc(sizeof(struct Stack));
    stk->top = NULL;
    return stk;
}

void Push(struct Stack *stk,int data)
{
    struct Node *temp;
    temp = malloc(sizeof(struct Node));

    if(!temp)
    {
        printf("Memoy Error!!\n");
    }

    temp->data = data;
    temp->next=stk->top;

    stk->top = temp;

}

int isEmptyStack(struct Stack *stk)
{
    return stk->top == NULL;
}

void Pop(struct Stack *stk){
    int data;
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
   
    if(isEmptyStack(stk))   
        printf("The stack is empty!\n");
    
    else
    {
        
        temp = stk->top;
        stk->top = stk->top->next;
        data = temp->data;
        printf("The element %i is popped\n",data);
        free(temp);
    
    }

}

void Peek(struct Stack* stk)
{
    if(isEmptyStack(stk))
    {
        printf("Stack is Empty!");
    }
    else
    {
        printf("The top of the stack is %i\n",stk->top->data);
    }
    
}

void DisplayStack(struct Stack *stk)
{

    if(isEmptyStack(stk))
    {
        printf("Stack is Empty!");
    }
    else
    {
        struct Node* temp;
        temp = stk->top;

        while(temp != NULL)
        {
            printf("%i ",temp->data);
            temp = temp->next;
        }

        printf("\n");


    }
    
}


int main(void)
{
    struct Stack *stk = CreateStack();


    int choice = -1;
    int data = 0;

    while(choice < 5)
    {
        printf("**********Stack using Linked List Program********\n");
        printf("\n");
        printf("----------Menu----------\n");
        printf("Select the following expressions to be performed on a Stack\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Dispaly Stack\n");
        printf("5. Exit\n");
        

        printf("Please Eneter the choice of operation you would like to perform: ");
        scanf("%i",&choice);


        printf("------------------------\n");

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted in the stack: ");
            scanf("%i",&data);
            Push(stk,data);
            break;
        case 2:
            Pop(stk);
            break;
        case 3:
            Peek(stk);
            break;   
        case 4:
            DisplayStack(stk);
            break;
        }
        
        

        printf("------------------------\n");
        printf("\n \n");

    }


}
