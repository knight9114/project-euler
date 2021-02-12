#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t max_int(uint64_t a, uint64_t b) {
	if (a < b) return b;
	return a;
}

int read_integers_2d(const char *path, int r, int c, int ***numbers) {
	// Open File
	FILE *fp = NULL;
	if ((fp = fopen(path, "r")) == NULL) {
		printf("fatal - failed to open %s\n", path);
		return 0;
	}

	// Prepare Array
	*numbers = (int**)malloc(r * sizeof(int*));
	for (int i = 0; i < r; i++) {
		(*numbers)[i] = (int *)malloc(c * sizeof(int));
	}

	// Read File
	int count = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (fscanf(fp, "%2d", &(*numbers)[i][j]) == 1) {
				count++;
			}
		}
	}

	return count;
}

uint64_t horizontal(int r, int c, int n, int **numbers) {
	uint64_t prod = 1;
	for (int i = 0; i < n; i++) {
		prod *= (uint64_t) numbers[r][c + i];
	}
	return prod;
}

uint64_t vertical(int r, int c, int n, int **numbers) {
	uint64_t prod = 1;
	for (int i = 0; i < n; i++) {
		prod *= (uint64_t) numbers[r + i][c];
	}
	return prod;
}

uint64_t diagonal_1(int r, int c, int n, int **numbers) {
	uint64_t prod = 1;
	for (int i = 0; i < n; i++) {
		prod *= (uint64_t) numbers[r + i][c + i];
	}
	return prod;
}

uint64_t diagonal_2(int r, int c, int n, int **numbers) {
	uint64_t prod = 1;
	for (int i = 0; i < n; i++) {
		prod *= (uint64_t) numbers[r + i][c - i];
	}
	return prod;
}

uint64_t solution(const char *path, int n_rows, int n_cols, int length) {
	// Prepare
	int **numbers = NULL;
	
	// Read File
	int count = 0;
	int num = n_cols * n_rows;
	if ((count = read_integers_2d(path, n_rows, n_cols, &numbers)) != num) {
		printf("fatal - unexpected number of integers read (%d != %d)", count, num);
		return 0;
	}

	// Search
	uint64_t output = 0;
	for (int r = 0; r < n_rows; r++) {
		for (int c = 0; c < n_cols; c++) {
			// Vertical
			if (r < n_rows - length) {
				output = max_int(output, vertical(r, c, length, numbers));
			}

			// Horizontal
			if (c < n_cols - length) {
				output = max_int(output, horizontal(r, c, length, numbers));
			}

			// Diagonal "\"
			if ((r < n_rows - length) && (c < n_cols - length)) {
				output = max_int(output, diagonal_1(r, c, length, numbers));
			}

			// Diagonal "/"
			if ((r < n_rows - length) && (c > length - 1)) {
				output = max_int(output, diagonal_2(r, c, length, numbers));
			}
		}
	}

	// Free Memory
	for (int i = 0; i < n_rows; i++) {
		free(numbers[i]);
	}
	free(numbers);

	return output;
}

int main() {
	char *path = "/home/knight/Documents/github/project-euler/problem-11/input.txt";
	printf("Solution #11: %ld\n", solution(path, 20, 20, 4));
}
