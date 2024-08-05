#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
    int total, i;
    total = 0;
    
    va_list args; //va_list macro is used to decalare a variable that will hold the list of arguments passed to the function
    va_start(args, count); //va_start macro is used to initialize the va_list variable, and must be passed the last non-variadic argument of the function
    
    for(int i = 0; i < count; ++i){
        total += va_arg(args, int); //va_arg macro is used to retrieve the next argument from the va_list; this is where you pass the va_list variable; type of argument being retrieved also must be passed
    }

    va_end(args);   //va_end macro must be called to clean up the va_list variable
    return total;

}

int main(){
    int numbers[5] = {5, 10, 15, 20, 25};
    int sum_of_numbers = sum(2, numbers[0], numbers[1]);
    printf("Sum is : %d\n", sum_of_numbers);

    return 0;
}