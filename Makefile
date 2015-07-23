
obj=bitNum delDigitals offsetof symmetry module.so module_test
all : $(obj)
bitNum : bitNum.c
delDigitals : delDigitals.c
offsetof : offsetof.c
symmetry : symmetry.c
module.so : module.c
	gcc -fPIC -shared -o module.so module.c
module_test : module_test.c
	gcc -o module_test module_test.c -ldl

.PRONY : clean
clean:
	rm -rf $(obj) *.o *.so
