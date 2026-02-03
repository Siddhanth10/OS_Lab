#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child exiting...\n");
    }
    else {
        sleep(10);
        printf("Parent still running...\n");
    }
    return 0;
}
