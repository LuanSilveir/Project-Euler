#include <stdio.h>
#include <time.h>

/* Solution 1 */
int solution1(void)
{
	int new = 1, last = 1, aux, result = 0;
	while (new < 4E6)
	{
		aux = new;
		new = new + last;
		last = aux;
		
		if (new % 2 == 0) result += new;
	} 

	return result; 
}

/* Solution 2 
Idea: Even numbers occur in intervals of 2 in the fibonacci sequence  */
int solution2(void)
{
	int new = 2, last = 1, aux, result = 0;
	while (new < 4E6)
	{	
		result += new;
	
		aux = new;
		new = new + last;
		last = aux;

		aux = new;
		new = new + last;
		last = aux;

		aux = new;
		new = new + last;
		last = aux;
	}
	return result;  
}


int main(void)
{	
	clock_t start1, start2, end1, end2;
	double time1, time2;
	
	start1 = clock();
	int result1 = solution1();
	end1 =  clock();

	start2 = clock();	
	int result2 = solution2();
	end2 = clock();
	
	time1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
	time2 = (double) (end2 - start2) / CLOCKS_PER_SEC;
	
	printf("Result 1: %d (%lf s)\n", result1, time1);
	printf("Result 2: %d (%lf s)\n", result2, time2);

	return 0;
}
