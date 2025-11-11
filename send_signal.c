/**
 * File: send_signal.c
 * Modified by: Anthony Higareda
 * 
 * Brief summary of program: Using sigqueue, send a SIGUSR1 to recv_signal with
 * and integer stored to sival_int. Gets the PID of recv_signal from command line upon
 * invoking the program
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{

    pid_t recv_pid;
    recv_pid = atoi(argv[1]);
    srand(time(NULL));
    int data = rand() % 100;

    union sigval value;
    value.sival_int = data;

    sigqueue(recv_pid, SIGUSR1, value);
    printf("Random number sent: %d\n", value.sival_int);
    return 0;
}