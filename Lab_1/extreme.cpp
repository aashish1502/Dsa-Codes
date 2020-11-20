#include<stdio.h>

long long int max(long long int[],int);
long long int min(long long int[],int);

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

  int choice = 0;

while(choice <3){

  printf("Enter what would you like to find: \n");
  printf("1. Maximum \n");
  printf("2. Minimum\n");
  
  scanf("%i",&choice);

  switch (choice){
    case 1 :
    printf("Maximum element is: %lld \n",max(arr,n));
    break;

    case 2:
    printf("Minimum element is: %lld \n",min(arr,n) );
	break;
    }
  }
}

long long int max(long long int a[],int n){

  long long int maximum = a[0];

  for(int i = 1 ; i< n; i++)
  {
    if(a[i]>maximum)
    maximum =a[i];
  }
  
  return maximum;
}


long long int min(long long int a[],int n){

  long long int minimum = a[0];

  for(int i = 1 ; i< n; i++)
  {
    if(a[i]<minimum)
    minimum =a[i];
  }

  return minimum;

}
