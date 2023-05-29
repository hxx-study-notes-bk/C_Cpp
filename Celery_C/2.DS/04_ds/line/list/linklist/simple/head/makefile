all:main

main:main.o list.o

%.o:%.c
	$(CC) $^ -c -o $@

clean:
	$(RM) *.o main -r