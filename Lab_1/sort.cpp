#include<stdio.h>

void swap(int *a,int *b)
{
  int temp = *a;
  *a=*b;
  *b=temp;
}

int main(void)
{

  int n = 0 , i = 0 ;
  printf("Enter the size of the array: ");
  scanf("%i",&n);

  int arr[n];

  for (i = 0; i < n; i++){

    printf("Enter the %i element :",i+1);
    scanf("%i",&arr[i]);

  }




  int min = 0;
  int j = 0;
  
  for (i = 0; i < n-1; i++){
  	
    min = i;

    for( j = i+1 ;  j < n ; j++)
        if(arr[j] < arr[min])
		min=j;
	
	swap(&arr[min],&arr[i]);


   
  }



int choice = 0 ;

while(choice <3)
{
	printf("In what order would you like to print the array? \n");
	printf("1. Ascending Order\n");
	printf("2. Descending order\n");
	scanf("%i",&choice);
	
	
	switch(choice){
		
		case 1:
		for (i = 0; i < n; i++){

      		printf("%i \t",arr[i]);

    	}
    	printf("\n");
		break;
		
		case 2:
		
		for (i = n-1; i >= 0 ; i--){
      	
		  printf("%i \t",arr[i]);
    	}
		printf("\n");
		break;		
		
	}
	
	
}

 




}
