#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(int n) {
	char string[10];
	sprintf(string, "%d", n);
	int len = strlen(string);

	for (int i = 0; i < len; i++) {
		if (string[i] != string[len - i - 1]) {
			return false;
		}
	}

	return true;
}

int solution_4(int min, int max) {
	int output = 0;

	for (int x = max - 1; x > min; x--) {
		for (int y = x - 1; y > min - 1; y--) {
			int prod = x * y;
			if (!(prod < output) && is_palindrome(prod)) {
				output = prod;
			}
		}
	}

	return output;
}

int main() {
	printf("Solution #4: %d\n", solution_4(100, 1000));
}
