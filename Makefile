
SRCS = bitNum.c delDigitals.c offsetof.c symmetry.c pointer.c
OBJS = $(patsubst %.c, %, $(SRCS))
TARGET = $(OBJS) module.so module_test

CC = gcc
CFLAGS = -g -Wall -I.
LIBS = -ldl

all : $(TARGET)
$(OBJS) : % : %.c
	$(CC) $(CFLAGS) $^ -o $@

module.so : module.c
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@
module_test : module_test.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

.PRONY : clean
clean:
	rm -rf $(TARGET) *.o
