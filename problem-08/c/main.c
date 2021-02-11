#include <stdio.h>
#include <stdlib.h>

long long int array_product(int n, int *array) {
	long long int prod = 1;
	for (int i = 0; i < n; i++) {
		prod *= array[i];
	}
	return prod;
}

long long int max_int(long long int a, long long int b) {
	if (a < b) return b;
	return a;
}

long long int solution(int n, const char *path) {
	// Open File
	FILE *fp = NULL;
	if ((fp = fopen(path, "r")) == NULL) {
		printf("fatal - failed to open file (%s)\n", path);
		return 0;
	}

	// Search
	int *numbers = malloc(n * sizeof(int));
	int idx = 0;
	int input = 0;
	long long int output = 0;
	while ((fscanf(fp, "%1d", &input)) != EOF) {
		// Load Array
		numbers[idx % n] = input;

		// Check Sum
		if (!(idx < n)) {
			output = max_int(output, array_product(n, numbers));
		}

		idx++;
	}

	// Close File
	fclose(fp);

	return output;
}

int main() {
	const char *path = "/home/knight/Documents/github/project-euler/problem-08/input.txt";
	printf("Solution #8: %lli\n", solution(13, path));
}
