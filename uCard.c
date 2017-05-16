#include <stdio.h>
// CS1010 AY2012/3 Semester 1
// PE1 Ex2: ucard.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

int algo(int);
int valid(int);
void issued(int);

int main(void) {
	int uCardNo, checkNumber;

	printf("Enter uCard Number: ");
    scanf("%d",&uCardNo);
    checkNumber = algo(uCardNo);
    printf("The check number is %d\n",checkNumber);
    if(valid(checkNumber) == 0)
        printf("Invalid\n");
    else{
        printf("Valid\n");
        issued(uCardNo);
    }
    
    
	return 0;
}

int algo(int num){
    int sum1,sum2,sum,num1,num2,secondMod;
    num1 = num2 = num;
    sum1 = sum2 = 0;
    while(num1 > 0){
        sum1 = sum1 + num1 % 10;
        num1 = num1/100;
    }
    while(num2 > 0){
        num2 = num2/10;
        secondMod = (num2%10)*2;
        while(secondMod >0){
            sum2 = sum2 + secondMod % 10;
            secondMod = secondMod/10;
        }
        num2 = num2/10; //divide it after modulus 
    }
sum = sum1 + sum2;
return sum; 
}

int valid(int sum){

    if((sum % 7) == 0)
        return 1;
    else 
        return 0;
}

void issued(int cardNo){
     while(cardNo > 100){
    cardNo = cardNo/10;
    }
    if(cardNo <=35 && cardNo >= 31)
        printf("Issued by East branch\n");
    else if(cardNo <= 55 && cardNo >= 51)
        printf("Issued by West branch\n");
    else
        printf("Issued by Central branch\n");
  
}