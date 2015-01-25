CPATH = ../include

.Phony: all clean install

all: libcomponent.so

libcomponent.o:libcomponent.c ../include/libcomponent.h 
	gcc -g -c -fPIC libcomponent.c

libcomponent.so: libcomponent.o
	gcc -g -shared -fPIC -o libcomponent.so libcomponent.o

install: libcomponent.so
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	cp libcomponent.so /usr/lib

uninstall:
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	rm /usr/lib/libcomponent.so

%.o: %.c
	gcc -g -c -I. $? 

clean:
	echo $(CPATH)
	rm -f *.o *.so
