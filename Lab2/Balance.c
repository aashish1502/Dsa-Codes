#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


struct Stack
{
    int top;
    int capacity;
    char *array;
};

struct Stack *CreateStack(int n)
{
    struct Stack *S = malloc(sizeof(struct Stack));

    if(!S)
    return NULL;

    S->capacity = n;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));

    if(! S->array)
    return NULL;

    return S;
}

void Push(struct Stack *S,char data)
{
    S->array[++S->top] = data;
}

char Pop(struct Stack *S)
{
    if(IsEmptyStack(S))
        return (char)'1';
    else
        return S->array[S->top--];

}

int IsEmptyStack(struct Stack *S)
{
    if(S->top ==-1)
        return 1;
    else
        return 0;
}

char Peek(struct Stack *S)
{
    if(IsEmptyStack(S))
    return'F';
    else
    return (S->array[S->top]);

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
            printf("%c ",S->array[i]);
        }
        printf("\n");
    }
}


int isCompatible(char symbol , struct Stack* S)
{
    if(symbol == ')' && Peek(S) == '(')
    {
        return 1;
    }
    else if (symbol == '}' && Peek(S) == '{' )
    {
        return 1;
    }
    else if (symbol == ']' && Peek(S) == '[' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
    
}

int isValid(struct Stack* S ,char infix_exp[])
{

    int i = 0 ;
    int j = 0 ;
    char x ='a';

    printf("The stack operations are as follows: \n");

    while(infix_exp[i]!='\0')
    {

        DisplayStack(S);

        if(infix_exp[i] == '(' || infix_exp[i] == '{' || infix_exp[i] == '[')
        {
            Push(S,infix_exp[i]);
        }        
        else if(infix_exp[i] == ')' || infix_exp[i] == '}' || infix_exp[i] == ']')
        {
            if(isCompatible(infix_exp[i],S))
            {
                Pop(S);
            }
            else
            {
                return 0 ;
            }
            
        }
        i++;
    }
    
    if(!IsEmptyStack(S))
        return 0;
    
    return 1;


}



int main(void)
{


    printf("Please Enter an infix expression\n");
    char str[100];
    scanf("%s",str);
    int n = 0;

    while(str[n] != '\0')
    {
        n++;
    }
    
	struct Stack* stack = CreateStack(n);
    
    if(isValid(stack,str))
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");
    


}
