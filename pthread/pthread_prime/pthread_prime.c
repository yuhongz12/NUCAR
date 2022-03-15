#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// constant for numbers of Pthreads
#define NTHREADS 10

// numbers of prime numbers
int primes = 0;

int i = 0;

// determine if the currently num is a prime or not
void prime(int num) {

    int p = 0;

    // loop through each number from 1 to num
    for (i = 1; i <= num; i++) {
        // if num is divisible by i, then increment p
        if (num % i == 0) {
            p++;
        }
    }

    // a prime is only divisible by 1 and itself
    // if p is 2, then its prime
    // else its not prime
    if (p == 2) {
        printf("%d is prime.\n", num);
        primes++;
    } else {
        printf("%d is not prime.\n", num);
    }
    return;
}
// main method
int main() {
    
    // initialize all pthreads
    pthread_t threads[NTHREADS];

    // forking all pthreads
    printf("forking\n");
    for (i = 0; i < NTHREADS; i++) {
        if (pthread_create(threads+i, NULL, &prime, i) != 0) {
            return i++;
        }
    }
        
    // joining pthreads
    printf("joining\n");
    for (i=0; i < NTHREADS; i++) {
       if (pthread_join(threads[i],NULL) != 0) {
           return NTHREADS+i+1;
       }
    }
    
    // print numbers of prime number
    printf("Numbers of prime numbers from 1 to %d: %d\n", NTHREADS, primes);

    pthread_exit(NULL);
    return 0;

}
