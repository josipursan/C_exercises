#include <stdio.h>

int main(int argc, char* argv[]){
    for(int i=0; i<argc; ++i){
        printf("argv[%d] : %s\n", i, argv[i]);
    }

    /*
        argc - arg count
            -int variable which say how many cmd line arguments have been passed by the user
        
        argv - arg variable
            -array of cmd line arguments
    */

    return 0;
}