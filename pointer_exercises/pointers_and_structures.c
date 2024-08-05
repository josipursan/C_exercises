#include <stdio.h>
#include <string.h>

struct tag
{
    char lname[20];
    char fname[20];
    int age;
    float rate;
};

void show_data(struct tag *tag_struct_ptr)
{
    printf("lname : %s\nfname : %s\nage : %d\nrate : %f\n", tag_struct_ptr->lname, tag_struct_ptr->fname, tag_struct_ptr->age, tag_struct_ptr->rate);
}

struct tag my_struct;

int main()
{
    strcpy(my_struct.lname, "Pero");
    strcpy(my_struct.fname, "Spongebob");
    printf("\n%s\n%s\n", my_struct.lname, my_struct.fname);

    struct tag *st_ptr; //pointer st_ptr to structure of type tag
    st_ptr = &my_struct; //pointing the pointer to our already create structure my_struct

    (*st_ptr).age = 50; //assigning field age a value of 50 through the pointer
    printf("Age directly from structure : %d\nAge through pointer : %d\n", my_struct.age, (*st_ptr).age);

    st_ptr->age = 20;   // A more succint way of assigning a field value through a pointer
    printf("Age directly from structure : %d\nAge through pointer : %d\n", my_struct.age, st_ptr->age);

    st_ptr->rate = 51.78;
    printf("Rate directly from structure : %f\nRate through pointer : %f\n", my_struct.rate, st_ptr->rate);

    show_data(st_ptr);

    return 0;
}