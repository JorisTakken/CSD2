SOURCE=instrument.o wind_instrument.o strings.o play_and_info.o main.o

instrumenten: $(SOURCE)
    c++ -o $@ $(SOURCE)

.cpp.o: 
    $(CXX) -c $<

clean: 
    rm instrumenten *.o




# c++ -c instrument.cpp
# c++ -c strings.cpp
# c++ -c wind_instrument.cpp
# c++ -c play_and_info.cpp
# c++ -c main.cpp

# c++ -o instrument.o wind_instrument.o strings.o play_and_info.o main.o