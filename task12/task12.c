//задача ввывести как можно больше информации о текущем процессе!
//т.е. изучаем что вообще можно ввывести читаем про него и учим как это делать
//какие данные есть о процессе вообще?!
//id
//cat /proc/sceld/status
//cat /proc/sceld/stat 
//самому тож мовещь по искать ..


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void proc_info(const char *procname)
{
    printf(
            "%s: PID %d, PPID %d, PGID %d, SID %d\n",
            procname, getpid(), getppid(), getpgid(0), getsid(0)
    );
}

int main(int argc, char *argv[])
{
    pid_t child_id = fork();    //создает копию текущего процесса
    if (child_id < 0) {
        perror("fork");
        return 1;
    }
    if (child_id == 0) {
        // this code is executed in child process only
        proc_info("child");
        if (argc > 1) {
            printf("%d\n", 42 / atoi(argv[1]));
        }
        kill(getpid(), SIGTERM);
        return 42;
    }else {
        // this code is executed in parent process only
        proc_info("parent");
        int status;
    }
   
    return 0;
}