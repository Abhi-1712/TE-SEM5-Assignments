//  Roll-No: 33231
//  Name: Abhijeet Ingle
//  Batch: K-10

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

sem_t full, empty;
pthread_mutex_t lock;
int pr, cs;
void *Producer(void *arg);
void *Consumer(void *arg);
int *BUFFER;
int buff_size;


int main()
{   
    printf("Enter the buffer size\n");
    scanf("%d",&buff_size);
    printf("Enter the number of producers:");
    scanf("%d", &pr);
    printf("Enter the number of consumers:");
    scanf("%d", &cs);
    
    
    BUFFER = (int *)malloc(buff_size * sizeof(int));
    for (int i = 0; i < buff_size; i++) BUFFER[i] = 0;
    
    pthread_t p[pr], c[cs];
    void *thread_result;
    int res;

    sem_init(&empty, 0, buff_size-1);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < pr; i++)
    {
        res = pthread_create(&p[i], NULL, Producer, (void *)&i);
        if (res != 0)
        {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < cs; i++)
    {
        res = pthread_create(&c[i], NULL, Consumer, (void *)&i);
        if (res != 0)
        {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < pr; i++)
    {
        res = pthread_join(p[i], NULL);
        if (res != 0)
        {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < cs; i++)
    {
        res = pthread_join(c[i], NULL);
        if (res != 0)
        {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
    return 0;
}

void *Producer(void *arg)
{
    int index= *(int *)arg;
    while(1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&lock);
        if(BUFFER[index]==0){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Producer thread: %d\n", index);
            BUFFER[index]=1;
            for(int i=0;i<buff_size;i++){
                printf(" %d", BUFFER[i]);
            }
            printf("\n");
        }
        else{
            sleep(1);
        }
        //printf("Hello,This is producer code\n");
        pthread_mutex_unlock(&lock);
        sem_post(&full);
    }
    //pthread_exit("Exit producer..");
}

void *Consumer(void *arg)
{   
    int index= *(int *)arg;
    while(1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&lock);
        if(BUFFER[index]==1){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Consumer thread: %d\n", index);
            BUFFER[index]=0;
            for(int i=0;i<buff_size;i++){
                printf(" %d", BUFFER[i]);
            }
            printf("\n");
        }
        else{
            sleep(1);
        }
        
        pthread_mutex_unlock(&lock);
        sem_post(&empty);
    } 
    
}
