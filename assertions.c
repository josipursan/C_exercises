#include <stdio.h>
#include <assert.h>

int main(){
    int x = 1;
    assert(x == 2); // This breaks the execution because 1 != 2.
    return 0;
}

/*
    Assertions are statements used to explicitly test assumptions made by the programmer.
    Checked at runtime, or if static, at compile time.
    Unit testing.
*/