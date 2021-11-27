#! /bin/bash

c++ -c oscillator.cpp
c++ -c main_oscillator.cpp
c++ -o oscillator main_oscillator.o oscillator.o

