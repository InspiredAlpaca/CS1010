/* hourglass.c
 * This program reads the durations of 2 hourglasses and a duration to measure,
 * to find the number of times to flip the hourglasses so that the total
 * number of flips is minimum.
 */

#include <stdio.h>
#include <math.h>
// Given function prototype must not be changed
int compute_flips(int, int, int, int *, int *);

int main (void) {
	int hg1, hg2;        // durations of hourglasses; assume hg1 < hg2
	int time;            // duration to measure; assume hg2 < time
	int flips1, flips2;  // number of flips needed for hourglasses

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &hg2, &hg1, &time);
    if(compute_flips(hg1,hg2,time,&flips1,&flips2))
        printf("Possible!\n%d flip(s) for %d-minute hourglass and %d flip(s) for %d-minute hourglass.\n",flips2,hg2,flips1,hg1);
    else
        printf("Impossible!\n");

	return 0;
}

int compute_flips(int hg1, int hg2, int time, int *flips1, int*flips2){
    double timeLeft;    
    int currenttime;
    *flips1 = time/hg1;
    timeLeft = time -(hg1*(*flips1));
    if(timeLeft == 0)
        return 1;
        //printf("Timeleft is %d\n",timeLeft);
    *flips2 = ceil(timeLeft/hg2);
            //printf("flip2 is %d\n",*flips2);
        if(timeLeft - *flips2 * hg2 == 0)
        return 1;
        //printf("Flips1 %d, hg1 %d, flips2 %d, hg2 %d.\n",*flips1,hg1,*flips2,hg2);
    currenttime = (*flips1 * hg1) + (*flips2* hg2); 
          //  printf("Currenttime: %d\n",currenttime);
    while(currenttime > time){

            (*flips1)--;
            //printf("Flips1 %d, hg1 %d, flips2 %d, hg2 %d.\n",*flips1,hg1,*flips2,hg2);

            currenttime = (*flips1 * hg1) + (*flips2* hg2); 
            while(currenttime < time){
                (*flips2)++;
                currenttime = (*flips1 * hg1) + (*flips2* hg2);
            }
            if(*flips1 <= 0 && currenttime > time)
            return 0;
        }
return 1;
}