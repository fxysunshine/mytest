CC=clang
CXX=clang++
export CC CXX

SUBDIRS=cc c

default:
	for dir in $(SUBDIRS);\
	  do make -C $$dir || exit 1;\
	done

clean:
	for dir in $(SUBDIRS);\
	  do make -C $$dir clean || exit 1;\
	done
	rm -rf build
