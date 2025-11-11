/**
 * File: recv_signal.c
 * Modified by: Anthony Higareda
 * 
 * Brief summary of program: Register a sigaction to handle a SIGUSR1 signal.
 * The received signal will have a sival_int value that will be printed
 * upon receiving a signal from send_signal.c
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigusr1(int signo, siginfo_t *info, void *context)
{
    printf("Signal received: %d\n", info -> si_value.sival_int);
}

int main(int argc, char const *argv[])
{
    struct sigaction receiver;
    

    
    receiver.sa_sigaction = handle_sigusr1;
    receiver.sa_flags = SA_SIGINFO;
    sigemptyset(&receiver.sa_mask);

    sigaction(SIGUSR1, &receiver, NULL);

    while (1) 
    {
        pause();
    }
    return 0;
}