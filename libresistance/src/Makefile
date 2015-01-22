.Phony: all clean

all: libresistance.so

%.o:%c 
	gcc -c -fPIC <&

libresistance.so: libresistance.o
	gcc -shared -fPIC -o libresistance.so libresistance.o

clean:
	rm -f *.o *.so