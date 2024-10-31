#include "buffer.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>


BUFFER_ITEM buffer[BUFFER_SIZE];
int count = 0;
int insertPos = 0;
int removePos = 0;
sem_t *empty;
sem_t *full;
sem_t *mutex;
bool terminate = false;
int MAX_SLEEP = 10;

int insert_item(BUFFER_ITEM item){
    //insert item into buffer

    buffer[insertPos] = item;
    insertPos = (insertPos + 1) % BUFFER_SIZE;
    count++;
    //return 0 if success
    return 0;
    //return -1 if erorr
}

int remove_item(BUFFER_ITEM *item){
    //remove item from buffer

    *item = buffer[removePos];
    removePos = (removePos + 1) % BUFFER_SIZE;
    count--;
    //placing it in item
    //return 0 if successful 
    return 0;
}



void *producer(void *param){
    BUFFER_ITEM item;
    fflush(stdout);
    item.cksum = 0;

    while (terminate != true){
        if (terminate == true){
            break;
        }
        //sleep for random period of time
        fflush(stdout);
        sleep((rand() % MAX_SLEEP) + 1);\
        printf("producer wakes up from sleep\n");
        fflush(stdout);
        //gen random number
        for (int i = 0; i < 30; i++){
            item.data[i] = rand() % 256;
            item.cksum += item.data[i];
        }

        sem_wait(empty);
        sem_wait(mutex);

        printf("semaphores acquired by producer\n");
        fflush(stdout);

        if (insert_item(item) != 0){
            fprintf(stderr, "report error condition");
            fflush(stdout);
        }
        else{
            printf("Producer produced: ");
            for (int i = 0; i < 30; i++) {
                printf("%d ", item.data[i]);            
            }
            printf("\n");

        }
        sem_post(mutex);
        sem_post(full);

    }   
    pthread_exit(NULL);
    printf("producer terminated\n");
    fflush(stdout);
}

void *consumer(void *param){
    BUFFER_ITEM item;


    while (terminate != true){
        if (terminate == true){
            break;
        }       
        //sleep for random period of time
        sleep((rand() % MAX_SLEEP) + 1);
        printf("Consumer wakes up from sleep\n");
        fflush(stdout);

        sem_wait(full);
        printf("full semaphore acquried\n");
        sem_wait(mutex);

        printf("semaphores acquired for consumer\n");
        fflush(stdout);
        if(remove_item(&item) != 0){
            printf("report error condition");
            fflush(stdout);
        }
        else{
            printf("Consumer consumed: ");
            for (int i = 0; i < 30; i++) {
                printf("%d ", item.data[i]);
            }
                printf("\n");

        }
        sem_post(mutex);
        sem_post(empty);
    }
    pthread_exit(NULL);
    printf("consumer terminated\n");
    fflush(stdout);
}



int main(int argc, char *argv[]){
    // get command line arguements argv[1], argv[2], and argv[3]
    sem_unlink("/empty");
    sem_unlink("/full");
    sem_unlink("/mutex");
    fflush(stdout);
    int sleeptime = atoi(argv[1]);
    int numProducer = atoi(argv[2]);
    int numConsumer = atoi(argv[3]);

    pthread_t producers[numProducer];
    pthread_t consumers[numConsumer];
    int produce;
    int consume;

    empty = sem_open("/empty", O_CREAT | O_EXCL, 0644, BUFFER_SIZE);
    full = sem_open("/full", O_CREAT | O_EXCL, 0644, 0);
    mutex = sem_open("/mutex", O_CREAT | O_EXCL, 0644, 1);

    if (empty == SEM_FAILED || full == SEM_FAILED || mutex == SEM_FAILED) {
        perror("sem_open failed");
        fflush(stdout);
        exit(EXIT_FAILURE);
    }
    else{
        printf("semaphore intialized correctly \n");
        fflush(stdout);
    }
    //initialize buffer
    for (int i = 0; i < BUFFER_SIZE; i++){
        memset(buffer[i].data, 0, sizeof(buffer[i].data));
        buffer[i].cksum = 0;
    }
    //create producer threads
    for (int i = 0; i < numProducer; i++){
        fflush(stdout);
        produce = pthread_create(&producers[i], NULL, producer, NULL);
        if (produce != 0){
            perror("Error creating producer thread \n");
            return -1;
    }
    }
    //create consumer threads
    for (int j = 0; j < numConsumer; j++){
        fflush(stdout);
        consume = pthread_create(&consumers[j], NULL, consumer, NULL);
        if (consume != 0){
            perror("Error creating consumer thread \n");
            return -1;
    }
    }
    //sleep
    sleep(sleeptime);
    printf("main wakes up from sleep\n");
    fflush(stdout);
    // fix sleep before termination 
    terminate = true;
    printf("main terminates loops \n");
    fflush(stdout);
    for (int i = 0; i < numProducer; i++){
        pthread_cancel(producers[i]);
        pthread_join(producers[i], NULL);
    }
    for (int i = 0; i < numConsumer; i++){
        pthread_cancel(consumers[i]);
        pthread_join(consumers[i], NULL);
    }
    printf("threads joined\n");
    fflush(stdout);

    sem_close(empty);
    sem_close(full);
    sem_close(mutex);
    sem_unlink("/empty");
    sem_unlink("/full");
    sem_unlink("/mutex");
    //exit
    printf("exiting...\n");
    fflush(stdout);

    return 0;
}