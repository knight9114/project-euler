#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t sqrt_int(uint64_t n) {
	return (uint64_t) (sqrt((double) n) + 1);
}

uint64_t count_factors(uint64_t n, uint64_t start) {
	// Default Case
	if (n == 1) return 1;

	// Recurse
	for (uint64_t i = start; i < sqrt_int(n); i++) {
		if (n % i == 0) {
			uint64_t n_factors = 1;

			while (n % i == 0) {
				n /= i;
				n_factors++;
			}

			return count_factors(n, i + 1) * n_factors;
		}
	}

	return 2;
}

uint64_t solution(uint64_t n) {
	// Prepare
	uint64_t output = 0;
	uint64_t n_factors = 0;

	// Search
	for (uint64_t i = 0; ; i++) {
		// Handle Summation
		if (i % 2 == 0) {
			n_factors = count_factors(i / 2, 2) * count_factors(i + 1, 2);
		}

		else {
			n_factors = count_factors(i, 2) * count_factors((i + 1) / 2, 2);
		}

		// Break
		if (n_factors > n) {
			output = i * (i + 1) / 2;
			break;
		}
	}

	return output;
}

int main() {
	printf("Solution #12: %ld\n", solution(500));
}
