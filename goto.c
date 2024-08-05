#include <stdio.h>

int main(){
    int x = 5;

    if(x < 10){
        goto printmessage;
    }
    else{
        return 0;
    }
printmessage:
    printf("AAAA\n");
}