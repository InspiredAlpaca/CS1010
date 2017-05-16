#include <stdio.h>

int computeDays(int, int);

int main(void) {    
	int day, month;

	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);
	printf("Day %d of month %d is the %dth day of 2016.\n",  day, month, computeDays(day, month));

	return 0;
}

int computeDays(int day, int mth) {
    int i, days = day, days2[] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for(i = 0; i < mth -1;i++){
            days = days2[i] + days;
        }
	return days;
}
