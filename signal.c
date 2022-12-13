#include <stdio.h>
//Esau Hutcherson
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int wait = 1;

int Prints = 0;  

void handler(int cignal){
  printf("Hello World!\n");
  printf("Turing was right!\n");
  Prints ++;
  wait = 0;
}

time_t start, stop;
void anotherHandler(int cignal){
  time(&stop);
  int executionTime = stop - start;
  printf("\nTotal execution time: %ds\n", executionTime);
  printf("Total prints: %d\n", Prints);
  
  exit(1);
}

int main(int argc, char * argv[]){
  signal(SIGINT, anotherHandler);
  signal(SIGALRM, handler);
  time(&start);
  while (1) {
    alarm(1);
    while(wait);
    wait = 1;
  }
  return 0;
}