/**
 * rabbit.c 
 * A rabbit can jump at most 50 centimetres. It needs to cross a
 * river, with rocks positioned in a straight line in the river.
 * The program computes the minimum number of jumps for the rabbit
 * to cross to the other side of the river.
 */

#include <stdio.h>

int countJumps(int [], int);

int main(void) {
	int num_rocks, rockDistance[20], x,i;            // including opposite bank

	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);
    for(i = 0; i < num_rocks; i++){
        scanf("%d",&rockDistance[i]);
    }
    x = countJumps(rockDistance,num_rocks);
    printf("%d\n",x);
	return 0;
}

// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
int countJumps(int rocks[], int size) {
    int i = 0, post = 0,currentPost, counter = 0;
    //printf("Function initalized\n");
    do{
    
        currentPost = post;//rabbit jumped
             //  if(currentPost == post)
        //    return -1;
        //printf("While Loop initalized\n");
        while(currentPost + 50 >= rocks[i]){
            if(i == (size))
                break;
            post = rocks[i];
            i ++;
           // printf(" i = %d and post = %d\n",i,post);
        }
            if(currentPost == post)
            return -1;
         counter++;
    }while(post < rocks[size -1]); //position is not at last rock

         
	return counter; // this is just a stub; replace it with the correct value
}
