#include<stdio.h>
#include<stdlib.h>

struct DoubleLinkedList
{
    int Data;
    struct DoubleLinkedList* Next;
    struct DoubleLinkedList* Previous;
};


struct DoubleLinkedList* CreateLinkedList()
{
    
    struct DoubleLinkedList* LL = malloc(sizeof(struct DoubleLinkedList));

    if(!LL)
    {
        printf("Memory Error Occured\n");
        return NULL;
    }
    
    LL->Next = LL->Previous = NULL;

    
    printf("LL created Succesfuly!\n");

    return LL;


}

void Insert(struct DoubleLinkedList* LL, int data, int pog)
{

    if(pog == 1)
    {
        struct DoubleLinkedList* temp = malloc(sizeof(struct DoubleLinkedList));
        temp->Data = data;
        temp->Next = LL->Next;
        temp->Previous = LL;
        LL->Next = temp;
    }
    else
    {
        int count = 1;
        struct DoubleLinkedList* temp = LL;
        while (count != pog && temp != NULL )
        {
            printf("cout : %i\n",temp->Data);
            temp = temp->Next;
            count++;
        }
        if(count < pog-1)
        {
            printf("The position does not exists in the linked list \n");
            exit(0);
        }
        else if(count = pog )
        {
            printf("THe val of temp is: %i\n",temp->Data);
            struct DoubleLinkedList* temp1 = malloc(sizeof(struct DoubleLinkedList));
            struct DoubleLinkedList* temp2 = temp->Previous;
            temp1->Data = data;
            temp1->Previous = temp2;
            temp1->Next = temp;
            temp->Previous = temp1;
            temp2->Next = temp1;
        }
        else
        {
            
            struct DoubleLinkedList* temp1 = malloc(sizeof(struct DoubleLinkedList));
            struct DoubleLinkedList* temp2 = temp->Previous;
            temp1->Next = temp;
            temp1->Previous = temp2;
            temp2->Next = temp1;
            temp->Previous = temp1;
        }
    }
    

}

void DisplayList(struct DoubleLinkedList* LL)
{
    struct DoubleLinkedList* temp = LL->Next;
    printf("The values in the list are: ");
    while (temp != NULL)
    {
        printf("%i\t",temp->Data);
        temp = temp->Next;
    }
    printf("\n");
    

}

int main(void)
{
    
    struct DoubleLinkedList* LL = CreateLinkedList();
    Insert(LL,4,1);
    Insert(LL,5,3);
    DisplayList(LL);
    
}