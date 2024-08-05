#include <stdio.h>
#include <threads.h>

typedef struct data{
    mtx_t mtx;
    int x;
} data;

int thread_func(void* arg){
    data* d = (data*)arg;
    mtx_lock(&d->mtx);
    d->x += 1;
    mtx_unlock(&d->mtx);
    return 0;
}

int main(){
    data d;
    mtx_init(&d.mtx, mtx_plain);
    thrd_t thread_id[10];

    for(int i = 0; i<10; ++i){
        thrd_create(&thread_id[i], thread_func, (void*)&d);
        thrd_join(thread_id[i], NULL);
    }

    printf("End x : %d\n", d.x);

    return 0;
}

/*
    Remember : pthread_mutex_t is POSIX specific (although I think it is present on onther systems)

    Mutual exclusion functionality - used to serialize access to shared variables between concurrent threds
 */