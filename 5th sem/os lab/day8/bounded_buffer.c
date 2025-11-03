/*
 * bounded_buffer.c
 *
 * Producer–Consumer problem using pthreads, mutex, and named POSIX semaphores.
 * Compatible with macOS (uses sem_open instead of sem_init).
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>      // For sleep()
#include <fcntl.h>       // For O_CREAT
#include <sys/stat.h>    // For mode constants
#include <time.h>        // For time()

// Buffer configuration
#define BUFFER_SIZE 5
#define NUM_ITEMS 20

// Shared buffer
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

// Synchronization primitives
pthread_mutex_t mutex;

// Named semaphores (use pointers)
sem_t *empty;
sem_t *full;

/*
 * Producer Thread
 */
void *producer(void *arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        item = rand() % 100;

        // Wait for empty slot
        sem_wait(empty);

        // Lock buffer
        pthread_mutex_lock(&mutex);

        // Add item
        buffer[in] = item;
        printf("Producer: Produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        // Unlock buffer
        pthread_mutex_unlock(&mutex);

        // Signal full slot
        sem_post(full);

        // Simulate delay
        sleep(rand() % 2);
    }
    pthread_exit(NULL);
}

/*
 * Consumer Thread
 */
void *consumer(void *arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        // Wait for full slot
        sem_wait(full);

        // Lock buffer
        pthread_mutex_lock(&mutex);

        // Remove item
        item = buffer[out];
        printf("Consumer: Consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        // Unlock buffer
        pthread_mutex_unlock(&mutex);

        // Signal empty slot
        sem_post(empty);

        // Simulate delay
        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

/*
 * Main function
 */
int main() {
    pthread_t prod_thread, cons_thread;

    srand(time(NULL));

    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex init failed");
        exit(EXIT_FAILURE);
    }

    // Clean up old semaphores if they exist
    sem_unlink("/empty_sem");
    sem_unlink("/full_sem");

    // Create named semaphores
    empty = sem_open("/empty_sem", O_CREAT, 0644, BUFFER_SIZE);
    full  = sem_open("/full_sem",  O_CREAT, 0644, 0);

    if (empty == SEM_FAILED || full == SEM_FAILED) {
        perror("sem_open failed");
        exit(EXIT_FAILURE);
    }

    printf("Starting Producer and Consumer threads...\n");

    // Create threads
    if (pthread_create(&prod_thread, NULL, producer, NULL) != 0) {
        perror("Producer thread create failed");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&cons_thread, NULL, consumer, NULL) != 0) {
        perror("Consumer thread create failed");
        exit(EXIT_FAILURE);
    }

    // Wait for threads
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    printf("Producer and Consumer threads have finished.\n");

    // Clean up
    pthread_mutex_destroy(&mutex);
    sem_close(empty);
    sem_close(full);
    sem_unlink("/empty_sem");
    sem_unlink("/full_sem");

    return 0;
}
