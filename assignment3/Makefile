OPTIMAL=optimal
FIFO=fifo
LRU=lru
SECOND=second
BINARY=fifo lru second optimal


.PHONY: optimal
optimal:
	$(CC) -o $(OPTIMAL) optimal.c

.PHONY: fifo
fifo:
	$(CC) -o $(FIFO) optimal.c

.PHONY: lru
lru:
	$(CC) -o $(LRU) optimal.c

.PHONY: second
second:
	$(CC) -o $(SECOND) optimal.c

clean:
	rm -rf $(BINARY)

