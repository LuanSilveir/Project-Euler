#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Digits(int *D, int x)
{
	while(x){
		D[x % 10]++;
		x = x / 10;
	}
}

int Unique(int a, int b, int p)
{
	int D[10] = {0,0,0,0,0,0,0,0,0,0};

	Digits(D, a);
	Digits(D, b);
	Digits(D, p);
	
	if (D[0] != 0) return 0;
	for (int i = 1; i < 10; i++) if (D[i] != 1) return 0;
	return 1;
}

/* The only possible configuration is a 2 digit number
times a 3 digit number generating a 4 digit number 
_ _ x _ _ _ = _ _ _ _   */
void Insert(int *Array, int x)
{
	for (int i = 1; i <= Array[0]; i++) if (Array[i] == x) return;
	Array[0]++;
	Array[Array[0]] = x;
}

int solution(void)
{
	int p, result = 0;
	int *products = (int*) calloc(101,sizeof(int));

	for (int a = 0; a < 100; a++){
		for (int b = 0; b < 10000; b++){
			p = a*b;
			if (Unique(a,b,p)) Insert(products, p);
		}
	}
	
	for (int i = 1; i <= products[0]; i++) result += products[i];
	return result;
}


int main(void)
{
	clock_t start, end;
	int solve;

	start = clock();
	solve =  solution();
	end = clock();

	double time = (double) (end - start)/CLOCKS_PER_SEC;
	
	printf("Solution: %d (%lf s)\n", solve, time);

	return 0;
}
