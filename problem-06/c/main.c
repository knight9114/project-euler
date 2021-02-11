#include <stdio.h>

int sum_of_squares(int n) {
	return n * (n + 1) * (2*n + 1) / 6;
}

int square_of_sum(int n) {
	int sum = n * (n + 1) / 2;
	return sum * sum;
}

int solution(int n) {
	return square_of_sum(n) - sum_of_squares(n);
}

int main() {
	printf("Solution #6: %d\n", solution(100));
}
