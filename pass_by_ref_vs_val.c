#include <stdio.h>

void add(int* x)
{
    *x += 1;
}

void add_2(int x)
{
    x += 1;
    printf("\n\nadd_2 x after addition : %d\n", x);
}

int main()
{
    int x = 5;
    printf("x before any actions : %d\t x addr : %p\n", x, (void*)&x);
    add(&x);
    printf("x after add : %d\t x addr : %p\n", x, (void*)&x);

    int y = 10;
    int* pootr = &y;
    printf("y : %d\t y addr : %p\n", y, (void*)&y);
    printf("pootr : %p\t *pootr : %d\n", (void*)pootr, *pootr);

    add(pootr);
    printf("\ny after passing pootr to add : %d\t y addr : %p\n", y, (void*)&y);
    printf("pootr after passing pootr to add : %p\t *pootr : %d\n", (void*)pootr, *pootr);

    add(&y);
    printf("\ny after passing y to add : %d\t y addr : %p\n", y, (void*)&y);
    printf("pootr after passing y to add : %p\t *pootr : %d\n", (void*)pootr, *pootr);

    int z = 5;
    printf("z before any actions : %d\t z addr : %p", z, (void*)&z);
    add_2(z);
    printf("z after add_2 : %d\t z addr : %p", z, (void*)&z);
    
    return 0;
}


/*
    Pass by reference - the caller and the callee use the same variable (the same chunk of memory)
        -e.g. some variable x is passed by reference from main to function XYZ. Whatever happens in XYZ, will also be visible in main, because function XYZ and main operate on the same chunk of memory.

    Pass by value - defaul state of C
        -variable passed to some function isn't actually passed; its value is simply copied, and another variable is made for the function.
        -the variables are independent;

*/