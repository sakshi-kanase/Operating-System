#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
pid_t pid = fork();
if(pid<0){
perror("fork failed");
return 1;
}
if(pid == 0){
printf("child process: PID=%d,executing ls../n",getpid());
execl("/bin/ls","ls",NULL);
perror("execl failed");
return 1;
}else{
printf("parent process:PID = %d,going to sleep for 10 sec../n",getpid());
sleep(10);
printf("parent process:woke up and exiting.\n");
}
return 0;
}

