CC=gcc
BINARY=bin
INCDIRS=-I.
CFILES=main.c sequence_gen.c avg_std_calculator.c
OBJECTS=main.o sequence_gen.o avg_std_calculator.o
OPT=-O0
CFLAGS=-WALL -Wextra -g $(INCDIRS) $(OPT)

all: $(BINARY)

$(BINARY): $(OBJECTS)
		$(CC) -o $@ $^

%.o:%.c
# $@ = whatever is on the left side of the colon
# $^ is whatever is on the right side of the colon
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm - rf $(BINARY) $(OBJECTS)