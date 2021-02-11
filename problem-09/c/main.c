#include <stdio.h>
#include <stdbool.h>

bool is_pythagorean_triplet(int a, int b, int c) {
	return ((a * a) + (b * b)) == (c * c);
}

int solution(int n) {
	for (int a = 1; a < n; a++) {
		for (int b = 1; b < n; b++) {
			for (int c = 1; c < n; c++) {
				if (is_pythagorean_triplet(a, b, c) && ((a + b + c) == n)) {
					return a * b * c;
				}
			}
		}
	}

	return 0;
}

int main() {
	printf("Solution #9: %d\n", solution(1000));
}
