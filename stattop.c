#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void handle_INT(int);

int count = 0;
long sum = 0;
long sum_squares = 0;

int main() {
  int i;
  float mean;
  float std_dev;
  char buffer[128];

  setvbuf(stdin, NULL, _IONBF, 0);
  signal(SIGINT, handle_INT);

  while( fgets(buffer, 128, stdin) ) {
    sscanf(buffer, "%d", &i);
    count += 1;
    sum += i;
    sum_squares += (i*i);

    mean = ((float) sum / (float) count);

    if( count > 1 ) {
      std_dev = sqrt((sum_squares - ((sum * sum) / count)) / ( count - 1 ));
    } else {
      std_dev = 0;
    }

    printf("\rlast=%d count=%d mean=%.0f std_dev=%.0f                    ", i, count, mean, std_dev);
    fflush(stdout);
  }
  return 0;
}

void handle_INT(int sig) {
  printf("\n");
  exit(0);
}
