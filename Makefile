CC=gcc
CFLAGS=-c -g -Wall -Werror

all: signal_handler signal_alarm

signal_handler: signal_handler.o
	$(CC) -o handler signal_handler.o

signal_alarm: signal_alarm.o
	$(CC) -o alarm signal_alarm.o

clean:
	rm -f *.o signal_handler signal_alarm

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<