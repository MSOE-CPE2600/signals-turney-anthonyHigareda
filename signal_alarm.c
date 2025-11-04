/**
 * File: signal_alarm.c
 * Modified by: Anthony Higareda
 * 
 * Brief summary of program:
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
 