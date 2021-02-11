#include <stdio.h>

int solution_1(int n) {
	int output = 0;

	for (int i = 0; i < n; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			output += i;
		}
	}

	return output;
}

int main() {
	printf("Solution #1: %d\n", solution_1(1000));
}
