ROOT_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

INCLUDES=-I$(ROOT_DIR)/../../libresistance/include 

OBJS=$(ROOT_DIR)/electrotest.o
LOCAL_LIBS=$(ROOT_DIR)/../../libresistance/src/libresistance.so
# Add more libs here

LOCALLY_LINKED_VERSION=$(ROOT_DIR)/electrotest_local
GLOBALLY_LINKED_VERSION=$(ROOT_DIR)/electrotest


.PHONY: all clean run lib install_libs

all: lib $(LOCALLY_LINKED_VERSION)
#	cd $(ROOT_DIR) && $(MAKE) -f $(ROOT_DIR)/Makefile $(LOCALLY_LINKED_VERSION)

lib:
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) all MAKEFLAGS=
# Add more libs here

install_libs:
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) install MAKEFLAGS=

install: install_libs $(GLOBALLY_LINKED_VERSION)
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	cp $(GLOBALLY_LINKED_VERSION) /usr/bin

$(LOCALLY_LINKED_VERSION): $(OBJS) $(LOCAL_LIBS)
	gcc $(INCLUDES) -o $(LOCALLY_LINKED_VERSION) $(OBJS) -L$(ROOT_DIR)/../../libresistance/src/ -lresistance -Wl,-rpath=$(ROOT_DIR)/../../libresistance/src/

$(GLOBALLY_LINKED_VERSION): $(OBJS)
	gcc $(INCLUDES) -o $(GLOBALLY_LINKED_VERSION) $(OBJS) -lresistance

%.o: %.c
	gcc $(INCLUDES) -c $<

run: all
	$(LOCALLY_LINKED_VERSION)

clean:
	rm -f $(LOCALLY_LINKED_VERSION) *.o 
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) clean MAKEFLAGS=
