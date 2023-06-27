#include <stdio.h>
#include <time.h>

int Prime(int x)
{	
	if (x % 2 == 0 && x != 2 || x < 2) return 0;
	for (int i = 3; i < x/2; i += 2){
		if (x % i == 0) return 0;
	}
	return 1;
}

int PrimeGenerator(void)
{
	static int candidate = 1;

	candidate++;
	while (!Prime(candidate)) candidate++;

	return candidate;		
}

int NumberOfPrimes(int a, int b)
{
	int count = 1, i = 1, value;
	value = a + b + 1;
	while (Prime(value)){
		i++;
		count++;
		value = i*i + a*i + b;
	}
	return count;
}
/*
int *PairGenerator(void)
{
	int *pair = (int*) calloc(2, sizeof(int));
	static int a = -10000, b = PrimeGenerator();

	if (a > 998){
		b = PrimeGenerator();
		a = -b;
	}
	else a += 1;
	pair[0] = a;
	pair[1] = b;
	return pair;
}*/

/* Updates the pair values from the previous ones. */
void UpdatePair(int *a, int *b)
{
	if (*a == 999){
		*b = PrimeGenerator();
		*a = -(*b);
	}
	else (*a)++;
}
/* Solution
Narrowing the search: b has to be prime and -b -1 < a < 1000 */
int Solution()
{
	int a = -2, b = 2, max = 0, aux, answer;
	max = NumberOfPrimes(a,b);

	while (b < 1000){
		UpdatePair(&a,&b);
		aux = NumberOfPrimes(a,b);
		if (aux > max){
			max = aux;
			answer = a*b;
		}
	}
	return answer;
}


int main(void)
{
	int solve;
	clock_t start, end;

	start = clock();
	solve = Solution();
	end = clock();

	double time = (double) (end - start)/CLOCKS_PER_SEC;
	
	printf("Solution: %d (%lf s)\n", solve, time);
	
	return 0;
}
