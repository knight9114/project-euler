#include <stdio.h>
#include <stdint.h>

int collatz(uint64_t n) {
	// Base Case
	if (n == 1) {
		return 1;
	}

	// Next State
	uint64_t next = 0;
	if (n % 2 == 0) {
		next = n / 2;
	}
	else {
		next = (3 * n) + 1;
	}

	return collatz(next) + 1;
}

uint64_t solution(uint64_t limit) {
	// Prepare
	uint64_t idx = 0;
	int max = 0;

	// Search
	for (uint64_t i = 1; i < limit; i++) {
		int count = collatz(i);
		if (count > max) {
			max = count;
			idx = i;
		}
	}

	return idx;
}

int main() {
	printf("Solution #14: %ld\n", solution(1000000));
}
