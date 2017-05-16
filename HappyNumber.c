#include <stdio.h>
 #include <math.h>

 int computeHappyNumbers(int,int);
 int computeFinalForm(int);
 
 int main(void){
     int lower1, upper1, lower2, upper2, number1, number2;
 
     printf("Enter first range: ");
     scanf("%d %d",&lower1,&upper1);
   printf("Enter second range: ");
     scanf("%d %d",&lower2, &upper2);
     number1 = computeHappyNumbers(lower1,upper1);
    number2 = computeHappyNumbers(lower2,upper2);
     printf("The numbers of happy numbers in the two ranges are: %d %d\n", number1, number2);
     if(number1 > number2)
    printf("There are more happy numbers in the first range.\n");
     else if(number1 < number2)
     printf("There are more happy numbers in the second range.\n");
     else
    printf("The numbers of happy numbers in both ranges are the same.\n");
 
     return 0;
  }
 
  int computeHappyNumbers(int lower, int upper){
        int i,num, counter = 0,squaredSum;

      for(i = lower; i <= upper; i++){

        squaredSum = i;

         while(squaredSum != 0 && squaredSum != 1 && squaredSum != 4 && squaredSum != 16 && squaredSum != 20 && squaredSum != 37 && squaredSum != 42 && squaredSum != 58 && squaredSum != 89 && squaredSum != 145 ){

             squaredSum = computeFinalForm(squaredSum);
   
         }
     if(squaredSum == 1)
         counter++;
     }
     return counter;
  }
 
 int computeFinalForm(int num){
     int squaredSum = 0;
     while (num >0){
         
        squaredSum = squaredSum + pow(num%10,2);
        
        num = num/10;
     }
     
 return squaredSum;
      }
  