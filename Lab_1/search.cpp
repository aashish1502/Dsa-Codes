#include<stdio.h>

int main(void)
{

  int n;
  printf("Enter the size of array n. \n");
  scanf("%i",&n);

  long long int arr[n];
  int i = 0;

  for ( i = 0; i < n ; i++) {
    printf("Enter the %i element: ",i+1);
    scanf("%lld", &arr[i]);
  }

  printf("What number do you want to search : ");
  int search;
  scanf("%i",&search);
  int s = 0;


  i = 0;
  for(i = 0 ; i< n ; i++)
  {

  if(arr[i] == search){
    s=1;
    printf("The element exsists at the index %i \n",i);
    break;
    }
  }

  if(s==0)
  printf("The number does not exsist in the array. \n");


}
