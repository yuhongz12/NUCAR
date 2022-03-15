#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define NTHREADS 10

int sum=0;

void adder()
{
 int t =  sum;
 sum = t+1;
 printf("sum computed: %d\n", sum);
 return;
}

int main()
{
 int i;
 pthread_t threads[NTHREADS];
 printf("forking\n");
 for (i=0; i < NTHREADS; i++)
    if (pthread_create(threads+i, NULL, &adder, NULL) != 0) return i+1;
 printf("join\n");
 for (i=0; i < NTHREADS; i++)
   if (pthread_join(threads[i],NULL)!=0)
      return NTHREADS+i+1;
  printf("sum computed: %d\n", sum);

  pthread_exit(NULL);
  return 0;
}

