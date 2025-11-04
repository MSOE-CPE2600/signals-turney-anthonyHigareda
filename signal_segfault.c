/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Anthony Higareda
 * 
 * Brief summary of modifications: Added a signal handler for a segmentation violation
 * When a SIGSEGV is sent out, the program reports that a violation happened, then returns
 * to the line where the violation occurs, only for the signal to be sent out again in 
 * an infinite loop
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_segfault()
{
    printf("Uh oh! A segmentation violation occured!\n");
}

int main (int argc, char* argv[]) {

    // Signal handler for a segmentation violation
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}