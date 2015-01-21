

INCLUDES=-I../../libresistance/include 

OBJS=electrotest.o

all: $(OBJS)
	gcc $(INCLUDES) -o electrotest $(OBJS) -L../../libresistance/src/ -lresistance -Wl,-rpath=../../libresistance/src/

%.o: %.c
	gcc $(INCLUDES) -c $<

.PHONY: run
run: all
	./electrotest

./PHONY: clean
clean:
	rm -f electrotest *.o 
	echo $(ROOT_DIR)