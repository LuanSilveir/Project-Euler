#include <stdio.h>
#include <time.h>
#include <math.h>

/* Solution 1 */
int prime(long unsigned int n)
{	
	if (n % 2 == 0 && n != 2) return 0;
	
	for(int i = 3; i < n/2; i += 2)
	{
		if(n % i == 0) return 0;
	} 
	return 1;
}

long unsigned int solution1(long unsigned int x)
{
	long unsigned int n = x/2;
	if (n % 2 == 0) n++;
	
	for (long unsigned int i = n; i > 1; i -= 2)
	{
		if (x % i == 0)
		{
			if (prime(i)) return i;	
		}
	}
	if (x % 2 == 0) return 2;
	return x;
}

/* Solution 2: Check from the bottom up, find the first factor, divide the original
number by it and restart with the divided number */
long unsigned int firstfactor(long unsigned int x)
{
	if (x % 2 == 0) return 2;
	for (long unsigned int i = 3; i < x; i += 2)
	{
		if (x % i == 0)
		{
			return i;
		}
	}
	return 1;
}

long unsigned int solution2(long int x)
{
	long unsigned int v = 0;
	long unsigned int xaux = x;

	while (v != 1 && xaux != 2)
	{
		v = firstfactor(xaux);
		xaux = xaux/v;
	}
	return xaux;
}

int main(void)
{	
	clock_t start1, start2, end1, end2;
	long unsigned int input = (long unsigned int) 71;
	printf("%ld\n", input);
	start1 = clock();
	long unsigned int result1 = solution1(input);
	end1 = clock();
	
	double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

	start2 = clock();
	long unsigned int result2 = solution2(input);
	end2 = clock();

	double time2 = (double) (end2 - start1)/CLOCKS_PER_SEC;
	printf("Solution 1: %ld (%lf s)\n", result1, time1);
	printf("Solution 2: %ld (%lf s)\n", result2, time2);
	printf("Result1 is prime: %d\n", prime(result1));
	printf("Result2 is prime: %d\n", prime(result2));
	return 0;
}
