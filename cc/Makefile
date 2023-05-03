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
	rvo_nrvo \
	rvo_nrvo_no \
	constructor \
	test \
	cpptest \

CFLAGS = -g -Wall -I.
CXXFLAGS = -g -std=c++17
LDFLAGS = -pthread -ldl

all: $(PROGRAMS)

stackOOB : stackOOB.cc
	$(CC) -O -g -fsanitize=address $^ -o $@ -lstdc++

rvo_nrvo_no : rvo_nrvo.cc
	$(CC) -O -g -fno-elide-constructors $^ -o $@ -lstdc++

clean:
	@rm -rf $(PROGRAMS) *.o *.dSYM
