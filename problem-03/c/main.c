#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime_sieve(int max, int **output) {
	// Create Initial Vector
	int *numbers = malloc((max - 2) * sizeof(int));

	// Load Initial Array
	for (int i = 0; i < max - 2; i++) {
		numbers[i] = i + 2;
	}

	// Sieve of Erastosthenes
	int count = 0;
	for (int i = 0; i < max - 2; i++) {
		int x = numbers[i];

		if (x != 0) {
			count++;
			for (int j = i + x; j < max - 2; j += x) {
				numbers[j] = 0;
			}
		}
	}

	// Load Output
	free(*output);
	*output = (int*)malloc(count * sizeof(int));
	int idx = 0;
	for (int i = 0; i < max - 2; i++) {
		int x = numbers[i];
		if (x != 0) {
			(*output)[idx] = x;
			idx++;
		}
	}

	// Free
	free(numbers);

	return count;
}

int max_int(int a, int b) {
	if (a < b) return b;
	return a;
}

int solution(long long int target) {
	// Prepare
	long long int sqrt_target = (long long int) (sqrt((double) target)) + 1;
	int *primes = NULL;

	// Get Primes
	int n_primes = prime_sieve(sqrt_target, &primes);

	// Find Max Prime Factor
	int output = 0;
	for (int i = 0; i < n_primes; i++) {
		// Search
		int prime = primes[i];
		int mod = target % prime;

		// Check
		if (mod == 0) {
			output = max_int(prime, output);
		}
	}

	return output;
}

int main() {
	printf("Solution #3: %d\n", solution(600851475143));
}
