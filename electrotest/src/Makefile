ROOT_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

INCLUDES=-I$(ROOT_DIR)/../../libresistance/include 

OBJS=$(ROOT_DIR)/electrotest.o
LIBS=$(ROOT_DIR)/../../libresistance/src/libresistance.so

.PHONY: all clean run lib

all: lib
	cd $(ROOT_DIR) && $(MAKE) -f $(ROOT_DIR)/Makefile electrotest

lib:
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) all MAKEFLAGS=
# Add more libs here

electrotest: $(OBJS) $(LIBS)
	gcc $(INCLUDES) -o $(ROOT_DIR)/electrotest $(OBJS) -L$(ROOT_DIR)/../../libresistance/src/ -lresistance -Wl,-rpath=$(ROOT_DIR)/../../libresistance/src/

%.o: %.c
	gcc $(INCLUDES) -c $<

run: all
	./electrotest

clean:
	rm -f electrotest *.o 
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) clean MAKEFLAGS=
	echo $(ROOT_DIR)	