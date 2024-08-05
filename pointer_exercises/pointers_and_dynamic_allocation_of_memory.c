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
            printf("rowptr[%d] malloc failed\n", row);
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
    We will allocate a block of memory to hold the whole array first. Then we create an array of pointers to point to each row.
    Even though an array of pointers is still being used, the actual array is contiguous in memory.

    aptr is array that takes up memory for all necessary elements (5*8 = 40 in our example here).
    
    rptr is a pointer to pointer, so pointer that is looking at an array.
    How do we point each rptr to different "rows" in aptr?
    Each row in aptr is separated by a certain number of elements forming that row. Which elements form up a row? Columns!
    So, each row is separated by COLS elements.
    In order to jump from one row to the next one in aptr, we need to move in aptr by COLS*row, row being the row we want to enter.
    That is why we point the rptr like this : rptr[k] = aptr + (k*cols); k being iterator going over all possible rows.

    There is also a graph/schematic for this you should check out.
 */

 /*int main()
 {
    int **rptr;
    int *aptr;
    int *testptr;
    int k;
    int nrows = 5;  // Although nrows and ncols are fixed here, imagine they are being evaluated at run time
    int ncols = 8;
    int row, col;

    //Let us now allocate memory for the array
    aptr = malloc(nrows * ncols * sizeof(int));
    if(aptr == NULL)
    {
        printf("aptr malloc issue\n");
        exit(0);
    }

    ///Now we will allocate room for the pointers to the rows
    rptr = malloc(nrows * sizeof(int*));
    if(rptr == NULL)
    {
        printf("rptr malloc issue\n");
        exit(0);
    }

    //Now we will point the pointers to the rows
    for(k = 0; k < nrows; k++)
    {
        rptr[k] = aptr + (k*ncols);
    }

    //Now we illustrate how the row pointers are incremented
    printf("\n\nIllustrating how row pointers are incremented");
    printf("\n\nIndex   Pointer(hex)  Diff.(dec)");

    for (row = 0; row < nrows; row++)
    {
        printf("\n%d         %p", row, rptr[row]);
        if (row > 0)
        printf("              %d",(rptr[row] - rptr[row-1]));
    }
    printf("\n\nAnd now we print out the array\n");

    for(row = 0; row < nrows; row++)
    {
        for(col = 0; col < ncols; col++)
        {
            rptr[row][col] = row*col;
        }
    }

    for(row = 0; row < nrows; row++)
    {
        for(col = 0; col < ncols; col++)
        {
            printf("rptr[%d][%d] : %d\n", row, col, rptr[row][col]);
        }
    }

    //Now we will demonstrate that this is actually a contiguous block of memory
    testptr = aptr;
    for(row = 0; row<nrows; row++)
    {
        for(col = 0; col < ncols; col++)
        {
            printf("row : %d col : %d val : %d\n", row, col, *(testptr++));
        }
        putchar('\n');
    }

    return 0;
 }*/

