// CS1010 AY2014/5 Semester 1
// PE1 Ex1: parking.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
#include <stdio.h>
#include <math.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

double computeFee(int,int,int);

int main(void){
	int day, timeIn, timeOut;
	int *p_timeIn, *p_timeOut;
    double fee =1;

	printf("Enter day: ");
    scanf("%d", &day);
	printf("Enter time-in: ");
    scanf("%d", &timeIn);
	printf("Enter time-out: ");
    scanf("%d", &timeOut);
    computeTime(&timeIn,&timeOut);
    //printf("Time In: %d, Time Out: %d\n", timeIn,timeOut);
    fee = computeFee(day,timeIn,timeOut);
	printf("Parking fee is $%.2f.\n", fee);

	return 0;
}

void computeTime( int *timeIn, int *timeOut){
    *timeIn = ((*timeIn/100)*60) + (*timeIn % 100);
    *timeOut = ((*timeOut/100)*60) + (*timeOut % 100);
}
double computeFee(int day, int timeIn, int timeOut){
    double fee, fee1,fee2,fee3;

    switch(day){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            //printf("Monday - Friday\n");
            if(timeOut - timeIn <= 10)
                return 0;
            if(timeIn >= 240 && timeIn < 420){  //check if timeIn is within first period
                   fee1 = ceil((MIN(420,timeOut) - (double)timeIn)/60) * 2; 
                    //printf("feeOutofFirst = %f\n",fee1);
            }
            fee2 = ceil((MIN(1080,timeOut) - MAX(420,(double)timeIn))/30) * 1.20;
            //printf("feeOutofSecond = %f\n",fee2);
            
            if(timeOut > 1080)
                fee3 = 5;
            //printf("feeOutofThird = %f\n",fee3);
            fee = fee1 + fee2 + fee3;
            if(ceil(timeOut - timeIn)/60 > 10)
                fee = fee * 1.1;
            if(timeOut > 1320)
                fee = fee + 3;
            return fee;
            
        case 6:
             //printf("Saturday\n");
            if(timeOut - timeIn <= 10)
                return 0;
            if(timeIn >= 240 && timeIn < 420){  //check if timeIn is within first period
                   fee1 = ceil((MIN(420,timeOut) - (double)timeIn)/60) * 2.50; 
                    //printf("feeOutofFirst = %f\n",fee1);
            }
            fee2 = ceil((MIN(1080,timeOut) - MAX(420,(double)timeIn))/30) * 1.50;
           //printf("feeOutofSecond = %f\n",fee2);
            
            if(timeOut > 1080)
                fee3 = 7;
            //printf("feeOutofThird = %f\n",fee3);
            fee = fee1 + fee2 + fee3;
                if(ceil(timeOut - timeIn)/60 > 10)
                fee = fee * 1.2;
                if(timeOut > 1320)
                fee = fee + 3;
            return fee;
        case 7:
             //printf("Sunday\n");
              if(timeOut - timeIn <= 10)
                return 0;
                fee = 5;
                if(timeOut > 1320)
                fee = fee + 3;
            return fee;
    }

}