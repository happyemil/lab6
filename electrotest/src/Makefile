# Targets:
#
# all
#     Rebuild libs if necessary, and link them locally to LOCALLY_LINKED_VERSION. 
#     NB, this is not exactly according to the specification, but we think this
#     is a better solution. electrotest is a test suite for the libs, so it shall
#     rebuild the libs if necessary, and it does build with the .so files, but it fetches
#     them directly from respective lib, not from a lib folder under electrotest.
#     Hope this is ok.
#
# lib
#     Rebuild all libs if necessary
#
# install_libs
#     Rebuilds all libs if necessary, and installs them in /usr/lib.
# 
# install
#     Runs the install_libs target, and then rebuilds electrocalc and installs it 
#     in /usr/bin.
# 
# electrotest_local
#     Builds electrotest_local, i.e. a program with locally linked libs taken from 
#     the folders at ../..
# 
# electrotest
#     A globally linked version. Libs must be in /usr/lib to run the program.
#
# run
#     Build electrotest_local and run it. 
#
# clean
#     Yep!
#

ROOT_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

INCLUDES=-I$(ROOT_DIR)/../../libresistance/include -I$(ROOT_DIR)/../../libcomponent/include 

OBJS=$(ROOT_DIR)/electrotest.o

LOCALLY_LINKED_VERSION=electrotest_local
GLOBALLY_LINKED_VERSION=electrotest


.PHONY: all clean run lib install_libs uninstall

all: lib $(LOCALLY_LINKED_VERSION)
#	cd $(ROOT_DIR) && $(MAKE) -f $(ROOT_DIR)/Makefile $(LOCALLY_LINKED_VERSION)

lib:
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) all MAKEFLAGS=
	cd $(ROOT_DIR)/../../libcomponent/src && $(MAKE) all MAKEFLAGS=
# Add more libs here

install_libs:
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) install MAKEFLAGS=
	cd $(ROOT_DIR)/../../libcomponent/src && $(MAKE) install MAKEFLAGS=

install: install_libs $(GLOBALLY_LINKED_VERSION)
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	cp $(GLOBALLY_LINKED_VERSION) /usr/bin

uninstall:
	@runner=`whoami` ; \
        if test $$runner != "root" ; \
        then \
                echo "ERROR: You are not root. Run 'sudo make $@'"; exit 1; \
        fi
	rm /usr/bin/$(GLOBALLY_LINKED_VERSION)

$(LOCALLY_LINKED_VERSION): $(OBJS)
	gcc $(INCLUDES) -o $(LOCALLY_LINKED_VERSION) $(OBJS) -L$(ROOT_DIR)/../../libresistance/src/ -lresistance -Wl,-rpath=$(ROOT_DIR)/../../libresistance/src/ -L$(ROOT_DIR)/../../libcomponent/src/ -llibcomponent -Wl,-rpath=$(ROOT_DIR)/../../libcomponent/src/

$(GLOBALLY_LINKED_VERSION): $(OBJS)
	gcc $(INCLUDES) -o $(GLOBALLY_LINKED_VERSION) $(OBJS) -lresistance -llibcomponent

%.o: %.c
	gcc $(INCLUDES) -c $<

run: all
	./$(LOCALLY_LINKED_VERSION)

clean:
	rm -f $(LOCALLY_LINKED_VERSION) $(GLOBALLY_LINKED_VERSION) *.o 
	cd $(ROOT_DIR)/../../libresistance/src && $(MAKE) clean MAKEFLAGS=
	cd $(ROOT_DIR)/../../libcomponent/src && $(MAKE) clean MAKEFLAGS=
