#include <stdio.h>

int main()
{
    int my_array[] = {1, 23, 17, 5, -5, 100};

    int *ptr;
    ptr = &my_array[0];

    printf("\n\n");

    for(int i = 0; i<6; ++i)
    {
        printf("my_array[%d] : %d\ti : %d\n", i, my_array[i], i);
        //printf("*ptr + %d : %d\n", i, *(ptr+i));
        //printf("*ptr++ : %d\n", *ptr++);    // Does the same as above - prints elements from my_array in expected order
        //printf("*(++ptr): %d\n", *(++ptr)); // This accessing method actually moves step ahead, ie. when my_array[i] is printing element 0 (my_array[0] = 0), this line will print 23 (ie. my_array[1]), meaning that this accessing method first moves the address, and then dereferences it
        printf("*++ptr : %d\n", *++ptr);    // Actually the same case as above
        printf("\n\n");      
    }

    return 0;


    int my_array_2[] = {1, 2, 3, 4, 5};
    int *ptr2;
    ptr = &my_array_2[0];   /* These two achieve the same result - ptr points to the first element of my_array_2*/
    ptr = my_array_2;

    
}

/*
    https://github.com/jflaherty/ptrtut13/blob/master/md/ch2x.md 
*/