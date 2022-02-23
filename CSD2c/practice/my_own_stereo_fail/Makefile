# Makefile for ringbuffer
#
CPP = g++ --std=c++11
CFLAGS = -Wall
LDFLAGS= -lpthread -ljack

JACKOBJ = ringbuffer.o jack_module.o jack_test.o
FXOBJ = ringbuffer.o jack_module.o keypress.o
RINGBUFOBJ = ringbuffer.o ringbuffer_test.o
HOPOBJ = hopbuffer.o hopbuffer_test.o
ATOMICOBJ = atomic_test.o

all: ringbuffer_test jack_test panning \


jack_test: $(JACKOBJ)
	$(CPP) -o $@ $(CFLAGS) $(JACKOBJ) $(LDFLAGS)

chorus_main: $(FXOBJ) chorus_main.o
	$(CPP) -o $@ $(CFLAGS) $(FXOBJ) chorus_main.o $(LDFLAGS)

ringbuffer_test: $(RINGBUFOBJ)
	$(CPP) -o $@ $(CFLAGS) $(RINGBUFOBJ) $(LDFLAGS)

.cpp.o:
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm /111 -type f`

