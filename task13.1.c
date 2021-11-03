#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

void proc_info(const char* procname)
{
printf("PID %d, PPID %d, PGID %d, SID %d\n", getpid(), getppid(), getpgid(0), getsid(0));
}

int main(int argc, char* argv[])
{
pid_t child_id = fork();
if(child_id < 0)
{
perror("fork");
return 1;
}

if(child_id == 0)
{
/* this code is executed in child process only */
proc_info("child");
if(argc > 1)
printf("%d\n", 42 / atoi(argv[1]));

kill(getpid(), SIGTERM);
return 42;
}
else
{
/* this code is executed in parent process only */
proc_info("parent");
int status;
pid_t res = wait(&status); //заменить на waitpid и обработку усыпления и пробуждения
if(WIFEXITED(status))
{
printf("child with PID = %d has exited normally with code %d\n", res, WEXITSTATUS(status));
}
else if(WIFSIGNALED(status))
{
int child_signal = WTERMSIG(status);
printf("child with PID = %d was killed by signal %d (%s)\n", res, child_signal, strsignal(child_signal));
}
else
printf("child with PID = %d has exited with termination status %d\n", res, status);
}
return 0;
}