// countPrimes.c
// To count the number of primes in the range [1, limit]
// where limit is entered by user.
#include <stdio.h>

int is_prime(int);

int main(void) {    
	int limit, i, countPrime;
    countPrime = 0;
	printf("Enter limit: ");
	scanf("%d", &limit);
    for (i = 1; i <=limit; i++){
        countPrime += is_prime(i);
    }
    printf("Number of primes (1-%d): %d\n",limit, countPrime);
	return 0;
}

int is_prime(int n) {
    int i;
    if (n == 1){
        return 0;
    }
    for (i = 2; i <= n/2; i++){
        
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}