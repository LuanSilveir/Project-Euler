#include <stdio.h>

int solution()
{
	int length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char names[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","dec"};
	char wnames[7][4] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	int count = 0, week_day = 2, last = 0;
	for (int year = 1901; year <= 2000; year++){
		last = count;
		if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) length[1] = 29;
		else length[1] = 28;
		for (int month = 0; month < 12; month++){
			if (week_day == 0)	count++;
			for (int day = 0; day < length[month]; day++){
				week_day = (week_day + 1) % 7;
			}
		}
	//printf("Year: %d Count: %d\n", year, count - last);
	}
	return count;
}


int main(void)
{

	printf("%d\n",solution());
	return 0;
}
