#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
} *root = NULL;

void insert(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->leftChild = temp->rightChild = NULL;
    if(root==NULL)  root = temp;
    else{
        struct node *root_c = root;
        while(1){
            if(key<root_c->data&&root_c->leftChild==NULL){
                root_c->leftChild = temp;
                break;
            }else if(key>root_c->data&&root_c->rightChild==NULL){
                root_c->rightChild = temp;
                break;
            }else if(key<root_c->data){
                root_c = root_c->leftChild;
            }else if(key>root_c->data){
                root_c = root_c->rightChild;
            }
        }
    }
}

void delete(int key){
    struct node *temp = root,*parent = NULL;
    while(1){
        if(key<temp->data){
            parent = temp;
            temp = temp->leftChild;
        }else if(key>temp->data){
            parent = temp;
            temp = temp->rightChild;
        }else if(key==temp->data){
            if(temp->leftChild==NULL&&temp->rightChild==NULL){
                if(temp==parent->leftChild) parent->leftChild = NULL;
                else  parent->rightChild = NULL;
                free(temp);
                break;
            }else if(temp->leftChild!=NULL&&temp->rightChild!=NULL){
                struct node* temp2 = temp->leftChild, *parent2 = temp;
                int max = temp2->data;
                while(temp2!=NULL){
                    max = temp2->data;
                    temp2 = temp2->rightChild;
                }
                temp->data = max;
                temp->leftChild = temp->leftChild->leftChild;
                break;
            }else{
                if(temp->leftChild!=NULL){
                    if(temp==parent->leftChild){
                        parent->leftChild = temp->leftChild;
                    }else{
                        parent->rightChild = temp->leftChild;
                    }
                }else{
                  if(temp==parent->leftChild){
                      parent->leftChild = temp->rightChild;
                  }else{
                      parent->rightChild = temp->rightChild;
                  }
                }
                break;
            }
        }
    }
}
void preorder(struct node *n){
    if(n==NULL) return;
    printf("%d ", n->data);
    preorder(n->leftChild);
    preorder(n->rightChild);
}

void inorder(struct node *n){
    if(n==NULL) return;
    inorder(n->leftChild);
    printf("%d ", n->data);
    inorder(n->rightChild);
}

void postorder(struct node *n){
    if(n==NULL) return;
    postorder(n->leftChild);
    postorder(n->rightChild);
    printf("%d ",n->data);
}

int main(){
    int ch,data;
    do{
        printf("**********Binary Search Tree Program********\n");
        printf("\n");
        printf("----------Menu----------\n");
        printf("Select the following expressions to be performed on a Tree\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. PreOrder Traversal\n");
        printf("4. InOrder Traversal\n");
        printf("5. PostOrder Traversal\n");
        printf("6. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter data be inserted:");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                printf("Enter data to be deleted:");
                scanf("%d",&data);
                delete(data);
                break;
            case 3:
                if(root==NULL)  printf("Tree Empty!\n");
                else{
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root==NULL)  printf("Tree Empty!\n");
                else{
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 5:
                if(root==NULL)  printf("Tree Empty!\n");
                else{
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
        }
    }while(ch!=6);
}
