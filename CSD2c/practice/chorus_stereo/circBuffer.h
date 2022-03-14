#pragma once
#include <iostream>

class CircBuffer{
	public:
		CircBuffer(int size, int numSamplesDelay);
		~CircBuffer();

		void setDelaySamps(float numSamplesDelay);
		void write(float sample);
		float read();

		

	private:
		int warp(int head);
		unsigned int readIndex;
		unsigned int writeIndex;
		unsigned int size;
		int numSamplesDelay;
		float* buffer = nullptr;

};