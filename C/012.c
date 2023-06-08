#include <stdio.h>

int divisors(int x)
{
	int n = 1;
	for (int i = 1; i <= x/2; i++){
		if (x % i == 0) n++;
	}
	return n;
}

int solution(int number)
{
	int div = 0, i = 0, tn = 0;
	while (div < number){
		i++;
		tn += i;
		div = divisors(tn);
	}	
	return tn;
}

int main(void)
{
	printf("%d\n",solution(500));
	return 0;
}
