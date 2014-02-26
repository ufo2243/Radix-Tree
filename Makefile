CFLAGS:=-D_LARGEFILE64_SOURCE
ALLOBJECTS:=radix_tree_test
all : $(ALLOBJECTS)

SRCDIR = .
SRCS = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/*.c)
OBJS = $(addsuffix .o, $(basename $(SRCS)))



radix_tree_test : $(OBJS) 
	g++ -g $(CFLAGS) -Wall -o $@ $^ 

%.o : %.c
	gcc -c -g $(CFLAGS) -Wall -o $@ $<

%.o : %.cpp
	g++ -c -g $(CFLAGS) -Wall -o $@ $<

clean :
	rm -f $(ALLOBJECTS) *.o 

