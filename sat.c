#include <stdio.h>
int compute_percentile(int,int,int);
double compute_iqscore(double,double);

int main(void) {
	int verbal, maths, writing ; // user’s input
	int score1,score2,score3,satPercent;
	double iqScore;
	printf("Enter scores: ");
	scanf("%d %d %d", &score1,&score2,&score3);
	satPercent = compute_percentile(score1,score2,score3);
	printf("The SAT score is in the %d percentile.\n",satPercent);	
	iqScore = compute_iqscore(score1,score2);
	printf("The IQ score is %.2lf\n",iqScore);
	if((score1 > 600 && score2 > 600 && score3 > 600) || iqScore >= 120)
		printf("Wow, this is amazing!\n");
return 0;
}

int compute_percentile(int score1,int score2, int score3){
int total, percentile;

total = score1+score2+score3;

if(total >= 2200)
	percentile = 99;
else if(total >=2000)
	percentile = 95;
else if(total >= 1500)
	percentile = 50;
else if (total <=1500)
	percentile = 10;

return percentile;
}

double compute_iqscore(double verbal,double math){
	double iq;
	iq = (0.095*math) +(0.003*verbal)+ 50.241;

return iq;
}
