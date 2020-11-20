#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

char Vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
int Count[] = {0,0,0,0,0,0,0,0,0,0};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


void inorder(struct node *root) {
  
  if (root != NULL) {
    inorder(root->left);
    printf("%c -> ", root->key);
    inorder(root->right);
  }

}


void findVowel(struct node *root, int *count, int print)
{

    if (root != NULL) {
    findVowel(root->left, count, print);
    int i = 0;
    for(i = 0 ; i < 10 ; i++)
    {
        if(Vowels[i] == root->key)
        {
            printf("%c\n",root->key);
            Count[i]++;
        }
    }
    findVowel(root->right, count, print);
  }

}

struct node *insert(struct node *node, int key) {
  
  if (node == NULL) return newNode(key);
  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}


int main() {
  struct node *root = NULL;
  char h[100];
  int  i = 0, j = 0;
  int choice = -1;
  int *c = 0;

  while(choice < 5)
  {

    printf("------------Data Structures and Algorithms LabFAT-----------\n");
    printf("---------------------------Menu-----------------------------\n");
    printf("-------------------------19BCE0971--------------------------\n");
    printf("1). Construct a BST.\n");
    printf("2). Perform Inorder Traversal.\n");
    printf("3). Search for vowels.\n");
    printf("4). Print and count Vowels.\n");
    printf("5). Exit\n");
    scanf("%i",&choice);
    c = 0 ;
    
    switch (choice)
    {
    case 1:
        printf("Enter your name: ");
        scanf("%s",h);
        i = 0;

        while(h[i]!='\0')
        {
            root = insert(root,h[i]);
            i++;
        }
        break;
    case 2:
        inorder(root);
        printf("\n");
        break;
    case 3:
        findVowel(root,c,0);
        break;
        
    case 4:
        
        printf("The count of the vowels are: \n");
        for(j = 0 ;  j < 10 ; j++)
        {
            printf("%c : %i\n",Vowels[j],Count[j]);
        }    


    default:
        break;
    }
  }

}