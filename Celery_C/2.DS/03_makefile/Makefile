OBJS=main.o tool1.o tool2.o
CXX=gcc
CFLAGS+=-c

mytool:$(OBJS)
	$(CXX) $^ -o $@

%.o:%.c
	$(CXX) $^ $(CFLAGS) -o $@

clean:
	$(RM) *.o mytool -r