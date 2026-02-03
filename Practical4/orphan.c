#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        sleep(5);
        printf("Child Process\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }
    else {
        printf("Parent exiting...\n");
        sleep(2);
    }
    return 0;
}
