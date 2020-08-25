ifeq ($(shell uname -m), x86_64)
ARCH = -x86-64
endif

PROGRAMS = \
	stdtest \
	add \
	add2 \
	wordrevert \
	sort \
	sort2 \
	mystring \
	fallocate_header \
	abs \
	binary_search \
	quick_sort \
	find_sum \
	bfs \
	dfs \
	getNumUpNK \
	topK \
	delnodeN \
	sum \
	link_sort \
	lru \
	treeMirror \
	link_reverse \
	get_median \
	yh \
	get_file_list \
	queue \

ifneq ($(filter $(shell uname -m), i686 i386),)
PROGRAMS += \
	helloworld
endif

ifneq ($(filter $(shell uname -s), Linux),)
PROGRAMS += \
	prime \
	direct_io \
	deletefiles \
	mem_test \
	mem_test2 \
#	stackOOB
endif

CFLAGS = -g -Wall -I.
CXXFLAGS = -g -std=c++11
LDFLAGS = -lpthread -ldl
ifneq ($(PRIV_GLIBC),)
LDFLAGS = -L$(PRIV_GLIBC)/lib -Wl,--rpath=$(PRIV_GLIBC)/lib -Wl,--dynamic-linker=$(PRIV_GLIBC)/lib/ld-linux$(ARCH).so.2
endif

all: $(PROGRAMS)

stackOOB : stackOOB.cc
	$(CC) -O -g -fsanitize=address $^ -o $@ -lstdc++

clean:
	@rm -rf $(PROGRAMS) *.o *.dSYM
