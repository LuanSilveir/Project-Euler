#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiply(int *array, int size, int n)
{
	int result, carry = 0;
	for (int i = 0; i < size; i++){
		result = carry + array[i] * n;
		array[i] = result % 10;
		carry = result / 10;
	}
}

void Printer(int *array, int size)
{	int i = size - 1;
	while (array[i] == 0) i--;
	for (;i >= 0; i--) printf("%d",array[i]);
	printf("\n");
}

int SumDigits(int *array, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) sum += array[i];
	return sum;
}

int solution()
{
	int size = 200, solve;
	int *array = (int*) calloc(size, sizeof(int));
	array[0] = 1;
	for (int i = 2; i < 101; i++){
		multiply(array, size, i);
	}
	//Printer(array, size);
	solve = SumDigits(array, size);
	
	return solve;
}

int main(void)
{
	clock_t start, end;
	int solve;
	
	start = clock();
	solve = solution();
	end = clock();
	
	double time = (double) (end - start)/CLOCKS_PER_SEC;

	printf("Solution: %d (%lf s)\n", solve, time);	
	return 0;
}
