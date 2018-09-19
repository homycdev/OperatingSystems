#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int count = 0;
int read = 1;
int write = 1;

void *consumer()
{
    while (1)
    {if (count == 0)while (!read){}
    printf("consumer\n");write = 1;}
}

void *producer()
{
    while (1){
        if (count == BUFFER_SIZE)while (!write){};
        printf("producer\n");read = 1;}
}

pthread_t cons, prod;

int main(){
    void *ret;
    pthread_create(&cons, NULL, consumer, NULL);pthread_create(&prod, NULL, producer, NULL);
    pthread_join(cons, &ret);pthread_join(prod, &ret);

    return 0;
}