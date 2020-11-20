#include<stdio.h>

#define MAX 10

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *CreateStack()
{
    struct Stack *S = malloc(sizeof(struct Stack));
    
    if(!S)
    return NULL;

    S->capacity = MAX;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));

    if(! S->array)
    return NULL;

    return S;
}

int IsEmptyStack(struct Stack *S)
{
    if(S->top ==-1)
        return 1;
    else
        return 0;
}

int IsFullStack(struct Stack *S)
{
    if(S->top == ((S->capacity) - 1))
        return 1;
    else
        return 0;
}

void Push(struct Stack *S,int data)
{
    if(IsFullStack(S))
    {
        printf("Stack Overflow!!!\n");
    }
    else
    {
        S->array[++S->top] = data;
        printf("Pushed %i in the stack!\n",data);
    }
}

void Pop(struct Stack *S)
{
    if(IsEmptyStack(S))
    {
        printf("Stack Underflow!!!\n");
    }
    else
    {
        printf("%i has been popped from the stack\n",S->array[S->top--]);
    }
}

void Peek(struct Stack *S)
{
    if(IsEmptyStack(S))
    {
        printf("There are no elements in the Stack to peek\n");
    }
    else
    {
        printf(" %i is the peek of the stack\n",S->array[S->top]);
    }

}

void DisplayStack(struct Stack *S)
{
    if(IsEmptyStack(S))
    {
        printf("The stack is Empty!\n");
    }
    else
    {
        int i;
        for(i = 0 ; i <=S->top; i++)
        {
            printf("%i ",S->array[i]);
        }
        printf("\n");
    }
}

int main(void)
{	
	struct Stack* stack = CreateStack();
	
    int choice = -1;
    int a =0;

    while(choice <5)
    {
        printf("**********Stack Program********\n");
        printf("----------Menu----------\n");
        printf("Select the following expressions to be performed on a stack\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display stack\n");
        printf("5. Exit\n");
        
        scanf("%i",&choice);

        printf("------------------------\n");

        switch (choice)
        {
        case 1:
            scanf("%i",&a);
            Push(stack,a);
            break;
        case 2:
            Pop(stack);
            
            break;
        case 3:
            Peek(stack);
            break;
        case 4:
            DisplayStack(stack);
            break;
        }
        printf("------------------------\n");
        printf("\n \n");

    }
   
}
