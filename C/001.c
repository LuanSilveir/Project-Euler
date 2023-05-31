#include <stdio.h>

/* Solution 1 */
int solution1(void)
{
	int result = 0;

	for (int i = 1; i < 1000; i++) /* ~ 1000 iterations  */
	{
		if (i % 3 == 0 || i % 5 == 0) result += i;
	}
	
	return result;
}

/* Solution 2 - From the site  */
int SumDivisibleBy(int n)
{
	int sum = 0;

	for (int i = n; i < 1000; i += n) sum += i; /* ~ 1000/n iterations  */
	
	return sum;
}

int solution2(void) /* ~ (1000/3 + 1000/5 + 1000/15) = ~ 599 iterations */
{
	return SumDivisibleBy(3) + SumDivisibleBy(5) - SumDivisibleBy(15);
}

int main(void)
{
	int result1 = solution1();
	int result2 = solution2();
	
	printf("Solution 1: %d\n", result1);
	printf("Solution 2: %d\n", result2);
	
	return 0;
}
