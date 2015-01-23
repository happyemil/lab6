CPATH = ../include

.Phony: all clean install runtest

all: libpower.so

libpower.o:libpower.c ../include/libpower.h 
	gcc -c -fPIC libpower.c

libpower.so: libpower.o
	gcc -shared -fPIC -o libpower.so libpower.o

install: libpower.so
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	cp libpower.so /usr/lib

uninstall:
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	rm /usr/lib/libpower.so

%.o: %.c
	gcc -c -I. $? 

clean:
	echo $(CPATH)
	rm -f *.o *.so
