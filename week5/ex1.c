#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* func(void* i)
{
    int *t = (int*)i;
    printf("%d", *t);
    printf("Thread announced\n");
    pthread_exit(0);
}

int* indexes;
pthread_t* thread;

int main()
{
    int n;
    scanf("%d", &n);
    int threads = n, i = 0, ret = -1;
    thread = (pthread_t*)malloc(sizeof(pthread_t) * threads);
    indexes = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < threads; i++)
    {
        void* ret;
        indexes[i] = i;
        pthread_create(&thread[i], NULL, func, &indexes[i]);
        pthread_join(thread[i], &ret);
    }
}
