#include <stdio.h>
#include <time.h>

void Coins(int *S, int size, int i, int aux, int *counter)
{
	if (aux == 1000) (*counter)++;
	else{
		for (int j = i; j < size; j++){
			if (aux + S[j] <= 1000) Coins(S, size, j, aux + S[j], counter);
		}
	}
} 

int solution(void)
{
	int S[8] = {200,100,50,20,10,5,2,1};
	int counter = 0;

	Coins(S, 8, 0, 0, &counter);

	return counter;
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
