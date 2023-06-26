#include <stdio.h>
#include <stdlib.h>

typedef struct _set{
	int *elements;
	int size;
} Set;

/*
int Membership(char *str, char c)
{
	int i = 0;
	while (str[i]){
		if (str[i] == c) return 1;
		i++;
	}
	return 0;
}

char *Cat(char *str, char c)
{
	int i = 0;
	char *new = (char*) calloc(strlen(str)+2, sizeof(char));
	while (str[i]){
    	new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	
	return new;
}*/

int Membership(Set S, int x)
{
	for (int i = 0; i < 1000; i++) if (S.elements[i] == x) return 1;
	return 0;
}

void Insert(Set *S, int x)
{
	int i = 0;
	while ((S->elements)[i] != 0) i++;
	S->elements[i] = x;
	S->size++;
}

int RecFraction(int x)
{
	Set R;
	int remainder = 1, counter = 0;

	R.elements = (int*) calloc(1000, sizeof(int));
	R.size = 0;

	while(!Membership(R, remainder)){
		if (remainder == 0) return 0;
		Insert(&R,remainder);
		remainder *= 10;
		while (remainder < x){
			remainder *= 10;
			counter++;
		}
		remainder %= x;
		//printf("%d\n",remainder);
	}
	free(R.elements);
	return R.size + counter;	
}

/* Solution  */
int Solution()
{
	int max = 0, aux, solution;
	for (int i = 1; i < 1000; i++){
		aux = RecFraction(i);
		//printf("Number: %d Fraction Size: %d\n", i, aux); 
		if (aux > max){
			max = aux;
			solution = i;
		}
	}
	return solution;
}

int main(void)
{

	//char *str = "10841";
	//char c = '5';
	//printf("%d\n",RecFraction(17));
	printf("%d\n",Solution());

}
