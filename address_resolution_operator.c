#include <stdio.h>

int main(){
    int x=5;
    printf("x = %d\tAddress of x : %p\n", x, (void*)&x);

    return 0;
}