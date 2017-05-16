#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 100
void findEndState(int[][MAX_COL], int, int, int, int*);

int main()
{
    int row, col, level, i, j;
    int land[MAX_ROW][MAX_COL];
    int counter;
    printf("Enter dimensions of the land: ");
    scanf("%d %d", &row, &col);

    printf("Enter elevations: \n");

    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &land[i][j]);

    printf("Enter flood level: ");
    scanf("%d", &level);
    findEndState(land, row, col, level, &counter);
    printf("Number of robots to be rescued: %d\n", counter); // Incomplete

    return 0;
}

void findEndState(int arr[MAX_ROW][MAX_COL], int row, int col, int level, int* counter)
{
    int i, j, flag = 1, max, mrow, mcol, temp[MAX_ROW][MAX_COL];
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            temp[i][j] = 1;
        }
    }
    while(flag == 1) {
        flag = 0;

        for(i = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                if(temp[i][j] == 0) {
                    continue;
                }

                max = arr[i][j];
                mrow = i;
                mcol = j;
                if(i - 1 >= 0) {
                    if(arr[i - 1][j] > max) {
                        max = arr[i - 1][j];
                        mrow = i - 1;
                        mcol = j;
                    }
                }
                if(i + 1 < row) {
                    if(arr[i + 1][j] > max) {
                        max = arr[i + 1][j];
                        mrow = i + 1;
                        mcol = j;
                    }
                }
                if(j - 1 >= 0) {
                    if(arr[i][j - 1] > max) {
                        max = arr[i][j - 1];
                        mrow = i;
                        mcol = j - 1;
                    }
                }
                if(j + 1 < col) {
                    if(arr[i][j + 1] > max) {
                        max = arr[i][j + 1];
                        mrow = i;
                        mcol = j + 1;
                    }
                }
                if(mrow == i && mcol == j)
                    continue;
                temp[mrow][mcol] += temp[i][j];
                temp[i][j] -= temp[i][j];
                flag = 1;
                break;
            }
            if(flag == 1)
                break;
        }
    }
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(arr[i][j] < level) {
                *counter += temp[i][j];
            }
        }
    }
}