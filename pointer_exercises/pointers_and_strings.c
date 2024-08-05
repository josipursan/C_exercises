#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80];

char *my_strcpy_2(char **destination, const char *source)  // const access modifier ensures that my_strcpy will not modify the string passed to function for copying (i.e. source)
{
    printf("destination : %p\t&destination : %p\t*destination : %p\n", destination, &destination, *destination);
    *destination = (char*)malloc(strlen(source) * sizeof(char));  
    char *p = *destination;
    while(*source != '\0')
    {
        *p++ = *source++;
    }
    *p = '\0';
    return *destination;
}

char *my_strcpy(char *destination, const char *source)
{
    char *p = destination;
    while(*source != '\0')
    {
        *p++ = *source++;
    }
    *p = '\0';
    return destination;
}

int main(void)
{

    char *pA;     /* a pointer to type character */
    char *pB;     /* another pointer to type character */
    puts(strA);   /* show string A */
    pA = strA;    /* point pA at string A */
    puts(pA);     /* show what pA is pointing to */
    pB = strB;    /* point pB at string B */
    putchar('\n');       /* move down one line on the screen */
    while(*pA != '\0')   /* line A (see text) */
    {
        *pB++ = *pA++;   /* line B (see text) */    //This line copies char by char the string pA is pointing to by dereferencing characters at the address currently pointed to by pA, and incrementing address stored in pA
    }
    *pB = '\0';          /* line C (see text) */
    puts(strB);          /* show strB on screen */

    char *test_string = "Pero";
    //char *copied_test_string = (char*)malloc(strlen(test_string) * sizeof(char));   // if you declare like this : char *copied_test_string you will get a segfault. Why? Because this variable then has enough memory to store memory address for one char element, not for the whole string. Therefore you either have to do this char copied_test_string[50], or malloc the memory for it in my_strcpy
    // Or
    //char copied_test_string[strlen(test_string)];
    //my_strcpy(copied_test_string, test_string);
    
    char *copied_test_string;   // If you want to do the malloc for copied_test_string in my_strcpy, then you need this line, and my_strcpy2
    printf("&copied_test_string : %p\tcopied_test_string : %p\n", &copied_test_string, (void*)copied_test_string);
    my_strcpy_2(&copied_test_string, test_string);

    printf("test_string : %s\ncopied_test_string : %s\n", test_string, copied_test_string);


    return 0;
}


/*
    Explanation

    What is the difference between my_strcpy and my_strcpy_2?

    my_strcpy implicitly expects that destination pointer will have enough memory to copy source string.
    It expects that enough memory has been malloced or taken up by having properly sized array. ---> char *copied_test_string = (char*)malloc(strlen(test_string) * sizeof(char))   OR  char copied_test_string[strlen(test_string)]

    my_strcpy_2 does the mallocing itself. However, to malloc memory in my_strcpy_2 for pointer that is being passed from different function, destination argument must be pointer to pointer.
    This is because we want to allocate enough memory in the space to which pointer is pointing, ie. we do not want to allocate memory for ptr, but for *ptr.
    To do this, the variable we pass to function must be double pointer, ie. we pass the variable with & operator.
    Then in the function we do *ptr = malloc(...)
    All other references to destination in my_strcpy_2 are done using dereference operator (*destination).
    Why is this so? Because we aren't operating on the pointer per se, but the memory chunk it is looking to - pointer only points to it! We actually want to malloc enough memory in the section of memory
        to which the pointer is pointing to. Pointer variable itself is absolutely irrelevant in this (except the fact that it provides us with the "route" to this memory chunk).
        At the top of my_strcpy_2, and before my_strcpy_2 is invoked, you have printfed all relevant variables and their addresses, supporting everything you've described here.

    https://stackoverflow.com/questions/1398307/how-can-i-allocate-memory-and-return-it-via-a-pointer-parameter-to-the-calling

 */
