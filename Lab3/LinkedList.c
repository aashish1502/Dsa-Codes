#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next ;
};

int ListLength(struct Node* head)
{

    struct Node* current = head;
    int i = 0;
    while(current != NULL)
    {
        i++;
        current = current->next;
    }

    return i;
}

void Insert(struct Node **head, int data, int pos){
	int k=1;
	struct Node *q,*p;
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory Error\n");
		return;
	}
	
    newNode->data=data;
	p=*head;

	if(pos==1 || p==NULL){
		newNode->next=*head;
		*head=newNode;
	}
	else{
		while(p!=NULL && (k<pos)){
			k++;
			q=p;
			p=p->next;
		}
		newNode->next=q->next;
		q->next=newNode;
	}
}

void DeleteNode(struct Node** head , int position)
{
    int i = 1;
    struct Node *p , *q;
    p=*head;
    if(*head == NULL)
    {
        printf("Empty List\n");
    }
    p = *head ;
    if(position ==1)
    {
        *head = (*head)->next;
        free(p);
        return;
    }
    else
    {
        while(p!=NULL && i < position)
        {
            i++;
            q=p;
            p = p->next;
        }
        if(p == NULL)
        {
            printf("Position doesnt exists\n");
            return;
        }
        q->next = p->next;
        free(p);
    }
}

void displayList(struct Node** head)
{
    struct Node *tmp;
    if(head == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = *head;
        while(tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;       
        }

        printf("\n");
    }
}


void Search(struct Node* head, int key)
{
    if(ListLength(head) == 0)
    {
        printf("There are no elements in the Linked List.\n");
    }
    else
    {
        int  i = 0;
        int status = 0;
        struct Node *current = head;
        while (current->next != NULL)
        {
            if(current->data == key)
            {
                printf("The element %i is present at %i node from the head node.\n",key,i);
                status = 1;
                break;
            }
            current = current->next;
            i++;
        }
        
        if(status == 0)
        {
            printf("The element is not present in the Linked list.\n");
        }
        
    }
    
}


int main(void)
{

    struct Node* head = NULL;

    int choice = -1;
    int position = -1;
    int data  = -1;

    while(choice < 5)
    {
        printf("**********Single Linked List Program********\n");
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
            printf("Enter the data to be inserted in the Linked List: ");
            scanf("%i",&data);
            printf("Enter the position to be inserted in the Linked List: ");
            scanf("%i",&position);
            printf("> \t");
            Insert(&head,data,position);
            break;
        case 2:
            printf("Enter the position to be deleted in the Linked List: ");
            scanf("%i",&position);
            printf("> \t");
            DeleteNode(&head,position);
            break;
        case 3:
            printf("> \t");
            displayList(&head);
            break; 
        case 4:
            printf("Enter the data you want to find in the Linked List: ");
            scanf("%i",&data);
            printf("> \t");
            Search(head,data);  
        }

        printf("------------------------\n");
        printf("\n \n");

    }

}