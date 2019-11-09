#include <stdio.h>
#include <pthread.h>

void *loopThread(void *arg);


int main()
{
	int		i;
	pthread_t	thr[3];


	for (i = 0; i < 3; i++)
		pthread_create(&thr[i], NULL, loopThread,(void *) i);

	for (i = 0; i < 3; i++)
		pthread_join (thr[i], NULL); 
}

void *loopThread (void *arg)
{
	int i, j;
	int threadNo = (int) arg;

	for (i = 0; i < 20; i++)
	{
		printf("Thread %d\n", threadNo);
		sleep (1);
	}
}