#include <stdio.h>

int main(){
    int x = 4;

    x < 0 ? printf("x is negative\n") : printf("x is 0 or greater than 0\n");

    /*
        How does ternary operator work?
            It evaluates the truthfulness of the condition to its left. If it is true, command to the left of the colon is executed; otherwise, command
                to the right of colon is executed
    */
    return 0;
}