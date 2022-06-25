CC=gcc
BINARY=bin
INCDIRS=-I.
CFILES=main.c  process.c process_queue.c srtheap.c utils.c 
OBJECTS=main.o process.o process_queue.c srtheap.o utils.o
OPT=-O0
TXT=data.txt
CFLAGS=-WALL -Wextra -g $(INCDIRS) $(OPT)
CSV=uniformhist.csv normalhist.csv normalrandomhist.csv normaldistdividenormalrandom.csv specialDistributionHistogram.csv
all: $(BINARY)

$(BINARY): $(OBJECTS)
		$(CC) -o $@ $^

%.o:%.c
# $@ = whatever is on the left side of the colon
# $^ is whatever is on the right side of the colon
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm - rf $(BINARY) $(OBJECTS)