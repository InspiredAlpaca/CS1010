#include <stdio.h>

// CS1010 AY2015/6 Semester 1
// PE1 Ex1: election.c
// Name:
// Matriculation number:
// plab-id:
// Discussion group:
// Description:

#include <stdio.h>
double sub_sample(double,double,double,double);
void print_summary(double,double);

int main(void) {
    float sampleCountA=0.0, sampleCountB=0.0, sampleA = 0.0;
    int i,votersD,stations,votersStation,teamA,teamB;
    
    // Use the following printf statements to print the appropriate messages.
    printf("Enter number of voters in the division: ");
    scanf("%d",&votersD);
    printf("Enter number of stations: ");
    scanf("%d",&stations);
    
    for(i = 1; i <=stations;i++){
        printf("Enter number of voters in station %d: ",i); // Incomplete
        scanf("%d",&votersStation);
        printf("Enter number of votes for Team A: ");
        scanf("%d",&teamA);
        printf("Enter number of votes for Team B: ");
        scanf("%d",&teamB);
        sampleA = sampleA + sub_sample(votersD,votersStation,teamA,teamB);
        sampleCountB = sampleCountB + sub_sample(votersD,votersStation,teamB,teamA);
        //	printf("SampleA is: %lf",sampleA);
    }
    
    sampleCountA = sampleA;
    printf("Sample count for Team A = %.2f%%\n",sampleCountA*100);
    printf("Sample count for Team B = %.2f%%\n",sampleCountB*100);
    // printf("Sample count A: %f, Sample count B: %f",sampleCountA,sampleCountB);
    //printf("Sample C: %f",sampleCountB-sampleCountA);
    print_summary(sampleCountA, sampleCountB);
    return 0;
}

double sub_sample(double votersD, double votersStation, double teamA, double teamB){
    double sample;
    
    sample = (teamA/(teamA+teamB)) * (votersStation/votersD);
    return sample;
}

void print_summary(double A, double B){
    //double C;
    //C = B-A;
    //printf("value of B mins A equals: %lf", C);
    if(A == B){
        printf("There is no winner in this election.\n");
    }
    else if(A - B < 0.05 && A-B > 0){
        printf("Team A narrowly wins this election.\n");
    }
    else if(A-B > 0.3){
        printf("Team A wins by a landslide.\n");
    }
    else if(A-B <= 0.3 && A-B >= 0.05){
        printf("Team A wins by a significant margin.\n");
    }
    else if(B-A <= 0.3 && B-A >= 0.050){
        printf("Team B wins by a significant margin.\n");
    }
    else if(B-A < 0.05){
        printf("Team B narrowly wins this election.\n");
    }
    else if(B-A > 0.3){
        printf("Team B wins by a landslide.\n");
    }
    
}
// Remove extra comments (including this one) after you have completed the program