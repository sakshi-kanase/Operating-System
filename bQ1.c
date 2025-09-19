#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        sleep(5);  
        printf("Child process PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
      printf("Parent process PID: %d exiting\n", getpid()); 
    }

    return 0;
    }
