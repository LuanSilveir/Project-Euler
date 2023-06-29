#include <stdio.h>
#include <time.h>



/* Solution
Let a layer n = 1,2,... be the nth square
The first summable element of the layer i+1 (i>1) is (2i-1)^2 + 2i
The next will be at a distance of 2i of the last (for the 4 elements in a layer)
So the jth element in the (i+1)th layer is E(i+1,j) = (2i-1)^2+2i+2i(j-1) for 1<=j<=4
Lastly a n x n spiral has (n-1)/2 layers, for a 1001 spiral we have 500 layers
*/
int Solution(void)
{
	int sum = 1, layer = 500;
	if (layer == 1) return sum;
	for (int i = 1; i <= layer; i++){
		for (int j = 1; j < 5; j++){
			sum += (2*i-1)*(2*i-1)+2*i*j;
		} 
	}
	return sum;
}


int main(void)
{
	clock_t start, end;
	int solve;

	start = clock();
	solve = Solution();
	end = clock();

	double time = (double) (end - start)/CLOCKS_PER_SEC;

	printf("Solution: %d (%lf s)\n", solve, time);
		
	return 0;
}
