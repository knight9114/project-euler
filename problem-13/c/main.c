#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

uint64_t solution(const char *path, int n) {
	// Prepare
	int n_digits_end = (int) (log10((double) n) + 1);
	int n_digits_expanded = n + n_digits_end;

	// Open File
	FILE *fp = NULL;
	if ((fp = fopen(path, "r")) == NULL) {
		printf("fatal - failed open file\n");
		return 0;
	}

	// Prepare to Read File
	char *prefix = malloc((n_digits_expanded + 1) * sizeof(char));
	char *buffer = NULL;
	size_t len = 0;
	ssize_t n_read = 0;
	uint64_t total = 0;

	// Read File
	while ((n_read = getline(&buffer, &len, fp)) != -1) {
		// Extract Substring
		memcpy(prefix, &buffer[0], n_digits_expanded);
		prefix[n_digits_expanded] = '\0';

		// Accumulate
		total += strtoul(prefix, NULL, 10);
	}

	// Free Buffers
	free(buffer);
	free(prefix);
	fclose(fp);

	// Get First n-Digits
	int n_digits_result = (int) (log10((double) total) + 1);
	uint64_t divisor = 1;
	for (int i = 0; i < n_digits_result - n; i++) {
		divisor *= 10;
	}

	return total / divisor;
}

int main() {
	const char *path = "/home/knight/Documents/github/project-euler/problem-13/input.txt";
	printf("Solution #13: %ld\n", solution(path, 10));
}
