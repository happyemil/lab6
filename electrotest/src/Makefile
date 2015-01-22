INCLUDES=-I../../libresistance/include 

OBJS=electrotest.o

.PHONY: all clean run

all:
	cd ../../libresistance/src && $(MAKE) all MAKEFLAGS=
	$(MAKE) electrotest

electrotest: $(OBJS)
	gcc $(INCLUDES) -o electrotest $(OBJS) -L../../libresistance/src/ -lresistance -Wl,-rpath=../../libresistance/src/

%.o: %.c
	gcc $(INCLUDES) -c $<

run: all
	./electrotest

clean:
	rm -f electrotest *.o 
	cd ../../libresistance/src && $(MAKE) clean MAKEFLAGS=	