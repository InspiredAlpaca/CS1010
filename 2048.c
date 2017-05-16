// CS1010 AY2014/5 Semester 1
// PE2 Ex2: 2048.c
// Name:
// Matriculation number:
// plab-id:
// Discussion group:
// Description:

#include <stdio.h>
#define SIZE 4
#define LENGTH 21

void readGrid(int[][SIZE]);
void printGrid(int[][SIZE]);
void play(int[][SIZE], char[]);
int exist(int[][SIZE], int);
int main(void)
{
    int grid[SIZE][SIZE], target;
    char directions[LENGTH];

    printf("Enter grid:\n");
    readGrid(grid);

    printf("Enter directions: ");
    scanf("%s", directions);
    printf("Enter target: ");
    scanf("%d", &target);
    play(grid, directions);
    printGrid(grid);
    if (exist(grid, target))
    printf("%d is formed.\n", target);
    else
    printf("%d is not formed.\n", target);

    return 0;
}

int exist(int grid[][SIZE], int target)
{
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(grid[i][j] == target)
                return 1;
        }
    }
    return 0;
}
void moveup(int grid[][SIZE])
{
    int i, j, k;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(grid[i][j] == 0) {
                for(k = i + 1; k < SIZE; k++) {
                    if(grid[k][j] != 0) {
                        grid[i][j] = grid[k][j];
                        grid[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    for(i = 0; i < SIZE ; i++) {
        for(j = 0; j < SIZE; j++) { // no need check last row
            if(grid[i][j] == 0)
                continue;
            if(grid[i][j] == grid[i + 1][j]) {
                grid[i][j] *= 2;
                for(k = i + 1; k < SIZE - 1; k++) {
                    grid[k][j] = grid[k + 1][j];
                }
                grid[SIZE - 1][j] = 0;
            }
        }
    }
}

void moveleft(int grid[][SIZE])
{
    int i, j, k;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(grid[i][j] == 0) {
                for(k = j + 1; k < SIZE; k++) {
                    if(grid[i][k] != 0) {
                        grid[i][j] = grid[i][k];
                        grid[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) { // no need check last row
            if(grid[i][j] == 0)
                continue;
            if(grid[i][j] == grid[i][j + 1]) {
                grid[i][j] *= 2;
                for(k = j + 1; k < SIZE - 1; k++) {
                    grid[i][k] = grid[i][k + 1];
                }
                grid[i][SIZE - 1] = 0;
            }
        }
    }
}

void play(int grid[][SIZE], char directions[])
{
    int i = 0;
    while(directions[i] != '\0') {
        switch(directions[i]) {
        case 'U':
            moveup(grid);
            break;
        case 'L':
            moveleft(grid);
            break;
        }
        i++;
    }
}
// Read in the grid
void readGrid(int grid[][SIZE])
{
    int i, j;

    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            scanf("%d", &grid[i][j]);
}

// Print out the grid
void printGrid(int grid[][SIZE])
{
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}