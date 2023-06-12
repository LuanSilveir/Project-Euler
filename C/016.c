#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Double(int* array)
{
	int carry = 0, result;
	for (int i = 0; i < 1001; i++){
		result = 2 * array[i] + carry;
		array[i] = result % 10;
		carry = result / 10;  
	}
}

void printer(int *array)
{
	int i = 1000;
	while (array[i] == 0) i--;
	while (i >= 0){
		 printf("%d",array[i]);
		 i--;
	}
	printf("\n");
}

int solution()
{
	int sum = 0;
	int *array = (int*) calloc(1001, sizeof(int));
	array[0] = 1;
	for (int i = 0; i < 1000; i++) Double(array);
	for (int i = 0; i < 1001; i++){
		sum += array[i];
	}
	return sum;
}

int main(void)
{
	printf("%d\n",solution());
	return 0;
}
