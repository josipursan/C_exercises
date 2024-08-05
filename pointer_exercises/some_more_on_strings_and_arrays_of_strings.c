#include <stdio.h>

int main()
{
    char my_string[40] = "Ted";
    char my_string_2[] = "Ted";
    char *my_string_3 = "Ted";
    // All of these do the same job - create a chunk of memory, and store string Ted in it. The first example creates a 40 byte chunk of memory because it was explicitly told to do so.
    // The second two rely on the compiler counting the characters and creating the necessary chunk of memory.

    /*
        However, there is a more important difference between these.

        The array notation (first example) takes up 4 bytes of storage space - one for each character, plus one for the terminating nul character.
        When using array notation, writing my_string is equivalent to &my_string[0]. Since the location of the array is fixed during runtime (because we decalred we want 40 bytes, thus compiler takes up
        some 40 byte memory chunk), &my_string[0] is a constant.

        The pointer notation (bottom two examples) requires the same 4 bytes for the string, plus N bytes to store the pointer variable my_string (so in addition to some chunk in memory holding the string itself,
        we also have to have a chunk of memory where the pointer my_string, which points to the chunk of memory holding the string, is stored. N depends on system - usually minimum of 2 bytes, and more.)
    */

    return 0;
}