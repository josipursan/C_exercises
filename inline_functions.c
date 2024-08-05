#include <stdio.h>

static inline void square(int* x){
    *x *= *x;
    return;
}

int main(){
    int num = 5;
    printf("Before square call : %d\n", num);
    square(&num);
    printf("num : %d\n", num);

    return 0;
}