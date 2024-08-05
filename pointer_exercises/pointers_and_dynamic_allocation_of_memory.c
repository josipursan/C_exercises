#include <stdio.h>
#include <stdlib.h>

// Here we will showacase various methods of dynamically allocating room for 2D arrays


/*
// METHOD 1
#define COLS 5
typedef int RowArray[COLS];
RowArray *rptr;

int main()
{
    int nrows = 10;
    int row, col;
    rptr = (RowArray*)malloc(nrows * COLS * sizeof(int));
    for(row = 0; row < nrows; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            rptr[row][col] = 17;
        }
    }
    return 0;
} */


// ------------------------------------------------------------------------------------

// METHOD 2
/* 
    In METHOD 1 rptr is actually a pointer to 1D array of COLS integers.
    Instead of using typedef, we can use : int (*xptr)[COLS]
    xptr is pointer to an array of integers, and the size of that array is given by the #define COLS (or by some manual input, computation, etc.)
    If we had written int *xptr[COLS], we would've gotten an array of pointers holding the number of pointers equal to COLS.
*/

// ------------------------------------------------------------------------------------



// METHOD 3

    /*Scenario in which we don't know the needed number of rows or cols at runtime - this is the main scenario.
    How will we solve this?
    We will create an array of pointers to type int.
    Then we will allocate space for each row (ie. pointer), and point our pointers to these rows.

    This method does not mean that our 2D array is contiguous in memory. Why?
    Because we create this 2D array by having an array of pointers, each of which is pointing to an array of some dimension (10 in our case).
    Each of these pointers is pointed to a chunk of memory. Each of these chunks of memory is malloced independently of one another.
    Therefore these contiguous memory chunks for 10 ints can be scattered around the memory.
    Still, the conventional array notation can be used (arr[][]) */
/*
int main()
{
    int nrows = 5;
    int ncols = 10; // Imagine here that number of rows and cols is evaluated at run time.

    int row, cols;
    int **rowptr;

    rowptr = (int*)malloc(nrows*sizeof(int*));  // Allocated memory for array of pointers - 5 in this case
    if(rowptr == NULL)
    {
        printf("rowptr malloc failed\n");
        exit(0);
    }

    printf("\n\n\nIndex   Pointer(hex)   Pointer(dec)   Diff.(dec)");

    for(row=0; row<nrows; row++)
    {
        rowptr[row] = (int*)malloc(ncols * sizeof(int));
        if(rowptr[row] == NULL)
        {
            printf("rowptr[%d] malloca failed\n", row);
            exit(0);
        }
        printf("\n%d         %p         %d", row, rowptr[row], rowptr[row]);
        if (row > 0)    
            printf("              %d",(int)(rowptr[row] - rowptr[row-1]));
    }

    for(row = 0; row<nrows; row++)
    {
        for(cols = 0; cols<ncols; cols++)
        {
            rowptr[row][cols] = row*cols;
        }
    }

    for(row = 0; row<nrows; row++)
    {
        for(cols = 0; cols<ncols; cols++)
        {
            printf("row, cols : %d %d\tVal : %d\n", row, cols, rowptr[row][cols] = row*cols);
        }
    }
    return 0;
} */


// ----------------------------------------------------------------------------------------


// METHOD 4
/*
    This method will make the 2D array take up a contiguous block of memory, unlike METHOD 3.
    
 */

