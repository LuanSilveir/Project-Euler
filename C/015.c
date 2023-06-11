#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Printer(long unsigned int **M, int size)
{
	for (int i = 0; i < size + 1; i++){
		for (int j = 0; j < size + 1; j++){
			printf("%ld ",M[i][j]);
		}
		printf("\n");
	}
}

/* Solution 1 */
void Pathways(int grid_size, int start_x, int start_y, long int *n)
{
	if (start_x == grid_size  && start_y == grid_size) (*n)++;
	else{
		if (start_x + 1 <= grid_size) Pathways(grid_size, start_x + 1, start_y, n);
		if (start_y + 1 <= grid_size) Pathways(grid_size, start_x, start_y + 1, n);
	}
}

/* Solution 2 */
void FillTable(long unsigned int **T, int grid_size, int x, int y)
{
	if (x < grid_size  && y < grid_size ){
		if (T[x][y+1] == 0) FillTable(T, grid_size, x, y + 1);
		if (T[x+1][y] == 0) FillTable(T, grid_size, x + 1, y);
		T[x][y] = T[x][y+1] + T[x+1][y];
	} 
	else T[x][y] = 1;
	/*else if (x == grid_size - 1 && y != grid_size - 1){
		if (T[x][y+1] == 0) FillTable(T, grid_size, x, y + 1);
		T[x][y] = T[x][y+1];
	}
	else if (y == grid_size - 1 && x != grid_size - 1){
		if (T[x+1][y] == 0) FillTable(T, grid_size, x + 1, y);
		T[x][y] = T[x+1][y];
	}
	//else T[x][y] = 1;
	else if (x == grid_size - 1 && y == grid_size -1) T[x][y] = 1;
	*/
}

long unsigned int Solution2(int grid_size)
{
	long unsigned int **T = (long unsigned int**) calloc(grid_size + 1, sizeof(long unsigned int*));
	for (int i = 0; i < grid_size + 1; i++) T[i] = (long unsigned int*) calloc(grid_size, sizeof(long unsigned int));
	T[grid_size][grid_size]=1;
	FillTable(T, grid_size, 0, 0);
	//Printer(T,grid_size);
	
	return T[0][0];
}


int main(void)
{
	long unsigned int n = 0;
	clock_t start1, start2, end1, end2;
	int x = 20;
	start1 = clock();
	Pathways(x,0,0,&n);
	end1 = clock();
	
	double time1 = (double) (end1 - start1)/CLOCKS_PER_SEC;
	printf("Solution 1: %ld (%lf s)\n",n, time1);

	start2 = clock();
	long unsigned int s = Solution2(x);
	end2 = clock();

	double time2 = (double) (end2 - start2)/CLOCKS_PER_SEC;

	printf("Solution2: %ld (%lf s)\n", s, time2);
	return 0;
}
