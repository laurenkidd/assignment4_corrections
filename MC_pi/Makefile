CC = gcc
CFLAGS = -g -lm -Wall -std=c99
OBJECTS = MC_pi_new.o
all : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o MC_pi_new


MC_pi_new: .c
	$(CC) $(CFLAGS) -c MC_pi_new.c

.PHONY : clean
clean :
	-rm edit $(OBJECTS)
