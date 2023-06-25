#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Add the two arrays num1 and num2 element-wise  */
int *Add(int *num1, int *num2)
{
	int carry = 0, result;
	int *Sum = (int*) calloc(2000, sizeof(int));
	for (int i = 0; i < 2000; i++){
		result = carry + num1[i] + num2[i];
		Sum[i] = result % 10;
		carry = result / 10;
	}
	return Sum;
}

/* Calculates the number of digits in the number represented by the array  */
int Digits(int *Array)
{
	int i = 1999;
	while(Array[i] == 0) i--;
	return i + 1;
}

/* Copies new into aux */
void Copy(int *new, int *aux)
{
	for (int i = 0; i < 2000; i++) aux[i] = new[i];
} 

/* Solution  */
int Solution(void)
{
	int index = 2, digits = 1;
	int *new = (int*) calloc(2000, sizeof(int));
	int *old = (int*) calloc(2000, sizeof(int));
	int *aux = (int*) calloc(2000, sizeof(int));
	new[0] = old[0] = 1;
	while(digits < 1000){
		index++;
		Copy(new,aux);
		new = Add(new, old);
		Copy(aux,old);
		digits = Digits(new);
	}
	return index;
}

int main(void)
{
	clock_t start, end;
	int solve;

	start = clock();
	solve = Solution();
	end = clock();

	double time = (double) (end - start)/CLOCKS_PER_SEC;
	printf("Solution: %d (%lf s)\n", solve, time);

	return 0;
}
