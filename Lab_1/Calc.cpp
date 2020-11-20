#include<stdio.h>

int main(void)
{

  int a,b;
  printf("Enter the number  a: ");
  scanf("%i",&a);

  printf("Enter the number b: ");
  scanf("%i",&b);

  int choice = 0;
  while(choice <5)
  {

    printf("Enter the type of operation you want to do on the program: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit");
    scanf("%i",&choice);


    switch (choice){

      case 1:
      printf("%i \n",a+b);
      break;
      case 2:
      printf("%i \n",a-b);
      break;
      case 3 :
      printf("%i \n",a*b);
      break;
      case 4:
      if(b == 0)
      printf("We can't devide a number by 0 \n");
      else
      printf("%f \n",(float)a/b);
      break;

    }
  }


}
