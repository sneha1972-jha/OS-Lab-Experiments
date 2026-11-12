#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* factorial(void* arg){
    int n=*(int*)arg;
    free(arg);
    int *res=malloc(sizeof(int));
    *res=1;
    for(int i=1;i<=n;i++)
        *res*=i;
    pthread_exit(res);
}
int main(){
    pthread_t t[5];
    int i,*arg,*result;
    for(i=0;i<5;i++){
        arg=malloc(sizeof(int));
        *arg=i+1;
        pthread_create(&t[i],NULL,factorial,arg);
    }
    for(i=0;i<5;i++){
        pthread_join(t[i],(void**)&result);
        printf("Thread for n=%d computed factorial = %d\n",i+1,*result);
        free(result);
    }
    printf("All threads have returned their results\n");
    return 0;
}
