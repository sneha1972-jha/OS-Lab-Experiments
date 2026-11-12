#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t S0,S1;
void *t0(void *arg){
    for(int i=0;i<5;i++){
        sem_wait(&S0); printf("0"); sem_post(&S1);
    }
    return NULL;
}
void *t1(void *arg){
    for(int i=0;i<5;i++){
        sem_wait(&S1); printf("1"); sem_post(&S0);
    }
    return NULL;
}
int main(){
    pthread_t a,b;
    sem_init(&S0,0,1); sem_init(&S1,0,0);
    pthread_create(&a,NULL,t0,NULL);
    pthread_create(&b,NULL,t1,NULL);
    pthread_join(a,NULL); pthread_join(b,NULL);
    printf("\n");
    sem_destroy(&S0); sem_destroy(&S1);
}
