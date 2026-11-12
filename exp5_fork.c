#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
    int n=fork();
    if(n<0){
        perror("Fork failed");
        exit(1);
    }
    printf("Process ID: %d and value of n = %d\n",getpid(),n);
    fflush(stdout);
    if(n==0){
        execlp("ls","ls",NULL);
        perror("execlp failed");
        exit(1);
    }
    else{
        wait(NULL);
        printf("Child completed\n");
    }
    return 0;
}
