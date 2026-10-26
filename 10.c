#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#define NUM_THREADS 5

int shared_resource = 0;
sem_t semaphore;

void *thread_function(void *arg)
{
    int thread_id = *((int *)arg);
    while (sem_wait(&semaphore) == -1) {
        if (errno != EINTR) { perror("sem_wait"); exit(EXIT_FAILURE); }
    }
    printf("Thread %d accessing shared resource.\n", thread_id);
    shared_resource++;
    printf("Shared resource value incremented to: %d\n", shared_resource);
    if (sem_post(&semaphore) == -1) { perror("sem_post"); exit(EXIT_FAILURE); }
    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    if (sem_init(&semaphore, 0, 1) == -1) { perror("sem_init"); return 1; }
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }
    if (sem_destroy(&semaphore) == -1) { perror("sem_destroy"); return 1; }
    return 0;
}
