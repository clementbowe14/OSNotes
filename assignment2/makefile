CC=gcc
BINARY=bin first worst best next
FIRST=first
WORST=worst
BEST=best
NEXT=next
INCDIRS=-I.
CFILES=bestfit.c
OBJECTS=bestfit.o firstfit.o worstfit.o nextfit.o
OPT=-O0
TXT=data.txt
CFLAGS=-WALL -Wextra -g $(INCDIRS) $(OPT)

all: $(BINARY)

$(BINARY): $(OBJECTS)
		$(CC) -o $@ $^

%.o:%.c
# $@ = whatever is on the left side of the colon
# $^ is whatever is on the right side of the colon
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: firstfit
firstfit:
	$(CC) -o $(FIRST) firstfit.c

.PHONY: worstfit
worstfit:
	$(CC) -o $(WORST) worstfit.c

.PHONY: bestfit
bestfit:
	$(CC) -o $(BEST) bestfit.c

PHONY: nextfit
nextfit:
	$(CC) -o $(NEXT) nextfit.c

clean:
	rm -rf $(BINARY) $(OBJECTS)