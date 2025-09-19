#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: Hello World! PID = %d\n", getpid());
    } else {
        // Parent process
        printf("Parent Process: Hi! PID = %d\n", getpid());
    }

    return 0;
}

