#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int i;
    for(i=0;i<3;i++)
        fork();
    printf("Process ID: %d, Parent ID: %d\n",getpid(),getppid());
    return 0;
}
