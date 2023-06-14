#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Destroy(int **P, int n);

int **ReadPiramid(char *arq, int *n){
	
	FILE *fp = fopen(arq, "r");

	fscanf(fp, "%d\n", n);
	
	int **P = (int**) calloc(*n, sizeof(int*));
	
	for (int i = 0; i < *n; i++){
		P[i] = (int*) calloc(i+1, sizeof(int));
		for (int k = 0; k < i; k++){
			fscanf(fp, "%d ", &(P[i][k]));
		}
	fscanf(fp, "%d\n", &(P[i][i]));	
	}
	return P;	
}

void PrintPiramid(int **M, int n)
{
	int pad = 16;
	for (int i = 0; i < n; i++){
		printf("%*c", pad, ' ');
		//printf("%*d", pad, M[i][0]);
		for (int j = 0; j < i+1; j++){
			printf(" %02d", M[i][j]);
		}
		printf("\n");
		pad --;
	}
}

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int solution(char *arq)
{
	int n, m = 0;
	int **P = ReadPiramid(arq, &n);
	printf("Piramid: \n");
	PrintPiramid(P, n);

	for (int i = 1; i < n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0) P[i][j] +=  P[i-1][j];
			else if(j == i) P[i][j] += P[i-1][j-1];
			else P[i][j] = P[i][j] + max(P[i-1][j-1],P[i-1][j]);
		}
	}
	for (int k = 0; k < n; k++)	if (P[n-1][k] > m) m = P[n-1][k];
	printf("\nCumulative Piramid: \n");
	PrintPiramid(P, n);
	Destroy(P,n);
	return m;
}

void Destroy(int **P, int n)
{
	if (P != NULL) for (int i = 0; i < n; i++) free(P[i]); 
	free(P);
}


int main(int argc, char **argv)
{
	int n, s;
	clock_t start, end;
	double time;

	start = clock();
	s = solution(argv[1]);
	end = clock();
	
	time = (double) (end - start) / CLOCKS_PER_SEC;	
	printf("Solution: %d (%lf s)\n", s, time);
	//PrintPiramid(P,15);
	return 0;
}
