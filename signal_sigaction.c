/**
 * File: signal_sigaction.c
 * Modified by: Anthony Higareda
 * 
 * Brief summary of program: Create a sigaction struct to process only SIGURS1
 * signals. Creates the sigaction, then enters an infinite loop to wait for a signal.
 * Upon receiving a SIGUSR1 signal, prints out the PID of this program.
 * To send SIGUSR1 to the process, run this program, then open a new terminal and issue $ps -a
 * Find the PID of this process, then issue $kill -SIGUSR1 <pid>
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigusr1()
{
    printf("PID: %d\n", getpid());
}

int main(int argc, char const *argv[])
{
    struct sigaction actor;
    actor.sa_handler = handle_sigusr1;
    sigfillset(&actor.sa_mask);
    sigaction(SIGUSR1, &actor, NULL);

    while (1) 
    {
        sleep(1);
    }
    return 0;
}

