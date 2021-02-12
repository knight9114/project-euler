#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t solution(uint64_t n) {
	// Create Prime Sieve
	int *numbers = malloc((n - 2) * sizeof(int));
	uint64_t sum = 0;

	// Load
	for (int i = 0; i < n - 2; i++) {
		numbers[i] = i + 2;
	}

	// Sieve
	for (int i = 0; i < n - 2; i++) {
		int x = numbers[i];

		if (x != 0) {
			sum += (uint64_t) x;
			for (int j = i + x; j < n - 2; j += x) {
				numbers[j] = 0;
			}
		}
	}

	// Free Sieve
	free(numbers);

	return sum;
}

int main() {
	printf("Solution #10: %ld\n", solution(2000000));
}
