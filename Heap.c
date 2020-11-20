#include<stdio.h>
#include<stdlib.h>


struct Heap
{
    int *array;
    int count;       // Number of elements in the heap
    int capacity;    // Capacity of the heap
    int heap_type;   // Min or max heap 0 for max and 1 for min
};

struct Heap* CreateHeap(int capacity)
{
    struct Heap* h = malloc(sizeof(struct Heap));

    if(h == NULL)
    {
        printf("Memory error occured\n");
        exit(1);
    }

    h->heap_type = 0;
    h->count = 0;
    h->capacity = capacity;
    h->array = malloc(sizeof(int)*(h->capacity));

    if(h->array == NULL)
    {
        printf("An error occured while allocating memory to the array.\n");
        exit(1);
    }

    return h;
}

int LeftChild(struct Heap* h, int i)
{
    int left = (2*i) + 1;
    if(left >= h->count)
        return -1;
    return left;
}

int RightChild(struct Heap* h, int i)
{
    int right = (2*i) + 2;
    if(right >= h->count)
        return -1;
    return right;
}

void PercolateDown(struct Heap* h, int i)
{
    int l,r,max,temp;
    l = LeftChild(h,i);
    r = RightChild(h,i);

    if(l != -1 && h->array[l] > h->array[i])
    {
        max = l;
    }
    else
    {
        max = i;
    }
    
    if(r != -1 && h->array[r] > h->array[max])
    {
        max = r;
    }
    
    if(max != i)
    {
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;
    }
    printf("wsad\n");
    PercolateDown(h,max);
}

void BuildHeap(struct Heap* h, int a[], int n)
{
    if(h == NULL)
    {
        printf("Heap is not allocated memory!\n");
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        h->array[i] = a[i];
    }
    h->count = n;

    for (int i = 0; i < n; i++)
    {
        PercolateDown(h,i);
    }
    
}

void HeapSort(int A[], int n)
{
    struct Heap* h = CreateHeap(n);
    int old_size, i , temp;
    BuildHeap(h,A,n);
    old_size = h->count;

    for(i = n-1 ; i > 0 ; i--)
    {
        temp = h->array[i];
        h->array[i] = h->array[h->count -1];
        h->array[i] = temp ;
        h->count--;
        PercolateDown(h,0);
    }

}


int main(void)
{
    int n;
    printf("*********** Heap Sort Program ************\n\n\n");
    printf("Enter the size of the array: ");
    scanf("%i",&n);
    int *a = malloc(sizeof(int)*n);

    for (int i = 0; i < n ; i++)
    {
        printf("Enter %i Element: ",i+1);
        scanf("%i",a++);
    }

    struct Heap* h = CreateHeap(n);
    HeapSort(a,n);

    printf("The sorted array after performing heap sort is: \n");

    for (int i = 0; i < h->count; i++)
    {
        printf("%i ",h->array[i]);
    }
    
}

