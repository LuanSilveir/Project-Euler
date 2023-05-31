#include <stdio.h>
#include <string.h>

/* Solution 1  */
int palindrome(int x)
{
	char str[20];
	sprintf(str, "%d", x);
	
	int last = strlen(str) - 1;
	
	for (int first = 0; last - first > 0; first++, last--)
	{	
		if (str[first] != str[last]) return 0;
	}
	return 1;
}

int solution1()
{	
	int max = 0, number;
	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j <= i; j++)
		{
			number = i*j;
			if (number > max && palindrome(number)) max = number;
		}
	}
	return max;
}

int main(void)
{
	int result = solution1();
	printf("%d\n", result);
	
	return 0;
}
