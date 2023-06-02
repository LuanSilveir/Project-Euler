#include <stdio.h>
#include <stdlib.h>

int firstfactor(int x)   // O(n)
{
	for (int i = 2; i < x/2; i++){
		if (x % i == 0) return i;
	}
	return x;
}

void update(int n, int* array){ // (O(nlog(n))
	int f;
	while (n != 1){         // O(nlog(n))
		f = firstfactor(n); // O(n)
		array[f-1] += 1;
		n = n/f;
	}
}

int *factors(int x){ // O(n²log(n))
	
	int *array = (int *)calloc(x, sizeof(int));
	
	for (int i = 0; i < x; i++){
		int *temp = (int *)calloc(x, sizeof(int));
		update(i+1, temp); // O(nlog(n))
		for (int j = 0; j < x; j++){ // O(n)
			if (temp[j] > array[j]) array[j] = temp[j];
		}
		free(temp);
	} 
	return array;
}

int power(int a, int b){

	if (b == 0) return 1;
	else return a * power(a, b-1);
}

int solution(int x){     // O(n²log(n))
	int *f = factors(x); 
	int result = 1;
	for (int i = 0; i < x; i++){
		result = result * power(i+1,f[i]);
	}
	return result;
}


int main(void){

	int solve = solution(20);

	printf("%d\n",solve);
	
	return 0;
}
