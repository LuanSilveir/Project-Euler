#include <stdio.h>

int solution()
{
	int c;
	for (int a = 3; a < 1000; a++){
		for (int b = a + 1; a + b < 1000; b++){
			c = b + 1;
			while (a*a + b*b > c*c) c++;
			if (a*a + b*b == c*c && a + b + c == 1000){
				printf("a:%d b:%d c:%d\n",a,b,c);return a*b*c;}
		}
	}
	return 0;
}


int main(void)
{
	
	printf("%d\n",solution());

	return 0;
}
