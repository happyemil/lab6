.Phony: all clean

all: libresistance.so

libresistance.o:libresistance.c ../include/resistance.h 
	gcc -c -fPIC libresistance.c

libresistance.so: libresistance.o
	gcc -shared -fPIC -o libresistance.so libresistance.o

clean:
	rm -f *.o *.so