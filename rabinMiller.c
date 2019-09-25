#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define COMPOSITE		0
#define INCONCLUSIVE 1

/*
 * Modular Arithmetic
 * (a mod n) * (b mod n) mod n = (a * b) mod n
 * This is used to avoid overflow during Miller-Rabin test
 */

long powMod(long base, long power, long n)
{
	if (power == 0) return 1;

	long mod = (base % n);
	for (long i = 1; i < power; i++) {
		mod = (mod * base) % n;
	}
	return mod;
}

int millerRabinTest(long n, int t)
{
	// some pre-check for basic condition
	if (n == 2 || n == 3) {
		return INCONCLUSIVE;
	} else if ((n % 2) == 0) {
		return COMPOSITE;
	}
	// find k,q such that (n-1) = 2^k * q
	long q = n - 1;
	long k = 0;
	while ((q % 2) == 0) {
		q /= 2;
		k++;
	}
	
	for (int i = 0; i < t; i++) {
		int result = COMPOSITE;
		// Select a radom integer 'a' such that 2 =< a =< n-2
		long a = (rand() % (n - 3)) + 2;

		long modulus = powMod(a, q, n);
		// modulus is now a^q mod n, which is j = 0 case in below for loop
		// so we can check for both modulus = 1 or n - 1 case here
		if (modulus == 1 || modulus == (n - 1)) continue;
		// check for a^(2^j * q) mod n
		// j = 1 ~ k - 1 (j = 0 is already checked)
		for (int j = 1; j <= (k - 1); j++) {
			modulus = powMod(modulus, 2, n);
			if (modulus == (n - 1)) {
				result = INCONCLUSIVE;
				break;
			}
		}
		// we just need one composite result to confirm n is not prime
		if (result == COMPOSITE) return COMPOSITE;
	}
	return INCONCLUSIVE;
}

int main(int argc, char* argv[]) 
{ 
	if(!argv[1] || !argv[2]) {
		printf("Uasge: assign2 n t\n");
		exit(1);
	}


	long n = atol(argv[1]);
	int t = atoi(argv[2]); 
	if (n <= 1|| t < 1) {
		printf("Invalid input!\n");
		return -1;
	}

	srand( time(NULL) );
	if (millerRabinTest(n, t) == INCONCLUSIVE) {
		printf("Inconclusive\n");
	} else {
		printf("Composite\n");
	}

	return 0; 
} 
