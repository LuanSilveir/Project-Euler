#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _set{
	int size;
	int **elements;
} Set;

void Printer(int *n);
void Multiply(int **number, int n);
int *Convert(long unsigned int x);
int Equal(int *element1, int *element2);
int Membership(Set *S, int *element);
void Insert(Set *S, int *element);
int *Power(int a, int b);

void Multiply(int **number, int n)
{
	int carry = 0, result, i = 1;
	
	do { 
		result = (*number)[i] * n + carry;
		(*number)[i] = result % 10;
		carry = result / 10;
		i++;

	} while (carry != 0 && result != 0 || i <= (*number)[0]);
	(*number)[0] = i - 1;
}
int *Convert(long unsigned int x)
{
	int *number = (int*) calloc(500, sizeof(int));
	int i = 1;

	while(x){
		number[i] = x % 10;
		x /= 10;
		i++;
	}
	number[0] = i - 1;
}
int Equal(int *element1, int *element2)
{
	for (int i = 0; i < (element1[0])+1; i++) if ((element1)[i] != (element2)[i]) return 0;
	return 1;
}

int Membership(Set *S, int *element)
{
	for (int i = 0; i < S->size; i++) if (Equal((S->elements)[i], element)) return 1;
	return 0;
}

void Insert(Set *S, int *element)
{
	if (!Membership(S,element)){
		S->size++;
		S->elements = (int**) realloc(S->elements, (S->size)*sizeof(int**));
		(S->elements)[S->size-1] = element;
	}
}

int *Power(int a, int b)
{
	int *power = Convert(a);
	int carry = 0, result, digits = 0;
	
	for (int i = 1; i < b; i++){
		Multiply(&power,a);
	}
	return power; 
}

void DestroyElements(Set *S)
{
	if (S->elements != NULL){
		for (int i = 0; S->size + 1; i++){
			free((S->elements)[i]);
		}
		free(S->elements);
	}
}

int solution(void)
{
	Set S;
	S.size = 0;
	S.elements = (int**) calloc(1, sizeof(int*));
	int *aux;
	int *K = Convert(8);
	for (int a = 2; a < 101; a++){
		for (int b = 2; b < 101; b++){
			aux = Power(a,b);
			Insert(&S, aux);
		}
	}
	DestroyElements(&S);
	return S.size;
}

void Printer(int *n)
{
	for (int i = n[0]; i > 0; i--) printf("%d",n[i]);
	printf("\n");
}

int main(void)
{
	clock_t start, end;
	int solve;

	start = clock();
	solve = solution();
	end = clock();
	
	double time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("Solution: %d (%lf s)\n", solve, time);
	
	return 0;
}
