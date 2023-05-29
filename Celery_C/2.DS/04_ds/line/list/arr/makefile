all:main

main:main.o sqlist.o

%.o:%.c
	$(CC) $^ -c -o $@

clean:
	$(RM) *.o main -r