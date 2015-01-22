.Phony: all clean install

all: libresistance.so

libresistance.o:libresistance.c ../include/resistance.h 
	gcc -c -fPIC libresistance.c

libresistance.so: libresistance.o
	gcc -shared -fPIC -o libresistance.so libresistance.o

install: libresistance.so
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	cp libresistance.so /usr/lib

uninstall:
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	rm /usr/lib/libresistance.so

clean:
	rm -f *.o *.so