ifeq ($(shell uname -m), x86_64)
ARCH = -x86-64
endif

PROGRAMS = \
	quick_sort \
	stackOOB \
	atomic \
	stack_safe \
	queue_safe \
	move \
	async \
	future \
	process_name \

CFLAGS = -g -Wall -I.
CXXFLAGS = -g -std=c++11
LDFLAGS = -pthread -ldl

all: $(PROGRAMS)

stackOOB : stackOOB.cc
	$(CC) -O -g -fsanitize=address $^ -o $@ -lstdc++

clean:
	@rm -rf $(PROGRAMS) *.o *.dSYM
