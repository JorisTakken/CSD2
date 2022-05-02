#pragma once
#include <iostream>
#include "delay.h"

class Freeze{
	public:
		Freeze();
		~Freeze();

        void processEffect(float &input, float &output);
		
	protected:
        // Delay(int size, int MSDelay, float feedback)
		Delay* delay1(44100,1000,0.9);


   		

};