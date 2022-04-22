#pragma once
#include <iostream>

class Circ{
	public:
		Circ(int size, int numSamplesDelay);
		~Circ();

		void setDelaySamps(float numSamplesDelay);
		void write(float sample);
		float read();

	private:
		int wrap(int head);
		unsigned int readIndex;
		unsigned int writeIndex;
		unsigned int size;
		int numSamplesDelay;
		float* buffer = nullptr;

};