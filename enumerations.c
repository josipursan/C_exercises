#include <stdio.h>

enum week {
    mon,
    tue,
    wed,
    thu,
    fri,
    sat,
    sun
};

int main() {
    for(int i = mon; i<=sun; ++i){
        printf("%d\n", i);
    }

    return 0;
}