#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define N 5          // Number of philosophers
#define MAX_MEALS 3  // Each philosopher eats 3 times

sem_t chopstick[N];

void* philosopher(void* num) {
    int id = *(int*)num;
    int i=0;
    for(i = 0; i < MAX_MEALS; i++) {

        printf("Philosopher %d is Thinking\n", id);
        sleep(1);

        // Pick left chopstick
        sem_wait(&chopstick[id]);

        // Pick right chopstick
        sem_wait(&chopstick[(id + 1) % N]);

        printf("Philosopher %d is Eating (%d time)\n", id, i+1);
        sleep(2);

        // Put down left chopstick
        sem_post(&chopstick[id]);

        // Put down right chopstick
        sem_post(&chopstick[(id + 1) % N]);
    }

    printf("Philosopher %d has finished eating.\n", id);
    return NULL;
}

int main() {
    pthread_t thread[N];
    int id[N];
    int i=0;
    for(i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    for(i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &id[i]);
    }

    for(i = 0; i < N; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("All philosophers have finished their meals.\n");

    return 0;
}
