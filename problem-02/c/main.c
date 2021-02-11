#include <stdio.h>

int fibonacci() {
	static int curr = 0;
        static int next = 1;

	int update = curr + next;
	curr = next;
	next = update;

	return curr;
}

int solution_2(int n) {
	int output = 0;
	int x = fibonacci();

	while (x < n) {
		if (x % 2 == 0) {
			output += x;
		}
		x = fibonacci();
	}

	return output;
}

int main() {
	printf("Solution #2: %d\n", solution_2(4000000));
}
