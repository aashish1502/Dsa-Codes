#include<stdio.h>
#include<stdlib.h>

struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;   
};

struct BSTNode *NewNode(int item) 
{ 
    struct BSTNode *temp =  (struct BSTNode *)malloc(sizeof(struct BSTNode)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct BSTNode* Insert(struct BSTNode* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return NewNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = Insert(node->left, key); 
    else if (key > node->data) 
        node->right = Insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

struct BSTNode* FindMax(struct BSTNode *root)
{
    if(root == NULL)
    {
        printf("The Tree is Empty!.\n");
        return NULL;
    }
    else
    {
        while (root -> right != NULL)
        {
            root-> right = root;
        }
        return root;
    }
}

struct BSTNode* Delete(struct BSTNode* root, int data)
{
    struct BSTNode *temp ;

    if(root == NULL)
    {
        printf("Element is not present in the Binary Search Tree\n");
    }
    else
    {

        if(data < root -> data)
        {
            Delete(root->left , data);
        }
        else if(data > root-> data)
        {
            Delete(root -> right , data);
        }
        else
        {
            
            if(root -> left && root -> right)
            {
                temp = FindMax(root -> left);
                root -> data = temp -> data;
                root -> left = Delete(root -> left, data);
            }   
            else
            {
                temp = root;
                if(root -> left == NULL)
                {
                    root = root -> right;
                }
                else
                {
                    root = root -> left;
                }

                free(temp);

            }  

        }
        return root;

    }    

}

void inOrder(struct BSTNode* root)
{
     if (root == NULL) // or if (!root)
          return;
     
     inOrder(root->left);  
     printf("%d ", root->data);  
     inOrder(root->right);
} 

void postOrder(struct BSTNode* root){
     if (root == NULL) // or if (!root)
          return;
       
     postOrder(root->left);  
     postOrder(root->right);
     printf("%d ", root->data);
} 

void preOrder(struct BSTNode* root){
  
     if (root == NULL) // or if (!root)
          return;
     printf("%d ", root->data);  
     preOrder(root->left);  
     preOrder(root->right);
} 


int main(void)
{
    struct BSTNode *root = NULL ;
    int choice = -1;
    int data = 0;

    while(choice < 7)
    {
        printf("**********Queue using Linked List Program********\n");
        printf("\n");
        printf("----------Menu----------\n");
        printf("Select the following expressions to be performed on a Stack\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Max\n");
        printf("4. PreOrder Traversal\n");
        printf("5. InOrder Traversal\n");
        printf("6. PostOrder Traversal\n");
        printf("7. Exit\n");
        

        printf("Please Eneter the choice of operation you would like to perform: ");
        scanf("%i",&choice);


        printf("------------------------\n");

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted in the BST: ");
            scanf("%i",&data);
            if(root == NULL)
                root = Insert(root, data);   
            else
                Insert(root,data);
            break;
        case 2:
            printf("Enter the data to be deleted in the BST: ");
            scanf("%i",&data);
            Delete(root,data);
            break;
        case 3:
            printf("%i", FindMax(root) -> data  );
            break;   
        case 4:
            preOrder(root);
            printf("\n");
            break;
        case 5:
            inOrder(root);
            printf("\n");
            break;
        case 6:
            postOrder(root);
            printf("\n");
            break;
         }
        
        printf("------------------------\n");
        printf("\n \n");

    }
}