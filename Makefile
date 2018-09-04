CC=gcc
CFLAGS=-lncurses
DEBUGFLAGS=-g -D DEBUG
HEADERS=concentration.h
SOURCES=main.c windows.c other.c

concentration: $(SOURCES) $(HEADERS)
	$(CC) -Wall -o concentration $(SOURCES) $(HEADERS) $(CFLAGS)

debug: $(SOURCES) $(HEADERS)
	$(CC) -Wall -o concentration $(SOURCES) $(HEADERS) $(CFLAGS) $(DEBUGFLAGS)

install: concentration
	mv ./concentration /usr/local/bin/