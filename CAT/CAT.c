#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

struct Stack{
    struct ListNode *top;
};

struct Stack *createStack(){
    struct Stack *stk;
    stk = malloc(sizeof(struct Stack));
    stk->top = NULL;
    return stk;
}

void push(struct Stack *stk, int data){
    struct ListNode *temp;
    temp = malloc(sizeof(struct ListNode));
    if(!temp){
        printf("\nStack/Heap overflow");
        return;
    }
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}

int size(struct Stack *stk){

    int count = 0;
    struct ListNode *temp;
    if(isEmpty(stk))  
        return 0;
    temp = stk->top;
    while (temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int isEmpty(struct Stack *stk){
    return stk->top == NULL;
}

int pop(struct Stack *stk){
    int data;
    struct ListNode *temp;
    if(isEmpty(stk))   
        return INT_MIN;
    temp = stk->top;
    stk->top = stk->top->next;
    data = temp->data;
    free(temp);
    return data;
}

int peek(struct Stack * stk){
    if(isEmpty(stk))  
        return INT_MIN;
    return stk->top->data;
}

void deleteStack(struct Stack *stk){
    struct ListNode *temp, *p;
    p = stk->top;
    while( p) {
        temp = p->next;
        p = p->next;
        free(temp);
    }
    free(stk);
}

 int main(){
    int i = 0;
    struct Stack *stk = createStack();
    int choice = -1;
    int a =0;
    int vowel[] = {'a','e','i','o','u'};
    char h[100] ;
    char str[100] ;


    printf("**********Stack Program********\n");
    printf("Please enter a string\n");
    scanf("%s",&str);
    printf("the string enterd is: %s",str);
    
    int j = 0 ;
    int vowelFound = 0;
    char sub[100];


    while(str[i]!='\0'){
        vowelFound = 0;
        for(j = 0 ; j < 5 ; j++)
        {
            if(str[i] == vowel[j])
            {
                printf("The Vowel element is: %c\n",str[i]);
                vowelFound = 1;
                break;            
            }
        }

        if(vowelFound == 0){
            push(stk,str[i]);
        }
        else
        {
            push(stk,-1);
        }
        
        i++;
    }
    
    printf("The top substring is: ");
    int x = pop(stk);
    while(x != -1){
        printf("%c",x);
        x = pop(stk);
    }

    return 0;
 }
