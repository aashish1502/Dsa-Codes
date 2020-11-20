#include<stdio.h>


void swap_2(int *a,int *b)
{

  *a=*a^*b;
  *b=*b^*a;
  *a=*a^*b;

}

void swap_1(int *a,int *b)
{
  int temp ;
  temp =*a;
  *a=*b;
  *b=temp;
}

int main(void)
{


  int a ,b;
  printf("Enter the first variable a to swap: ");
  scanf("%i",&a);

  printf("Enter the second variable b to swap: ");
  scanf("%i",&b);

  

	int choice =0;

while(choice < 3){
  printf("\n");
  printf("How do you want to swap the variables \n");
  printf("1.By using a temporary variable.\n");
  printf("2.By not using a temporary variable\n");

  printf("\n");
	
	scanf("%i",&choice);	
	
  switch (choice) {
    case 1 :
        
		printf("Before swapping a: %i b: %i \n",a,b);
		swap_1(&a,&b);
        printf("After swapping a: %i  b: %i \n",a,b);
		break;
    case 2 :
    	printf("Before swapping a: %i b: %i \n",a,b);
        swap_2(&a,&b);
        printf("After swapping a: %i  b:%i \n",a,b);
        break;
	}
	}
}
