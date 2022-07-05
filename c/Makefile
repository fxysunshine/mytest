ifeq ($(shell uname -m), x86_64)
ARCH = -x86-64
endif

PROGRAMS = \
	bitNum \
	delDigitals \
	offsetof \
	symmetry \
	consolidate_forward \
	vuln \
	memory_profile \
	glibc_heap \
	heap_overlap \
	test_process_stack \
	weak_symbol1 \
	weak_symbol2 \
	module.so \
	module_test \

ifeq ($(shell uname -s), Linux)
PROGRAMS += \
	cursor \
	seat \
	pointer \
	keyboard \
	client \
	uinput \
	egl_display \

endif

ifneq ($(filter $(shell uname -m), i686 i386),)
PROGRAMS += \
	helloworld \
	x11_window \

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
x11_window : x11_window.c
	$(CC) $(CFLAGS) $^ -o $@ -lX11
cursor : cursor.c
	$(CC) $(CFLAGS) $^ -o $@ -lEGL -lGLESv2 -lwayland-client -lwayland-cursor -lwayland-egl
seat : seat.c
	$(CC) $(CFLAGS) $^ -o $@ -lwayland-client
pointer: pointer.c
	$(CC) $(CFLAGS) $^ -o $@ -lEGL -lGLESv2 -lwayland-client -lwayland-egl
keyboard : keyboard.c
	$(CC) $(CFLAGS) $^ -o $@ -lEGL -lGLESv2 -lwayland-client -lwayland-egl
client : client.c xdg-shell-protocol.c
	$(CC) $(CFLAGS) $^ -o $@ -lwayland-client -lrt
egl_display: egl_display.c
	$(CC) $(CFLAGS) $^ -o $@ -lEGL -lGLESv2

clean:
	@rm -rf $(PROGRAMS) *.o *.dSYM
