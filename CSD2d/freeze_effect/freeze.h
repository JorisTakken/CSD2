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
		// Delay delay1(1000,73,0.9);
		delay1 = new Delay(1000,73,0.9);
};