all: electrotest.o
	gcc -o electrotest electrotest.c -L. -lresistance -Wl,-rpath='../../libresistance/src/'
#	gcc -o electrotest electrotest.o

.PHONY: run
run: all
	./electrotest

./PHONY: clean
clean:
	rm -f electrotest *.o