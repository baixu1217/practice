#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define SIZE 64
int ring[SIZE];
sem_t blank_sem,data_sem;
void *consume(void* arg)
{
	int i = 0;
	while(1)
	{
		sem_wait(&data_sem);
		int data = ring[i++];
		sem_post(&blank_sem);
		i %= SIZE;
		printf("consume is %d\n",data);
		sleep(3);
	}
}

void *product(void *arg)
{
	int data = 0;
	int i = 0;
	while(1)
	{
		sem_wait(&blank_sem);
		ring[i++] = data;
		sem_post(&data_sem);
		i %= SIZE;
		printf("product is : %d\n",data++);
	//	sleep(1);
	}
}

int main()
{
	sem_init(&blank_sem,0,SIZE);
	sem_init(&data_sem,0,0);
	pthread_t c,p;
	pthread_create(&c,NULL,consume,NULL);
	pthread_create(&p,NULL,product,NULL);

	pthread_join(c,NULL);
	pthread_join(p,NULL);

	sem_destroy(&blank_sem);
	sem_destroy(&data_sem);

	return 0;
}
