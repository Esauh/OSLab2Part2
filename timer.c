#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int time = 1;
time_t start, end;

void alrm_handler(int signum) {
  printf("SIGALRM Triggered!\n");
  time = 0;
}

void sigint_handler(int signum) {
  time(&end);
  int time_elapsed =  end - start;
  printf("\nTime Gone: %d seconds\n", time_elapsed);
  exit(1);
}


int main(int argc, char * argv[]) {
  signal(SIGINT, sigint_handler);
  signal(SIGALRM, alrm_handler);
  time(&start);
  while (1) {
    alarm(1);
    while(time);
    time = 1;
  }
  return 0;
}