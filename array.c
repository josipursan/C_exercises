#include <stdio.h>

int main(){
    int first_array[5];
    int second_array[] = {0,1,2,3,4};

    size_t len = sizeof(first_array)/sizeof(first_array[0]);
    for(size_t i = 0; i<len; ++i){
        first_array[i] = i;
    }

    for(int i = 0; i<len; ++i){
        printf("first_array[%d] : %d\n", i, first_array[i]);
        printf("second_array[%d] : %d\n", i, second_array[i]);
    }

    return 0;
}