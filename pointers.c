#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/*
First problem/exercise set : https://w3.cs.jmu.edu/lam2mo/cs240_2015_08/lab06-pointers.html

A pointer is a variable that holds a memory address.
To avoid issues, if the pointer is not being set to some value immediately, initialize to null : int *p = NULL;
*/

typedef struct point{
    int x;
    int y;
}point_t;

int main()
{
    int x = 5;

    //int *a;
    //int *m, *n; // If you wish to declare multiple pointers on the same line, you must include asterisk with each of them.

    int *p;
    p = &x;

    printf("x value : %d\tx address : %x\n", x, &x);
    printf("p value : %x\tp address : %x\tp deref value : %d\n", p, &p, *p);

    // Exercise : tracing

    int a = 42;
    int b = 7;
    int c = 999;    // We have 3 ordinary, initialized, int variables : a,b,c
    int *t = &a;
    int *u = NULL;  // We have two int pointer variables : t is initialized with address of variable a; u is initialized to NULL
    printf("%d %d\n", a, *t);   // This printf will printf 42 42 because we printf a, and dereference *t, meaning that we grab the value of a

    c = b;  // Value of variable b is assigned to c, meaning that c is now 8
    u = t;  // Pointer u (which was inited to NULL) has its value now set to t --> t is a pointer, so when we set u to the value of t, we set variable u to the address set in pointer t
    printf("%d %d\n", c, *u);   // This printf will print 7 42 because c = b = 7, and because u = t = &a

    a = 8; 
    b = 8;
    printf("%d %d %d %d\n", b, c, *t, *u);  // This printf will print 8 7 8 8 because b has been set to 8 (line above), c has been previously set to b (b at the time was 7), *t = a = 8, *u = a = 8

    *t = 123;   // Value that can be found at the address to which ptr t is pointing is set to 123
    printf("%d %d %d %d %d\n", a, b, c, *t, *u);    // This printf will print 123 8 7 123 123 because a=123 due to *t = 123, b stays 8, c stays 7, *t = a = 123, *u = a = 123

    /*
        1. Update t to point to c.
            Use a pointer dereference to change the value of c to 555.
    */

    t = &c; // udpate t to point to c.
    printf("%d %d %d %d %d\n", a, b, c, *t, *u); // This printf will print 123 8 7 7 123 because a has been set to 123 by *t couple of lines above, b has been 8 for some time now, c has been 7 for some time now, t now points to c, and u points to a (which is 123)

    *t = 555; // Using pointer dereferencing we change the value of c to 555
    printf("%d %d %d %d %d\n", a, b, c, *t, *u); // 123 8 555 555 123 because a has been set to 123 by *t couple of lines above, b is unchanged, c has been set to 555 by *t, t points to c, u points to t (which points to c)

    /*
        You made a fault when predicting the above printf value. You predicted 123 8 555 555 555. Why?
        Because you were thinking of L2 pointers, hence you were expecting that u would return 555 because u was initialized like so : u = t.
        But, the issue here is that when you have L1 pointers, and you do u = t, what happens is that whatever is in t gets dumped to buffer representing u, and it stays there.
        Hence, u = address_of_whichever_variable_was_in_t_at_the_time_of_assignment
        What you predicted would hold true only if you did u = t before *t = 555, or if you had this : int **u; u = &t; at the first assignment.
    */


    // Exercise : Allocating memory
    int *r = (int*)malloc(sizeof(int)); // Malloc returns a void* pointer to the allocated memory; becuase it is void*, we have to cast it to the wanted data type.

    if(r = NULL)
    {
        printf("Malloc issue!\n");
    }
    free(r);

    // Exercise : Arrays and pointers
    int d[3] = {0, 1, 2};
    printf("Element 0. : %d\n", *d);
    printf("Element 1. : %d\n", *(d+1));
    printf("Element 2. : %d\n", *(d+2));

    int i;

    for(i = 0; i<3; ++i)
    {
        printf("Element %d : %d\n", i, d[i]);
    }
    for(int *w = d; w < (d+3); ++w)
    {
        printf("Value : %d\n", *w);
    }

    // Structs and pointers
    point_t *pt = (point_t*)malloc(sizeof(point_t));

        // Example #1 of how to access/set/dereference variables in a ptr to struct
    (*pt).x = 1;
    (*pt).y = 2;
    printf("x : %d\ty : %d\n", pt->x, pt->y);

        // Example #2 of how to access/set/dereference variables in a ptr to struct
    pt->x=3;
    pt->y=4;
    printf("x : %d\ty : %d\n", pt->x, pt->y);


    // Pointers can also be used to store references to arrays of structs
    point_t *pts = (point_t*)malloc(sizeof(point_t) * 4); // 4 point_t structs are allocated

    if(pts == NULL)
    {
        printf("Malloc issue\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i<4; ++i)
    {
        pts[i].x = i*10;
        pts[i].y = i*20;
    }

    for(int i = 0; i<4; ++i)
    {
        printf("struct %d\nx : %d\ty : %d\n\n", i, pts[i].x, pts[i].y);
    }


    // Passing structs into functions using pointers
    point_t* addPoints(point_t *p1, point_t *p2)
    {
        int x_added = p1->x + p2->x;
        int y_added = p1->y + p2->y;
        printf("x_added : %d\ty_added : %d\n", x_added, y_added);
    }

    point_t p1 = {.x = 5, .y = 5};
    point_t p2 = {.x = 6, .y = 6};
    addPoints(&p1, &p2);    // When the variable which holds the structure is not pointer, then you pass with address operator because the function expects a pointer (ie. address)

    // Different example of how struct is passed if it is defined as a ptr - considering point_t *p3 and *p4 are already pointers, it means that p3 and p4 hold a an address in themselves to the struct, which is why we pass to function like we did
    point_t *p3 = (point_t*)malloc(sizeof(point_t));
    point_t *p4 = (point_t*)malloc(sizeof(point_t));
    p3->x = 1;
    p3->y = 1;
    p4->x = 2;
    p4->y = 2;
    addPoints(p3, p4); // When the variable you are passing is of pointer type, then you pass its name as is, because the variable holds an address (which is expected by the function)  
    

}
/* /////////////////// - - - - - END OF FIRST PROBLEM/EXERCISE SET - - - - - - \\\\\\\\\\\\\\\\\\\\*/