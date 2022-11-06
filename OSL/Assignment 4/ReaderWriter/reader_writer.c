//  Roll-No: 33231
//  Name: Abhijeet Ingle
//  Batch: K-10

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

int readcount,reader_number,writer_number;
sem_t read_sem,write_sem;

void *Reader(void *arg);
void *Writer(void *arg);
int number=1;

int main(){
	printf("Enter the number of reader:");
	scanf("%d",&reader_number);
	printf("Enter the number of writer");
	scanf("%d",&writer_number);
	
	pthread_t read[reader_number],write[writer_number];
	int res;
	
	sem_init(&read_sem,0,1);
	sem_init(&write_sem,0,1);
	
	for(int i=0;i<reader_number;i++)
	{
		res=pthread_create(&read[i],NULL,Reader,(void *)&i);
		if (res!=0){
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
	}
	
	for(int i=0;i<writer_number;i++)
	{
		res=pthread_create(&write[i],NULL,Writer,(void *)&i);
		if(res!=0)
		{
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
	}
	
	for(int i=0;i<reader_number;i++)
	{
		res=pthread_join(read[i],NULL);
		if(res!=0)
		{
			perror("Thread join failed");
			exit(EXIT_FAILURE);
		}
	}
	
	for(int i=0;i<writer_number;i++)
	{
		res=pthread_join(write[i],NULL);
		if(res!=0)
		{
			perror("Thread join failed");
			exit(EXIT_FAILURE);
		}
	}
	
	return 0;

}

void *Reader(void *arg){
	int index=*(int *)arg;
	while(1){
		
		sem_wait(&read_sem);
		readcount++;
		if(readcount==1)
		{
			sem_wait(&write_sem);
		}
		sem_post(&read_sem);
		
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Reader no%d\n",index);
		printf("Reading value: %d\n",number);
		
		
		
		
		
		sem_wait(&read_sem);
		readcount--;
		if(readcount==0){
			sem_post(&write_sem);
		}
		sem_post(&read_sem);
		
		sleep(2);	
		
	}
}

void *Writer(void *arg){
	int index=*(int *)arg;
	while(1){
		sem_wait(&write_sem);
		
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Writer no: %d\n",index);
		printf("Value changed from %d",number);
		number++;
		printf(" to %d\n",number);
		
		sem_post(&write_sem);
		
		sleep(2);
	
	
	
	
	}
}








































