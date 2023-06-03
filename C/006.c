#include <stdio.h>
#include <time.h>

/* Solution 1 */
int sumsquare(int x){

	int sum = 0;
	for (int i = 1; i <= x; i++) sum += i*i;
	return sum;
}

int squaresum(int x){
	
	int sum = 0;
	for (int i = 1; i <= x; i++) sum += i;
	return sum * sum;
}

int solution1(int x){
	
	int result;
	return squaresum(x) - sumsquare(x); 
}

/* Solution 2  */
int solution2(int x){

	int sumsquare = 0, squaresum = 0;
	for (int i = 1; i <= x; i++){
		squaresum += i;
		sumsquare += i*i;
	}
	return squaresum * squaresum - sumsquare;
}

int main(void){
	
	clock_t start1, start2, end1, end2;
	int solve1, solve2;
	
	start1 = clock();
	for (int i = 0; i < 10000; i++) solve1 = solution1(100);
	end1 = clock();

	start2 = clock();
	for (int i = 0; i < 10000; i++) solve2 = solution2(100);
	end2 = clock();
	
	double time1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
	double time2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
	
	printf("Solution 1: %d (%lf s)\n", solve1, time1);
	printf("Solution 2: %d (%lf s)\n", solve2, time2);
	
	return 0;
}
