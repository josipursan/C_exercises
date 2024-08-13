#include <stdio.h>

#define MAX_BUF 256

long arr[10] = {3,6,1,2,3,8,4,1,7,2};
char arr_2[5][20] = { "Mickey Mouse",
                      "Donald Duck",
                      "Minnie Mouse",
                      "Goofy",
                      "Ted Jensen" };

void bubble_1(int a[], int N);
void bubble_2(void *p, int width, int N, int(*fptr)(const void *, const void *));
int compare_string(const void *m, const void *n);
int compare_long(const void *m, const void *n);

int arr[10] = {3,6,1,2,3,8,4,1,7,2};

int main()
{
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    bubble_1(arr, 10);
    printf("\nAfter bubble sort\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void bubble_1(int a[], int N)
{
    int i,j,t;

    for(i=N-1; i >= 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            if(a[j-1] > a[j])
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
        }
    }
}

int compare_string(const void *m, const void *n)
{
    char *m1 = (char *)m;
    char *n1 = (char *)n;
    return (strcmp(m1, n1));
}

int compare_long(const void *m, const void *n)
{
    long *m1 = (long *)m;
    long *n1 = (long *)n;
    return (*m1 > *n1);
}

void bubble_2(void *p, int width, int N, int(*fptr)(const void *, const void *))
{
    int i,j,k;
    unsigned char buf[MAX_BUF];
    unsigned char *bp = p;

    for(i = N-1; i >= 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            k = fptr((void *)(bp + width*(j-1)), (void *)(bp + j*width)); // This is where we called the function pointer we passed when we were calling bubble_2!
            if(k > 0)
            {
                memcpy(buf, bp+width*(j-1), width);
                memcpy(bp + width*(j-1), bp + j*width, width);
                memcpy(bp + j*width, buf, width);
            }
        }
    }

}

/*
    What are function pointers? 
        Name of a function decays into the address of that function in the code segment.
        Therefore, we must use a pointer to a function if we want to say which function we want to use for some code segment.
    
    Why would we do that? Observe bubble_1 implementation. The biggest hurdle we have to overcome to making this function truly universal, irregardles of the data type we want to bubble sort, is this if clause : 
        if(a[j-1] > a[j])
        {
            t = a[j-1];
            a[j-1] = a[j];
            a[j] = t;
        }
        You will notice that everything is hardcoded to int data type.

    Observe the signatures of bubble_1 and bubble_2 : 
        void bubble_1(int a[], int N);
        void bubble_2(void *p, int width, int N, int(*fptr)(const void *, const void *));

    This is how we declare pointer to a function : int (*fptr)(const void *p1, const void *p2);

    If we were to do this : int *fptr(const void *p1, const void *p2); we actually would have declared a function which return pointer to type int.

    Notice we have declared two more functions : 
        int compare_string(const void *m, const void *n);
        int compare_long(const void *m, const void *n);
    These are functions which are tasked with executing appropriate comparisons based on data type, thus overcoming the above described hard coded if clause.

    What does this line do?  k = fptr((void *)(bp + width*(j-1)), (void *)(bp + j*width))

        fptr() is invocation of the funcion pointer, ie. simply calling the function that was passed to bubble_2 as a parameter
    
    What are parameters in fptr() call?     (void *)(bp + width*(j-1)), (void *)(bp + j*width)
    
        These parameters are simply elements from the passed array that get passed on to the compare function.
        Previously, in the hardcoded version, these parameters were "a[j-1] > a[j]".
        But, now because we are passing the array we want to sort as void *p, we have to traverse this pointer using j-th iteration, and take into account the width we have passed (width being here the representation of the number of bytes each element of array takes up in memory).

    Each array of data we want to bubble sort gets passed as void *p to bubble_2.
    Then why this line? ----> unsigned char *bp = p;
    Because unsigned char "may alias other data types without violating the "aliasing rules", that is that access to the same data through a pointer that is typed differently will be guaranteed to see all modifications"
    https://stackoverflow.com/questions/13642381/c-c-why-to-use-unsigned-char-for-binary-data 
        
*/


/*
    What does bubble sort do?

    It scans the array from the second to last element (i=N-1) comparing each element with the one which precedes it.
    If the one that precedes it is larger than the current element (if(a[j-1] > a[j])), the two are swapped so that the larger one is closer to the end of the array.
*/