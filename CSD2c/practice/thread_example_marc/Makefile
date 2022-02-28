# Makefile for thread examples with C++ 11
#
CPP = g++ --std=c++11
CFLAGS = -Wall
LDFLAGS = -lpthread

MSGQOBJ = msgqueue.o


# all: msgqueue

# threads: $(OBJ)
#     $(CPP) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS)

# needs_mutex: $(NEEDSMUTEXOBJ)
#     $(CPP) -o $@ $(CFLAGS) $(NEEDSMUTEXOBJ) $(LDFLAGS)

# simplemutex: $(SMUTEXOBJ)
#     $(CPP) -o $@ $(CFLAGS) $(SMUTEXOBJ) $(LDFLAGS)

# simple_try_lock: $(TRYLOCKOBJ)
#     $(CPP) -o $@ $(CFLAGS) $(TRYLOCKOBJ) $(LDFLAGS)

msgqueue: $(MSGQOBJ)
	$(CPP) -o $@ $(CFLAGS) $(MSGQOBJ) $(LDFLAGS)

.cpp.o:
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm /111 -type f`