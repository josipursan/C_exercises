#include <stdio.h>
#include <threads.h>

int thread_function(void* arg){
    printf("In thread function\n");
    return NULL;
}

int main(){
    thrd_t thread_id;
    thrd_create(&thread_id, thread_function, NULL);
    thrd_join(thread_id, NULL);
    printf("Thread returned\n");
    return 0;
}