CXX= g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= 
SOURCE=saw.o sine.o square.o oscillator.o writeToFile.o main.o
TARGET=synth

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CFLAGS)

clean:
	rm -f $(TARGET) *.o