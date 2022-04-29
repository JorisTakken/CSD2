#pragma once
#include <iostream>

class Rec{
	public:
		Rec(int size, int numSamplesDelay);
		~Rec();

		void setDelaySamps(float numSamplesDelay);
		void write(float sample, bool recordNow);
		float read();

	private:
		int wrap(int head);
		unsigned int readIndex;
		unsigned int writeIndex;
		unsigned int size;
		int numSamplesDelay;
		float* buffer = nullptr;

};