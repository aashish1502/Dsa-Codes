//demonstration of a simple fork program - 19BCE0971

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

#define MAX_COUNT 5

void childProcess(void);
void parentProcess(void);

int main(void)
{

    printf("******** BEGINING OF MAIN PROGRAM ****** \n");
    printf("The parent id of the program is : %d",getppid()); //prints the parent id of the main program.
    printf("\n \n");

    pid_t pid ;

    pid = fork(); //Creates a child process

    if(pid == 0) //the child will always have pid as 0
    {
    
        //This is called only in a child process
        childProcess();
        

    }
    else
    {

        //This is called only in a Parent process       
        wait(NULL); //waits till the child process is complete
        parentProcess();
   
    }
    

}

// fprint(stderr, "..."); is a unbuffered print function and outputs the string at the same time of calling 
// this helps us in better visualisation of completion of the child process first than parent

void childProcess(void)
{
    int i;
    for(i = 1 ; i <= MAX_COUNT ; i++)
    {
        
        
        fprintf(stderr, "This is a child Process with pid: %i \n",getpid());
        fprintf(stderr, "This The parent id of the child is: %i \n",getppid());
        fprintf(stderr, "This is the iteration number of the child process is : %d \n",i);
        fprintf(stderr, "\n \n");
        
    }
}

void parentProcess(void)
{
    
    int i = 0 ;
    for(i = 1 ; i <= MAX_COUNT; i++)
    {    
        
        fprintf(stderr, "**** This is a Parent Process with pid: %i \n",getpid());
        fprintf(stderr, "**** This is the iteration number of the Parent process is : %d \n",i);
        fprintf(stderr, "\n \n");
    }


}