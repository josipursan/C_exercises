#include <stdio.h>
#include <stdlib.h>

int main()
{
    int depth = 3;
    int rows = 3;
    int cols = 3;

    int i,j,k;

    int ***my_3d_array;

    my_3d_array = malloc(depth * sizeof(int **));    // Allocate the wanted depth of 3D array, ie. how many layers of matrices (2D arrays) we want

    for(i = 0; i < depth; i++)
    {
        my_3d_array[i] = malloc(rows*sizeof(int *));   // For each layer malloc enough pointer to point to 2D arrays
    }

    for(i = 0; i<depth; i++)
    {
        for(j = 0; j<rows; j++)
        {
            my_3d_array[i][j] = malloc(cols*sizeof(int));   // In each row of each 2D array allocate enough memory to accomodate all members
        }
    }

    // Loop to populate array with members
    for(i = 0; i<depth; i++)
    {
        for(j = 0; j<rows; j++)
        {
            for(k = 0; k<cols; k++)
            {
                my_3d_array[i][j][k] = i*j*k;
            }
        }
    }

    // Print loop to check if members are ok
    for(i = 0; i<depth; i++)
    {
        for(j = 0; j<rows; j++)
        {
            for(k = 0; k<cols; k++)
            {
                printf("i = %d\nj = %d\nk = %d\nval : %d\nadd : %p\n\n", i, j, k, my_3d_array[i][j][k], (void*)&my_3d_array[i][j][k]);
            }
        }
    }

    // Print loop to show continuity of addresses and continuity of memory chunk sizing for depth, rows, and cols
    for(i = 0; i<depth; i++)
    {
        for(j = 0; j<rows; j++)
        {
            for(k = 0; k<cols; k++)
            {
                printf("i : %d\tDepth address : %p\nj : %d\tRows address : %p\nk : %d\tCols address : %p\n\n", i, (void*)&my_3d_array[i], j, (void*)&my_3d_array[i][j], k, (void*)&my_3d_array[i][j][k]);;
            }
        }
    }

    return 0;
}