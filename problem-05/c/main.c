#include <stdio.h>
#include <stdbool.h>

int solution(int max_mod) {
	int output = max_mod;

	for (int i = max_mod; ; i += max_mod) {
		bool found = true;
		for (int j = max_mod; j > 1; j--) {
			if (i % j != 0) {
				found = false;
				break;
			}
		}

		if (found) {
			output = i;
			break;
		}
	}

	return output;
}

int main() {
	printf("Solution #5: %d\n", solution(20));
}

