#include <signal.h>
#include <unistd.h>
#include <stdio.h>

volatile int g_last_signal;

void sig_handler(int signum){
    g_last_signal = signum;
}

int main(void){

    signal(SIGINT, sig_handler);
    signal(SIGQUIT);
    signal(SIGTSTP);
    signal(SIGHUP);
    signal(SIG);

    while(1){
        pause();
        printf("Signal %d came\n", g_last_signal);
    }
    return 0;
}

// цель написать sigaction.
//маны которые нужно читать
