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

	return output;
}

/*
int prime_sieve(int n, int **output) {
	// Prepare
	int *numbers = malloc((n - 2) * sizeof(int));

	// Load Initial Array
	for (int i = 0; i < n - 2; i++) {
		numbers[i] = i + 2;
	}

	// Sieve of Erasthosthenes
	int count = 0;
	for (int i = 0; i < n - 2; i++) {
		int x = numbers[i];

		if (x != 0) {
			count++;
			for (int j = i + x; j < n - 2; j += x) {
				numbers[j] = 0;
			}
		}
	}

	// Load Output
	free(*output);
	*output = (int*)malloc(count * sizeof(int));
	int idx = 0;
	for (int i = 0; i < n - 2; i++) {
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
*/

int solution(int n) {
	// Get Primes
	return prime_sieve(n);
}

int main() {
	printf("Solution #7: %d\n", solution(10001));
}
