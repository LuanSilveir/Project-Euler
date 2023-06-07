#include <stdio.h>
#include <stdarg.h>
#include <time.h>

/* Solution 1*/
int horizontal(int grid[][20], int size)
{
	int prod, max = 0, l, c, counter = 0;
	for (int line = 0; line < 20; line++){
		for (int column = 0; column <= 20 - size; column++){
			prod = 1;
			counter++;
			for (int i = 0; i < size; i++) prod *= grid[line][column+i];
			if (prod > max){max = prod; l = line; c = column;}		
		}
	}
	//printf("Horizontal:: Line: %d Column: %d Max: %d Counter: %d\n", l, c, max, counter);
	return max;
}

int vertical(int grid[][20], int size)
{
	int prod, max = 0, l, c, counter = 0;
	for (int column = 0; column < 20; column++){
		for (int line = 0; line <= 20 - size; line++){
			prod = 1;
			counter++;
			for (int i = 0; i < size; i++){
				prod *= grid[line+i][column];
			}
			if (prod > max){max = prod; l = line; c = column;}
		}
	}
	//printf("Vertical:: Line: %d Column: %d Max: %d Counter: %d\n", l, c, max,counter);
	return max;
}

int diagonal(int grid[][20], int size)
{

	int prodm, prods, max = 0, l, c, counter = 0;
	for (int line = 0; line <= 20 - size; line++){
		for (int column = 0; column <= 20 - size; column++){
			prodm = 1;
			counter++;
			for (int i = 0; i < size; i++){
				 prodm *= grid[line+i][column+i];
			}
			if (prodm > max){max = prodm; l = line; c = column;} 
		}
	}
	//printf("Diagonal:: Line: %d Column: %d Max: %d Counter: %d\n", l, c, max,counter);
	return max;
}

int secdiagonal(int grid[][20], int size)
{
	int prod, max = 0, l, c, counter = 0;
	for (int line = 0; line <= 20 - size; line++){
		for (int column = 19; column >= size - 1; column--){
			prod = 1;
			counter++;
			//printf("(%d,%d)\n",line,column);
			for (int i = 0; i < size; i++) prod *= grid[line+i][column-i];
			if (prod > max){max = prod; l = line; c = column;}

		}
	}
	//printf("Sec Diagonal:: Line: %d Column: %d Max: %d Counter: %d\n", l, c, max,counter);  
	return max;
}

int biggest(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int max(int count, ...)
{
	va_list list;
	va_start(list,count);
	int max_n = 0;
	
	for (int i = 0; i < count; i++){
		max_n = biggest(max_n, va_arg(list,int));
	}
	return max_n;
}

int solution1(int grid[][20], int size)
{
    int v, h, m, s, Max;
    v = vertical(grid, size);
    h = horizontal(grid, size);
    m = diagonal(grid, size);
    s = secdiagonal(grid, size);
    Max = max(4,v, h, m, s);
    return Max;
}


/* Solution 2*/ 

int cross(int grid[][20], int size)
{   
    int prodm, prods, max = 0, counter = 0;
    for (int line = 0; line < 20; line++){
        for (int column = 0; column <= 20 - size; column++){
            prodm = 1; prods = 1;
            counter++; 
            for (int i = 0; i < size; i++){
                prodm *= grid[line][column+i];
                prods *= grid[column+i][line];
            }
            if (prodm > max) max = prodm;
            if (prods > max) max = prods;
        }
    }
    //printf("Cross:: Max: %d Counter: %d\n", max, counter);
    return max;
}


int times(int grid[][20], int size)
{
    int prodm, prods, max = 0, counter = 0;
    for (int line = 0; line <= 20 - size; line++){
        for (int column = 0; column <= 20 - size; column++){
            prodm = prods = 1;
            counter++;
            for (int i = 0; i < size; i++){
                prodm *= grid[line+i][column+i];
                prods *= grid[line+i][19-column-i];
                if (prodm > max) max = prodm;
                if (prods > max) max = prods;
            }
        }
    }
    //printf("Diagonal:: Max: %d Counter: %d\n", max, counter);
    return max;
}

int solution2(int grid[][20], int size)
{
	int c, t, max;
	c = cross(grid, size);
	t = times(grid, size);
	if (c > t) max = c;
	else max = t;
	return max;
}
int solution(int grid[][20], int size)
{
	int v, h, m, s, Max;
	v = vertical(grid, size);
	h = horizontal(grid, size);
	m = diagonal(grid, size);
	s = secdiagonal(grid, size);
	Max = max(4,v, h, m, s);
	return Max; 
}

int main(void)
{
	int grid[20][20] = {
{ 8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8},
{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0},
{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
{52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91},
{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
{24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
{67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21},
{24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
{21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95},
{78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92},
{16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57},
{86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
{19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40},
{ 4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
{88, 36, 68, 87, 57, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
{ 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36},
{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16},
{20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54},
{ 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48}}; 

	//int solve = horizontal(grid, 4);
	//printf("%d\n",solve);
	//printf("%d\n",cross(grid, 4));
	//printf("%d\n",times(grid, 4));
	//printf("%d\n",diagonal(grid, 4));
	//printf("%d\n",secdiagonal(grid, 4));
	clock_t start1, start2, end1, end2;
	int solve1, solve2;
	start1 = clock();
	solve1 = solution1(grid,4);
	end1 = clock();

	start2 = clock();
	solve2 = solution2(grid,4);
	end2 = clock();
	
	double time1 = (double) (end1 - start1)/CLOCKS_PER_SEC;
	double time2 = (double) (end2 - start2)/CLOCKS_PER_SEC;
	
	printf("Solution 1: %d (%lf s)\n",solve1, time1);
	printf("Solution 2: %d (%lf s)\n",solve2, time2);

	return 0;
}
