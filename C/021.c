#include <stdio.h>
#include <stdlib.h>
int SumDivisors(int x)
{
	int sum = 0;
	for (int i = 1; i <= x/2; i++)	if (x % i == 0) sum += i;
	return sum;
}

int solution(void)
{
	int *numbers = (int*) calloc(10000, sizeof(int));
	int aux, sumaux, result = 0;
	numbers[0] = -1; numbers[1] = -1;
	for (int i = 2; i < 10000; i++){
		aux = SumDivisors(i);
		sumaux = SumDivisors(aux);
		if (i == sumaux && i != aux) result += i;
	}
	
	return result;
}


int main(void)
{
	int solve = solution();
	printf("%d\n", solve);

	return 0;
}
