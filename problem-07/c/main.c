#include <stdio.h>
#include <stdlib.h>

int prime_sieve(int n) {
	// Prepare
	int limit = (n * n) - 2;
	int *numbers = malloc(limit * sizeof(int));

	// Load Initial Array
	for (int i = 0; i < limit; i++) {
		numbers[i] = i + 2;
	}

	// Sieve
	int n_prime = 0;
	int output = 0;
	for (int i = 0; i < limit; i++) {
		int x = numbers[i];

		if (x != 0) {
			n_prime++;
			for (int j = i + x; j < limit; j += x) {
				numbers[j] = 0;
			}
		}

		if (n_prime == n) {
			output = x;
			break;
		}
	}

	// Free Number Array
	free(numbers);

	return output;
}

int solution(int n) {
	// Get Primes
	return prime_sieve(n);
}

int main() {
	printf("Solution #7: %d\n", solution(10001));
}
