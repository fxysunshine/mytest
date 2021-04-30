ifeq ($(shell uname -m), x86_64)
ARCH = -x86-64
endif

PROGRAMS = \
	bitNum \
	delDigitals \
	offsetof \
	symmetry \
	pointer \
	consolidate_forward \
	vuln \
	memory_profile \
	glibc_heap \
	heap_overlap \
	test_process_stack \
	random_stack \
	weak_symbol1 \
	weak_symbol2 \
	module.so \
	module_test \

ifneq ($(filter $(shell uname -m), i686 i386),)
PROGRAMS += \
	helloworld
endif

CFLAGS = -g -Wall -I.
 
all: $(PROGRAMS)

module.so : module.c
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@
module_test : module_test.c
	$(CC) $(CFLAGS) $^ -o $@ -ldl
glibc_heap : glibc_heap.c
	$(CC) $(CFLAGS) $^ -o $@ -ldl -lpthread
weak_symbol1 : weak_symbol.c
	$(CC) $(CFLAGS) $^ -o $@ -ldl
weak_symbol2 : weak_symbol.c
	$(CC) $(CFLAGS) $^ -o $@ -ldl -lpthread
helloworld.o : helloworld.c
	$(CC) -c -fno-builtin $^ -o $@
helloworld : helloworld.o
	ld -static -e nomain $^ -o $@

clean:
	rm -rf $(PROGRAMS) *.o
