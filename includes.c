#include <stdio.h>
#include "../include/file.h"

int main(){
    // use some functions here from file.h
}

/*
    In file include/file.c

    #include <stdio.h
    #include "file.h"

    //Implementation of all functions declared in file.h

    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 

    In file include/file.h

    #ifndef PROG_H
    #define PROG_H

    //Declarations of functions

    #endif

    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 


    Why use include guards? 
        Once the header is included, it checks if a unique value (in our case PROG_H) is defined.
        If it is not defined, it defines it and continues on.
        If the code is included again, ifndef fails, because it realises PROG_H has already been defined.
        
        Include guards prevent double declaration of any identifiers such as types, enums, static vars, recursive includes, etc.
*/