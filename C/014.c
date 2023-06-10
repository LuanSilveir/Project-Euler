#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long unsigned int solution(int range, int *seqSize)
{	
	/* Starting the first value  */
	seqSize[0] = 1;
	
	long int counter, max = 0;
	long unsigned int aux, max_number = 0;	
	/* Evaluating every number in the given range  */
	for (int i = 2; i < range; i++){
		aux = i;     // Create the auxiliary variable that will be transformed
		counter = 0; // Counter of the number of transformations
		while (1){
			if (aux % 2 == 0) aux = aux / 2;      // Transformation if it is even 
			else aux = 3*aux + 1;                 // Transformation if it is odd
			counter++;        // New transformation happend - counter incremented
			if (aux < 1E6 && seqSize[aux-1] > 0){ // If it transformed into an already
                                                  // calculated number
				seqSize[i-1] = seqSize[aux-1] + counter; // Length will be counter +
				if (seqSize[i-1] > max){                 // Length of new number 
					 max = seqSize[i-1]; // Updating the maximum length
					 max_number = i;     // Storing the number with the max length
				}
				break; // Break the loop and go to the next number
			}
		} 
	}
	return max_number;
}

int main(void)
{
	int *seqSize = (int*) calloc(1E6, sizeof(int));
	
	clock_t start, end;	
	long unsigned int solve, value = 1E6;
	
	start = clock();
	solve = solution(value, seqSize);
	end   = clock();

	double time = (double) (end - start)/CLOCKS_PER_SEC;
	printf("Solution: %ld (in %lf s)\n", solve, time);

	return 0;
}
