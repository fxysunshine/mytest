
obj=bitNum delDigitals offsetof symmetry
all : $(obj)
bitNum : bitNum.c
delDigitals : delDigitals.c
offsetof : offsetof.c
symmetry : symmetry.c

clean:
	rm -rf $(obj) *.o
