#include <stdio.h>
#include <math.h>
#include <time.h>

int prime(int x)
{
	if (x % 2 == 0 && x != 2) return 0;
	for (int i = 3; i < x/2; i++){
		if (x % i == 0) return 0;
	}
	return 1;
}

long unsigned int solution(int n)
{
	long unsigned int sum = 2;
	for (int i = 3; i < n; i += 2){
		if (prime(i)) sum += i;
	}
	return sum;
}


int main(void)
{
	clock_t start, end;
	long unsigned int solve;
	
	start = clock();
	solve = solution(2000000);
	end = clock();

	double time = (double)(end - start)/CLOCKS_PER_SEC;
	
	printf("Solution: %ld (%lf s)\n",solve,time);

	return 0;
}
