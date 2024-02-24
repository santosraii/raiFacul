#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9
#define UNASSIGNED 0


int UsedInRow(int grid[][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int UsedInCol(int grid[][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return 1;
    return 0;
}

int UsedInBox(int grid[][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return 1;
    return 0;
}

int isSafe(int grid[][N], int row, int col, int num)
{
    return !UsedInRow(row, num) && !UsedInCol(col, num) && !UsedInBox(row - row % 3, col - col % 3, num);
}

int FindUnassignedLocation(int grid[][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == 0)
                return 1;
    return 0;
}

int SolveSudoku(int grid[][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, &row, &col))
        return 1;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

void printGrid(int grid[][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}

int main()
{
   
    }

    printGrid();
    return 0;
}
