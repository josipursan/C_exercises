#include <stdio.h>

struct my_struct {
    int x;
    int y;
};

int main(){
    struct my_struct str1;
    str1.x = 5;
    str1.y = 6;

    printf("Address of str1 : %p\nstr1.x : %d\tstr1.y : %d\n", &str1, str1.x, str1.y);

    return 0;
}