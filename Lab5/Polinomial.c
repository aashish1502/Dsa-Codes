#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int coeff, exp;
    struct node *next;
}*start1 = NULL, *start2 = NULL;


void insert(int c,int e,int ch){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->exp = e;
    
    if(ch==1)
    {
    
      temp->next = start1;
      start1 = temp;
    
    }
    else
    {
    
      temp->next = start2;
      start2 = temp;
    
    }
}

void display(struct node *start,int ch){
    struct node *temp = start;
    if(ch==3)
        printf("Sum: ");
    else if(ch==4)
        printf("Product: ");
    else
        printf("Polynomial %d: ",ch);
    
    while(temp!=NULL)
    {

        if(temp->coeff>=0&&temp!=start)  printf("+%dx^%d",temp->coeff,temp->exp);
        else printf("%dx",temp->coeff);
        temp = temp->next;
    
    }
    
    printf("\n");

}

struct node* add(struct node *p1,struct node *p2){
    struct node *temp1 = p1, *temp2 = p2, *result = NULL;
    
    while(temp1!=NULL)
    {
        
        struct node *temp_r = (struct node*)malloc(sizeof(struct node));
        temp2 = p2;
        temp_r->exp = temp1->exp;
        temp_r->coeff = temp1->coeff;
    
        while(temp2!=NULL){
            if(temp2->exp==temp1->exp){
                temp_r->coeff += temp2->coeff;
            }
            temp2 = temp2->next;
        }
    
        temp_r->next = result;
        result = temp_r;
        temp1 = temp1->next;
    
    }

    temp2 = p2;
    
    while(temp2!=NULL)
    {
        int wasFound = 0;
        struct node *temp_r = (struct node*)malloc(sizeof(struct node));
        temp1 = p1;
        
        while(temp1!=NULL)
        {
            if(temp1->exp==temp2->exp)
                wasFound = 1;
            
            temp1 = temp1->next;
            
        }
        
        if(wasFound==0)
        {
            temp_r->coeff = temp2->coeff;
            temp_r->exp = temp2->exp;
            temp_r->next = result;
            result = temp_r;
        }
        
        temp2 = temp2->next;
    
    }
    
    return result;

}

struct node* multiply(struct node *p1,struct node *p2)
{

    struct node *temp1 = p1, *temp2 = p2, *list = NULL, *result = NULL;
    int itr = 0;
    
    while(temp1!=NULL)
    {
        temp2 = p2;
        while(temp2!=NULL)
        {
        
            struct node *temp_m = (struct node*)malloc(sizeof(struct node));
            temp_m->coeff = (temp1->coeff)*(temp2->coeff);
            temp_m->exp = (temp1->exp)+(temp2->exp);
            temp_m->next = list;
            list = temp_m;
            temp2 = temp2->next;
        
        }
        
        itr++;
        
        if(itr==1)
        {
            result = list;
        }
        else
        {
            result = add(result,list);
        }
        
        list = NULL;
        
        temp1 = temp1->next;
    }
    return result;
}

int main(){
    int choice = -1;
    while(1){
        
            int ex;
            char s[10];

            printf("\nSelect any one:\n1. Add\t 2. Multiply\t3.Exit\nEnter your choice: ");
            scanf("%d",&choice);
            
            if(choice==3) break;
            printf("\nEnter first Polynomial:\n");
            
            while(1)
            {
            
                if(start1!=NULL) 
                    display(start1,1);
                
                printf("Enter Coeffecient (Enter '.' to terminate here):");
                scanf("%s",&s);
                
                if(strcmp(s,".")==0)
                    break;
                
                printf("Enter Exponent:");
                scanf("%d",&ex);
                insert(atoi(s),ex,1);
            
            }
            
            display(start1,1);
            printf("\nEnter second Polynomial:\n");
            
            while(1)
            {
            
                if(start2!=NULL)
                    display(start2,2);
                
                printf("Enter Coeffecient (Enter '.' to terminate here):");
                scanf("%s",&s);
                
                if(strcmp(s,".")==0)
                    break;
                
                printf("Enter Exponent:");
                scanf("%d",&ex);
                insert(atoi(s),ex,2);
            
            }

            printf("\n\n");
            display(start1,1);
            display(start2,2);
            
            switch(choice)
            {
            
                case 1:
                    display(add(start1,start2),3);
                    start1 = start2 = NULL;
                    break;
                case 2:
                    display(multiply(start1,start2),4);
                    start1 = start2 = NULL;
                    break;
            }

        }
        
    return 0;
}
