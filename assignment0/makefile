CC=gcc
BINARY=bin
INCDIRS=-I.
CFILES=main.c sequence_gen.c avg_std_calculator.c histogram.c
OBJECTS=main.o sequence_gen.o avg_std_calculator.o histogram.o
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
	rm - rf $(BINARY) $(OBJECTS) $(TXT) $(CSV)