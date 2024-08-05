#include <stdio.h>

int main()
{
    int my_array[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr;
    ptr = &my_array[0]; // This is from chapter 2 - pointing our pointer at the first integer in our array

    // We can use a pointer as a formal parameter of a function which is designed to manipulate an array : 
    int array[3] = {'1', '5', '7'};
    void a_func(int *p);
    // Or
    void a_func (int p[]);
    // Note the two different function prototypes of the same function.
    // In either case, pointer to the first element of the array is actually what gets passed to the function - note that using array notation does NOT require you to pass the dimension of the array



    // Let us now turn to the problem of 2 dim arrays
    /*
        C interprets 2D array as an array of 1D arrays.
        The first element of a 2D array of integers is a 1D array of integers.
        Pointer to a 2D array of integers must be a pointer to that data type.
        One way of accomplishing this is through the use of typedef keyword.
    */

    typedef int Array[10]; // "Array" is typedefed to become an array of integers with memory space for 10 elements
    Array my_arr; // my_arr is array of 10 integers
    Array arr2d[5] // arr2d is an array of 5 arrays, each with 10 integers
    Array *p1d; // p1d is a pointer to an array of 10 integers

    p1d = &arr2d[0];
    p1d = arr2d;
    /*
        Both methods of pointing the pointer to a 2D array shown above are valid
    */

    /*
        Because we've used typedef, and because we've typedef-ed Array as an array of 10 integers, incrementing our p1d pointer by 1 will actually move us by 1 based on our typedef, ie.
        we will jump by 10 integers at once because by typedefing we've created a new data type, for which 10 integers in an array constitute one jump in memory.
    */

    /*
        However, even though author of this pointer tutoraial/guide argues that usage of typedef has made things clearer and easier to understand for programmer, I would strongly disagree.
        Furthermore, author states that doing what he did with typedef is not really necessary.

        What we need is this : 
    */
    int (*p1d)[10]; // This is a pointer to an array of 10 integers.

    int *p1d[10] // WARNING : note that this declaration, and the one above are very different - here p1d is the name of an array of 10 pointers to type int (so literally array with memory to hold 10 pointers, all pointing to int data type)
    
    return 0;
}