#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Permutation(int *Digits, int i, int n);

typedef struct _integerarray{
	int n;
	int *arr;
} Array;

/* Creates an array from the array N without the element n */
Array *CreateArray(Array *N,  int n)
{
	Array *A = (Array*) calloc(1, sizeof(Array*)); 
	A->n = N->n - 1;
	A->arr = (int*) calloc(N->n - 1,sizeof(int));
	
	int i = 0;
	while((N->arr)[i] != n){
		(A->arr)[i] = (N->arr)[i];
		i++;
	}
	for (i++; i < A->n + 1; i++) (A->arr)[i-1] = (N->arr)[i];
	return A;
}

/* Concatenates str with the char c (str||c)  */
char *Cat(char *str, char c)
{
	int new_size = strlen(str) + 2, i;
	char *new = (char*) calloc(new_size, sizeof(char));
	
	for (i = 0; i < new_size - 2; i++) new[i] = str[i];
	new[i++] = c;
	new[i] = '\0';
	
	return new;
}


/* Variation that prints all the permutations of numbers */
void SolutionPrint(Array *N, char *string)
{
	if (N->n == 0) printf("%s\n",string);
	else {
		Array *Aux;
		char *conc_str;
		int ex;
		for (int i = 0; i < N->n; i++){
			ex = (N->arr)[i];
			Aux = CreateArray(N, ex);
			conc_str = Cat(string,ex+48);
			SolutionPrint(Aux, conc_str); 
		}
	}
}

/* Solution */
void Solution(Array *N, char *string, int *count)
{   
    if (N->n == 0){
		(*count)++;
		if (*count == 1000000) printf("Solution: %s\n", string);
	}
    else {
        Array *Aux;
        char *conc_str;
        int ex;
        for (int i = 0; i < N->n; i++){
            Solution(CreateArray(N,(N->arr)[i]), Cat(string, (N->arr)[i] + 48), count);
        }
    }
}

int main(void)
{
	int Digits[10] = {0,1,2,3,4,5,6,7,8,9};
	int Result = 0;
	clock_t start, end;
	Array T;
	
	T.n = 10;
	T.arr = Digits;
	
	start = clock();
	Solution(&T,"",&Result);	
	end = clock();

	double time = (double) (end - start)/CLOCKS_PER_SEC;
	printf("Time: %lf\n", time);
	return 0;
}
