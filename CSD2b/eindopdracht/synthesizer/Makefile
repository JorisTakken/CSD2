CXX= g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE=jack_module.o ui_input.o 1_writeToFile.o wavetable.o square.o saw.o sine.o oscillator.o main2.o
TARGET=synth

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CFLAGS)

clean:
	rm -f $(TARGET) *.o