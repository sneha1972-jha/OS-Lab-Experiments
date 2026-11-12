#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 6
void* display(void* arg){
    int i=*(int*)arg;
    free(arg);
    printf("Thread %d: my ID is %lu\n",i,(unsigned long)pthread_self());
    return NULL;
}
int main(){
    pthread_t t[N];
    int i;
    for(i=0;i<N;i++){
        int *p=malloc(sizeof(int));
        *p=i;
        pthread_create(&t[i],NULL,display,p);
    }
    for(i=0;i<N;i++)
        pthread_join(t[i],NULL);
    printf("pthread_equal(thread[0], thread[1]) = %d (%s)\n",
           pthread_equal(t[0],t[1]),
           pthread_equal(t[0],t[1])?"same thread":"different threads");
    printf("All %d threads have completed\n",N);
    return 0;
}
