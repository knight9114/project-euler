#include <stdint.h>
#include <stdio.h>

uint64_t n_choose_k(int n, int k) {
	// Prepare
	uint64_t prod = 1;

	// Load
	for (int i = 1; i <= k; i++) {
		prod *= n - k + i;
		prod /= i;
	}

	return prod;
}

uint64_t solution(int n_rows, int n_cols) {
	return n_choose_k(n_rows + n_cols, n_cols);
}

int main() {
	printf("Solution #15: %ld\n", solution(20, 20));
}
