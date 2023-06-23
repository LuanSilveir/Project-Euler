#include <stdio.h>
#include <stdlib.h>

/* Sum of the proper divisors of a number x */
int DivisorsSum(int x)
{	
	int sum = 0;
	for (int i = 1; i <= x/2; i++) if (x % i == 0) sum += i;
	return sum;
}

/* Array of Abundant numbers below x */
int *Abundant(int x, int *size)
{
	int *Anumbers = (int*) calloc(x, sizeof(int));
	*size = 0;	
	for (int i = 1; i < x; i++) if (DivisorsSum(i) > i){
		Anumbers[*size] = i;
		(*size)++;
	}	
	return Anumbers;
}

/* Prints an Array A of size n */
void Print(int *A, int n)
{
	printf("[");
	for (int i = 0; i < n - 1; i++) printf("%d,", A[i]);
	printf("%d]\n",A[n-1]);
}

/* Numbers that can be constructed by the sum of two abundant numbers 
Array of 0s and 1s where if n is an abundant number then Array[n] = 1
and Array[n] = 0 otherwise. */
int *Constructible(int *Abundant, int Abundant_size)
{
	int *Cons = (int*) calloc(28123, sizeof(int));
	int sum;
	
	for (int i = 0; i < Abundant_size; i++){
		for (int j = 0; j <= i; j++){
			sum = Abundant[i] + Abundant[j];
			if (sum < 28123) Cons[sum] = 1;
		}
	}
	return Cons;
}

/* Solution  */
int solution()
{
	int Abundant_size, sum = 0;
	int *ConstructibleN, *AbundantN;
 
	AbundantN = Abundant(28123, &Abundant_size);
	ConstructibleN = Constructible(AbundantN, Abundant_size);

	for (int i = 1; i < 28123; i++)	if (ConstructibleN[i] == 0) sum += i;
	return sum;
}

int main(void)
{
	printf("Solution: %d\n", solution());	
	
	return 0;
}
