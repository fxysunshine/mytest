ifeq ($(shell uname -m), x86_64)
ARCH = -x86-64
endif

PROGRAMS = \
	bitNum \
	delDigitals \
	offsetof \
	symmetry \
	pointer \
	array_init \
	module.so \
	module_test \
	glibc_heap \
	heap_overlap \
	consolidate_forward \
	test_process_stack \
	random_stack \
	vuln \
	memory_profile \
	weak_symbol1 \
	weak_symbol2 \


CFLAGS = -g -Wall -I.
ifneq ($(PRIV_GLIBC),)
LDFLAGS = -L$(PRIV_GLIBC)/lib -Wl,--rpath=$(PRIV_GLIBC)/lib -Wl,--dynamic-linker=$(PRIV_GLIBC)/lib/ld-linux$(ARCH).so.2
endif
 
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

clean:
	rm -rf $(PROGRAMS) *.o
