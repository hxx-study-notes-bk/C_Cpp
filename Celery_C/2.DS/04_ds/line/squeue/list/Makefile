all:queue

queue:queue.o list.o main.o
	$(CC) $^ -o $@

clean:
	rm queue *.o -rf