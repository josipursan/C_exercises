#include <stdio.h>

int main(){
    int x=33;
    int* y = &x;
    printf("x : %d\tx address : %p\ny : %p\ty address : %p\ty deref to real value : %d\n", x, (void*)&x, (void*)y, (void*)&y, *y);

    return 0;
}