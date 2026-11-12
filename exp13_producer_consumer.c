#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5
int b[N],in=0,out=0;
sem_t empty,full,mutex;
void *producer(void *arg){
    for(int i=1;i<=10;i++){
        int x=rand()%100;
        sem_wait(&empty); sem_wait(&mutex);
        int p=in; b[in]=x; in=(in+1)%N;
        printf("%d producer produce %d at %d\n",i,x,p);
        sem_post(&mutex); sem_post(&full);
    }
    return NULL;
}
void *consumer(void *arg){
    for(int i=1;i<=10;i++){
        sem_wait(&full); sem_wait(&mutex);
        int p=out,x=b[out]; out=(out+1)%N;
        printf("%d consumer consume %d from %d\n",i,x,p);
        sem_post(&mutex); sem_post(&empty);
    }
    return NULL;
}
int main(){
    pthread_t p,c;
    sem_init(&empty,0,N); sem_init(&full,0,0); sem_init(&mutex,0,1);
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL); pthread_join(c,NULL);
    sem_destroy(&empty); sem_destroy(&full); sem_destroy(&mutex);
}
