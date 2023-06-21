#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrinterS(char **A, int n)
{

	for (int i = 0; i < n; i++) printf("%s ",A[i]);
	printf("\n");
}

void InsertionSort(int *A, int n)
{
	int j, key;
	for (int i = 1; i < n; i++){
		j = i - 1;
		key = A[i];
		while (key < A[j] && j >= 0){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

int Smaller(char *str1, char *str2) 
{
	int n = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2); 
	for (int i = 0; i < n; i++){
		if (str1[i] < str2[i]) return 1;
		else if (str1[i] > str2[i]) return 0;
	}
	if (strlen(str1) < strlen(str2)) return 1;
	else return 0;
}

void StringIS(char **A, int n)
{
	int j;
	char *key;
    for (int i = 1; i < n; i++){
        j = i - 1;
        key = A[i];
        while (j >= 0 && Smaller(key, A[j])){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
	}
}

int Worth(char *str)
{
	int size = strlen(str), worth = 0, count = 0;
	for (int i = 0; i < size; i++){count +=1; worth += str[i] - 'A' + 1;}
	return worth;
}

long long unsigned int Score(char **Names, int n)
{
	long long unsigned int score = 0;
	for (int i = 0; i < n; i++)	score += Worth(Names[i]) * (i+1);
	return score;
}

char **Read(char *arq, int *n)
{
	FILE *fp = fopen(arq, "r");
	fscanf(fp,"%d\n", n);
	
	char **Names = (char**) calloc(*n, sizeof(char*));
	for (int i = 0; i < *n; i++) Names[i] = (char*) calloc(30, sizeof(char));
	for (int i = 0; i < *n; i++) fscanf(fp, "%s\n", Names[i]);
	fclose(fp);
	
	return Names;
}


int main(int argc, char **argv)
{
	int n;
	char **Names = Read(argv[1], &n);
	
	StringIS(Names, n);

	long long unsigned int result = Score(Names, n);
	printf("Solution: %lld\n", result);
	return 0;
}
