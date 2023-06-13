#include <stdio.h>

int solution(int *units, int *tens, int *hunds, int *special)
{
	int sum = 0, n;
	for (int i = 0; i < 10; i++) sum += units[i];
	n = sum;
	for (int i = 1; i < 10; i++){
		if (i != 1) sum += 10 * tens[i] + n;
		else for (int j = 0; j < 10; j++) sum += special[j];
	}
	n = sum;
	for (int i = 1; i < 10; i++) sum += 100 * hunds[i] + n - 3;
	sum += 11;
	return sum;
}


int main(void)
{
	int units[10] = {0,3,3,5,4,4,3,5,5,4};
	int tens[10]  = {0,-1,6,6,5,5,5,7,6,6};
	int hunds[10] = {0,13,13,15,14,14,13,15,15,14};
	int special[10] = {3,6,6,8,8,7,7,9,8,8};
	
	printf("%d\n",solution(units,tens,hunds,special));
	
	return 0;
}
