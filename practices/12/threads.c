#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 20

void *helloThread(void *arg)
{
    int id = *((int *) arg);
    printf("Hello world from %d!\n", id);
}

int main()
{
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(
            &threads[i],
            NULL,
            helloThread,
            (void *) &i
        );
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
