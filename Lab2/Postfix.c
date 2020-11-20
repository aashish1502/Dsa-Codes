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


int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	    return 0;
	}
}


int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void ConvertToPostfix(struct Stack* S ,char infix_exp[], char postfix_exp[])
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
        else if(isalpha(infix_exp[i]) || isdigit(infix_exp[i]))
        {
            postfix_exp[j] = infix_exp[i];
            j++;
        }
        else if(is_operator(infix_exp[i]))
        {
            if(precedence(Peek(S)) >= precedence(infix_exp[i]))
            {
                while(precedence(Peek(S)) >= precedence(infix_exp[i]))
                {
                    x=Pop(S);
                    postfix_exp[j]  = x ;
                    j++;

                }
                Push(S,infix_exp[i]);

            }
            else
            {
                Push(S,infix_exp[i]);
            }

        }
        else if(infix_exp[i] == ')' || infix_exp[i] == '}' || infix_exp[i] == ']')
        {
            while(Peek(S) != '(' || Peek(S) == '{' || Peek(S) == '[')
            {
                x=Pop(S);
                postfix_exp[j]  = x ;
                j++;
            }
            Pop(S);
        }
        DisplayStack(S);
        i++;
    }
    while(!IsEmptyStack(S))
    {

        postfix_exp[j] = Pop(S);
        j++;
    }

    DisplayStack(S);
    postfix_exp[j+1]='\0';

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
    char postfix[n];
	struct Stack* stack = CreateStack(n);
    ConvertToPostfix(stack , str , postfix);
    int i=0;
    printf("\n");

    printf("The postfix expression is: ");
    while(postfix[i]!='\0')
    {
        printf("%c",postfix[i]);
        i++;
    }




}
