CC = gcc
CFLAGS = -g -lm -Wall -std=c99
OBJECTS = scatter_new.o
all : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o scatter_new


scatter_new: .c
	$(CC) $(CFLAGS) -c scatter_new.c

.PHONY : clean
clean :
	-rm edit $(OBJECTS)
