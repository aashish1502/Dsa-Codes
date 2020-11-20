
#include<stdio.h>
#include <stdlib.h>
struct node {
    int vertex;
    struct node *next;
};

#define new_node (struct node*)malloc(sizeof(struct node))


void read_graph(struct node *adj_list[], int n){
    int i, j;
    char reply;
    struct node *p, *c;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j)
            {
                printf("\nVertices %d and  %d are Adjacent ? (Y/N) : ",i,j);
                scanf("%s",&reply);
                
                
                if (reply == 'y' || reply == 'Y') {
                    c = new_node;
                    c -> vertex = j;
                    c -> next = NULL;
                    if (adj_list[i] == NULL)
                        adj_list[i] = c;
                    else {
                        p = adj_list[i];
                        while (p -> next != NULL)
                            p = p -> next;
                        p -> next = c;
                    }
                }

            }
        }
    }
    
}


int dir_graph() {
    struct node *adj_list[10], *p;
    int n;
    int in_deg, out_deg, i, j;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        adj_list[i] = NULL;
    read_graph(adj_list, n);
    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");
    for (i = 1; i <= n; i++) {
        in_deg = out_deg = 0;
        p = adj_list[i];
        while (p != NULL) {
            out_deg++;
            p = p -> next;
        }
        for (j = 1; j <= n; j++) {
            p = adj_list[j];
            while (p != NULL) {
                if (p -> vertex == i)
                    in_deg++;
                p = p -> next;
            }
        }
        printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n", i, in_deg, out_deg,
               in_deg + out_deg);
    }
    return 0;
}
int undir_graph() {
    struct node *adj_list[10], *p;
    int deg, i, j, n;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        adj_list[i] = NULL;
    read_graph(adj_list, n);
    printf("\n Vertex \t Degree ");
    for (i = 1; i <= n; i++) {
        deg = 0;
        p = adj_list[i];
        while (p != NULL) {
            deg++;
            p = p -> next;
        }
        printf("\n\n %5d \t\t %d\n\n", i, deg);
    }
    return 0;
}


void main() {
    int option;
    do {
        printf("\n A Program to represent a Graph by using an Linked List \n ");
        printf("\n 1. Directed Graph ");
        printf("\n 2. Un-Directed Graph ");
        printf("\n 3. Exit ");
        printf("\n\n Select a proper option : ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                dir_graph();
                break;
            case 2:
                undir_graph();
                break;
            case 3:
                exit(0);
        }
    } while (1);
}

