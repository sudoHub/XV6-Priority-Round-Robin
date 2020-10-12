// dummy_func.c
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  int pid, priority;
  int k, n;
  int x, z;

  if(argc < 2)
	n = 1; //Default
  else
	n = atoi(argv[1]);
  
  if (n < 0 ||n > 20)
  {
	  n = 2;
  }
  if (argc < 3)
  {
    priority = 10;
  }
  else
  {
    priority = atoi(argv[2]);
  }
  

  x = 0;
  pid = 0;

  for ( k = 0; k < n; k++ ) {
    pid = fork ();

    if ( pid < 0 ) 
    {
      printf(1, "%d failed in fork!\n", getpid());
    } 
    else if (pid > 0) 
    {
      // parent
      printf(1, "Parent %d creating child %d\n",getpid(), pid);
      wait();
    }
    else{
      if(priority > 0)
        priority -= 1; 

      //chpr(getpid(), priority); // attempt to change priority

      sleep(2); //had to add sleep to get print statement readable

      printf(1,"Child %d created\n",getpid());
      
      for(z = 0; z < 4000000000; z+=1)
      //for(z = 0; z < 8000000; z+=1) //this should return, it's not infinite loop
          x = x + 3.14*89.64; //Useless calculation to consume CPU Time
      
      break;
      }
  }
  exit();
}