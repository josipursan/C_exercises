#include <stdio.h>

int double_number_a(int x){     // Pass by value
    return 2*x;
}

int double_number_b(int* x){        // Pass by reference, ie. change the original value
    *x *= 2;
}

int main(){
    int num = 5;

    printf("Before any call : %d\n", num);
    printf("double_number_a : %d\tnum : %d\n", double_number_a(num), num);

    double_number_b(&num);
    printf("num after double_number_b : %d\n", num);

    return 0;
}