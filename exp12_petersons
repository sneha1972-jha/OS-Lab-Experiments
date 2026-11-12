#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <unistd.h>
atomic_int interested[2]={0},turn;
int shareData=0,count=0;
void entry(int p){
    int q=1-p;
    interested[p]=1; turn=p;
    while(interested[q] && turn==p);
}
void exit_section(int p){
    interested[p]=0;
}
void *critical_section(void *arg){
    int id=*(int*)arg;
    while(1){
        entry(id);
        if(count>10){exit_section(id);break;}
        printf("Thread %d enter CS, shareData=%d\n",id,shareData);
        usleep(100000);
        shareData++; count++;
        printf("Thread %d exit CS, shareData=%d\n",id,shareData);
        exit_section(id);
    }
    return NULL;
}
int main(){
    pthread_t t[2]; int id[]={0,1};
    for(int i=0;i<2;i++) pthread_create(&t[i],NULL,critical_section,&id[i]);
    for(int i=0;i<2;i++) pthread_join(t[i],NULL);
    printf("Final shareData=%d\n",shareData);
}
