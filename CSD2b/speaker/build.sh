#! /bin/bash

c++ -c speaker.cpp
c++ -c speaker_main.cpp
c++ -c woofer.cpp
c++ -c tweeter.cpp

c++ -o speaker speaker_main.o speaker.o woofer.o tweeter.o 


