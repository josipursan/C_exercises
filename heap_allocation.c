#include <stdio.h>
#include <stdlib.h>

int main(){
    int* x = (int*)malloc(sizeof(int)); // Pointer to a memory space where enough space has been made (reserved) for an integer
    if(x){          // Check if malloc went through ok
        printf("Freeing\n");
        free(x);    // If malloc went through ok we free it
    }
    return 0;
}