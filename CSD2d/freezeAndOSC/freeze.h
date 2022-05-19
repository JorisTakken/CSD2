#pragma once
#include <iostream>
#include "delay.h"

class Freeze{
	public:
		Freeze();
		~Freeze();

        void applyEffect(float &input, float &output);
		
	protected:
			// delay1 = 73ms - 3219 samps
			// delay2 = 100ms = 4410 samps
			// delay3 = 121ms = 5336 ssamps
		Effect* delay1 = new Delay(44100,3219,0.9);
		Effect* delay2 = new Delay(44100,4410,0.9);
		Effect* delay3 = new Delay(44100,5336,0.9);
		Effect* delay4 = new Delay(44100,6736,0.9);


		float output1;
		float output2;
		float output3;
		float output4;



};