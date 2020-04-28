#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<pthread.h>
#include<unistd.h>

void *A(void *arg);
void *B(void *arg);
int r1 = 1;
int x = 6;
int y = 3;

int main()
{
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, A,(void *)&x);
	pthread_create(&threads[1], NULL, B,(void *)&y);
	for (int i=0; i<2; i++)
		pthread_join(threads[i], NULL);
	r1 = x+y;
	printf("R1 = %d \n", r1);
}
void* A(void *arg)
{
	int *entrada = arg;
	int i, cont = *entrada;
	for (i = cont; i > 0; i--)
		cont = cont - 0.5;
}
void* B(void *arg)
{
	int i, *entrada = arg;
	int aux = *entrada;
	for (i=0; i<*entrada; i++)
	{
		aux = aux+1;
	}
	*entrada = aux;
}
