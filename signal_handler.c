/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Anthony Higareda
 * 
 * Brief summary of modifications: Added an integer variable that is incremented every second
 * Every 5 seconds, we will send a SIGINT
 * To completely exit this program, it must first be suspended (Ctrl + Z).
 * Next issue ~$ps and find the pid of this program
 * Finally, issue ~$kill -SIGKILL <pid>
 *  replacing <pid> with the pid of this program.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    // exit(1);
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    int killer = 1; // Control variable for intermittent signal sending

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        if (killer % 5 == 0) // Every 5 seconds we will send a signal
        {
            kill(getpid(), SIGINT);
        }
        killer++;
        sleep(1);
    }

    return 0;
}