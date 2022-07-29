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
	$(CC) -o $(FIFO) fifo.c

.PHONY: lru
lru:
	$(CC) -o $(LRU) lru.c

.PHONY: second
second:
	$(CC) -o $(SECOND) second.c

clean:
	rm -rf $(BINARY)

