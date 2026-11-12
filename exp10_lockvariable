#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
int main() {
    volatile int *s = mmap(NULL, 2*sizeof(int), PROT_READ|PROT_WRITE,
                           MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    s[0] = s[1] = 0; // lock, active processes
    for(int i=0; i<3; i++) {
        if(fork() == 0) {
            if(s[0] == 0) {
                usleep(100000); // expose race condition
                s[0] = 1;
                s[1]++;
                printf("Process %d entered CS, Active = %d\n", getpid(), s[1]);
                if(s[1] > 1) printf("ME VIOLATED!\n");
                usleep(200000);
                s[1]--;
                s[0] = 0;
            }
            _exit(0);
        }
    }
    while(wait(NULL) > 0);
    munmap((void *)s, 2*sizeof(int));
    return 0;
}
