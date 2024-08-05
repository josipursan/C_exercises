#include <stdio.h>

int main(){

    int x[5] = {1,2,3,4,5};
    int* x_ptr = &x[0];
    printf("Value of x_ptr = %p\tDeref : %d\n", (void*)x_ptr, *x_ptr);
    printf("Value of x_ptr+1 = %p\tDeref : %d\n", (void*)(x_ptr+1), *(x_ptr+1));

    char y[5] = {'a', 'b', 'c', 'd', 'e'};
    char* y_ptr = &y[0];
    printf("Value of y_ptr : %p\tDeref : %d\n", (void*)y_ptr, *y_ptr);
    printf("Value of y_ptr+1 : %p\tDeref : %d\n", (void*)(y_ptr+1), *(y_ptr+1));

    return 0;
}