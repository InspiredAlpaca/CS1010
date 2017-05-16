/*
 * CS1010 AY2016/7 Semester 1 Lab2 Ex1
 * candles.c
 * <Calculate the total number of candles that can be burned>
 * <Wong Kai Min Herman>
 * <T13>
 */

#include <stdio.h>

int count_candles(int ,int);

int main(void) {
    int candles,residuals;

    printf("Enter number of candles and \n");
    printf("number of residuals to make a new candle: ");
    scanf("%d", &candles);
    scanf("%d", &residuals);
    
    printf("Total candles burnt = %d\n", count_candles(candles,residuals));

    return 0;
}
//This functions takes in the num of candles and residual and calculate the number of extra candles that can be made and add into initial num of candles.
//Pre condition: Inputs are positive.
int count_candles(int c,int r){
    int counter, candle;
    candle = c; //Initial number of candles
    while(c >= r){
        c -= r; //Minus away required residual
        c ++;   //Make additional new candle
        counter ++;
    }
    candle = candle + counter;

    return candle;
}
