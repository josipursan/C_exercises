#include <stdio.h>

int main(){

    restrict int* a;
    const int b;
    atomic int c;
    volatile int d;

    /*
        restrict - keyword restrict says that the pointer is the only thing that can access the underlying object
            -eliminates potential for pointer aliasing, enabling better optimization by the compiler
            -restrict says that two pointers can not point to overlapping memory regions
            -by adding the restrict type qualifier, a programmer hints to the compiler that for the lifetime of the pointer, no other pointer will be used to access
                the object to which it points

        const - type qualifier which can be used to specify that the variable's value will not be changed
            -used when you want a variable to be read-only

        atomic - objects of atomic type are the only objects free from data races
        
        volatile - type qualifier which tells the compiler that the value of the variable may change at any time without any action being taken by the code the compiler
            finds nearby
                -volatile keyword tells the optimizer not to optimize anything that has to do with the volatile variable
                -used when you interface with hardware that changes value itself, when there is another thread running that also uses this variable, and 
                    when there is a signal handler that might change the value of the variable
    */

    return 0;
}