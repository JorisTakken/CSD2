#! /bin/bash

c++ -c drMartens.cpp
c++ -c shoes.cpp 
c++ -c main.cpp 


c++ -o shoes drMartens.o shoes.o main.o



