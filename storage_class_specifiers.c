#include <stdio.h>

int main(){
    extern int a; // defined elsewhere
    static int b; // hold value between invocations
    register int c; // store in CPU register for fast access
    auto int d; // automatic duration - scope lifetime. Implicit if not specified
    _Thread_local int e; // thread storage duration

    /*
        register - hint to the compiler that the variable will be heavily used, and that you recommend it is kept in the CPU register if possible
            -some/most compilers will ignore this keyword (e.g. GCC always ignored this), some compilers do this optimization on their own

        auto - a storage class specifier which indicates thet the variable's lifetime is equal to its scope
            -when it goes out of scope, it is "auto"matically destroyed

        _Thread_local - storage class specifier which marks that a variable is given thread storage duration, ie. they are allocated when the
            thread begins, and deallocated when the thread ends.
                -such variables are local to the thread

                -DO NOT confuse static and _Thread_local - a static variable comes into existence at the beginning of the program execution and exists for the
                    entire runtime of the program; an object with static storage duration is shared by all threads; an object with _Thread_local storage classifier
                        is bound to the thread in which it was created (and consequently destroyed)        
    */
    return 0;
}