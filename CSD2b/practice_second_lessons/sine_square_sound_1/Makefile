CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE=square.o sine.o oscillator.o main.o 
TARGET=synth

$(TARGET): $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f $(TARGET) *.o 
