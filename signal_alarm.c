/**
 * File: signal_alarm.c
 * Modified by: Anthony Higareda
 * 
 * Brief summary of program: Set up an alarm signal handler.
 * The handler reports that the signal was received and exits.
 * Set the alarm for 5 seconds, then enter an infinite while loop
 * that prints "Waiting....." as fast as the program is able to.
 * Once the alarm signal is sent, the program will exit
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_alarm()
{
    printf("Alarm received!\n");
    exit(0);
}

int main(int argc, char const *argv[])
{

    signal(SIGALRM, handle_alarm);

    int seconds = 5;

    alarm(seconds);

    printf("Waiting for an alarm...\n");
    while (1)
    {
        printf("Waiting.......\n");
        
    }
    
    return 0;
}
 