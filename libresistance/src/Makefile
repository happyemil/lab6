all: libresistance.c
	gcc -c -fPIC libresistance.c
	gcc -shared -fPIC -o libresistance.so libresistance.o

.PHONY: clean
clean:
	rm -f *.o *.so