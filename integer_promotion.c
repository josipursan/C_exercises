#include <stdio.h>

int main(){
    char x='A';
    if(x < 'a'){
        printf("Less than\n");
    }
    else{
        printf("Greater than\n");
    }

    /*
        Any operand whose rank is lower than int is temporarily promoted to int or unsigned int for the comparison
        In the given example, x is promoted to int so that the comparison to the integer value of 'a' can be executed.

        char size - 1 byte
        int size - 4 bytes (or 2, depending on platform)

        This comparison will resolve to else.
        Why?
        Because 'A' and 'a' are compared as ints, and the int value of these chars can be found in ASCII table (https://www.asciitable.com/).
        Per the ASCII table, 'A' has decimal value 65, while 'a' has decimal value 97, hence 65 < 97 comparison holds true
    */
    return 0;
}