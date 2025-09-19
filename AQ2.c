#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <exec_type>\n", argv[0]);
        printf("exec_type: execl, execv, execvp\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child PID=%d, Parent PID=%d\n", getpid(), getppid());

        if (strcmp(argv[1], "execl") == 0) {
            execl("/bin/ls", "ls", "-l", NULL);
            perror("execl failed");
        } else if (strcmp(argv[1], "execv") == 0) {
            char *args[] = {"/bin/ls", "-l", NULL};
            execv("/bin/ls", args);
            perror("execv failed");
        } else if (strcmp(argv[1], "execvp") == 0) {
            char *args[] = {"ls", "-l", NULL};
            execvp("ls", args);
            perror("execvp failed");
        } else {
            printf("Unknown exec type\n");
            return 1;
        }
        return 1;  // exec failed
    } else {
        // Parent process
        printf("Parent PID=%d, Child PID=%d\n", getpid(), pid);
        wait(NULL);
        printf("Parent: Child finished. Control back to parent.\n");
    }
    return 0;
}

