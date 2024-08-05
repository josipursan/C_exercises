#include <stdio.h>

union my_data{
    int i;
    float f;
    char str[20];
};

int main(){
    union my_data un1;
    printf("Size of my_data union : %lu\n", sizeof(un1));
    return 0;
}

/*
    Union is a user-define data type in C.
    Unlike structures, all union members are stored in the same memory location.
    How? Because only one member at a time can store data at a given moment.
    The memory location big enough to be able to accomodate the biggest member of the union (in our case, it is str[20])
*/