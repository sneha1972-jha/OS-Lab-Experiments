#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
int main() {
    volatile int *lock = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE,
                              MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    *lock = 0;
    for(int i=0; i<3; i++) {
        if(fork() == 0) {
            while(__sync_lock_test_and_set(lock, 1));
            printf("Process %d entered CS\n", getpid());
            sleep(1);
            printf("Process %d exited CS\n", getpid());
            __sync_lock_release(lock);
            _exit(0);
        }
    }
    while(wait(NULL) > 0);
    munmap((void *)lock, sizeof(int));
    return 0;
}
