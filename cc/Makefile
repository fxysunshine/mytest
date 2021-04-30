ifeq ($(shell uname -m), x86_64)
ARCH = -x86-64
endif

PROGRAMS = \
	quick_sort \
	stackOOB \

CFLAGS = -g -Wall -I.
CXXFLAGS = -g -std=c++11
LDFLAGS = -lpthread -ldl

all: $(PROGRAMS)

stackOOB : stackOOB.cc
	$(CC) -O -g -fsanitize=address $^ -o $@ -lstdc++

clean:
	@rm -rf $(PROGRAMS) *.o *.dSYM
