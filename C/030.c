#include <stdio.h>
#include <time.h>

int FifthSum(int x)
{
	int sum = 0, aux;
	while (x){
		aux = x % 10;
		sum += aux*aux*aux*aux*aux;
		x /= 10;
	}
	return sum;
}
/* Solution
There is an upper limit to the numbers that need to be checked. The maximum value of
the summation of an n-digit number is n*9^5 and the smallest n-digit number is 10^(n-1)
At some point, as n gets bigger 10^(n-1) will always be bigger than n*9^5. In this case
the smallest integer that satisfies 10^(n-1) > n*9^5 is 7, so we only test up to 7 digits,
that is 10^6. */
int solution(void)
{
	int sum = 0;
	for (int i = 2; i < 1E6; i++){
		if (i == FifthSum(i)) sum+= i;
	}
	return sum;
}

int main(void)
{
	clock_t start, end;
	int solve;

	start = clock();
	solve = solution();
	end = clock();

	double time = (double) (end - start) / CLOCKS_PER_SEC;

	printf("Solution: %d (%lf s)\n", solve, time);	

	return 0;
}
