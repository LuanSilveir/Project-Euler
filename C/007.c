#include <stdio.h>
#include <math.h>

int prime(int x){
	int limit = (int) sqrt(x) + 1;
	if (x % 2 == 0 && x != 2) return 0;
	for (int i = 3; i < limit; i += 2){
		if (x % i == 0) return 0;
	}
	return 1;
}

int solution(int x){

	int counter = 1, number = 3;
	while (counter < x){
		if (prime(number)) counter++;
		number += 2;
	}
	return number - 2;
}

int main(void){
	
	printf("%d\n",solution(10001));

	return 0;
}
