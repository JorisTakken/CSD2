#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth(){
}

FM_synth::~FM_synth(){
}



void FM_synth::initialize(std::string waveform[],float frequency[], int input_number_oscs){
    this->carrierFreq = frequency[0];
    this->modulatorFreq = frequency[1];

    if (waveform[0] == "sine"){
        carrier = new Sine;
        }
    else if (waveform[0] == "saw"){
        carrier = new Saw;
        }
    else if (waveform[0] == "square"){
        carrier = new Square;
        }

    if (waveform[1] == "sine"){
        modulator = new Sine;
        }
    else if (waveform[1] == "saw"){
        modulator = new Saw;
        }
    else if (waveform[1] == "square"){
        modulator = new Square;
        }

    carrier->initialize(carrierFreq,1,SAMPLERATE);
    modulator->initialize(modulatorFreq,1,SAMPLERATE);
}

void FM_synth::setCarrierFrequency(float newFreq){
    carrier->setFrequency(newFreq);   
}

float FM_synth::getCarrierFrequency(){
    float carrierFreq = carrier->getFrequency();
    return carrierFreq;
}


void FM_synth::setModulationIndex(){
    this->modulationIndex = (1.056 * modulator->getFrequency()) * 7.0;
}

float FM_synth::getModulationIndex(){
    return modulationIndex
}



void FM_synth::calculateCarrierFreq(){
    carrierFreq = modulator->getFrequency() + (modulator->tick() * getModulationIndex());

}

void FM_synth::calculate(){ 
    sample = carrier->getSample() + (7 * modulator->getSample());
    carrier->tick();
    modulator->tick();
}

float FM_synth::getSample(){
    return sample;
}



void FM_synth::write_waveform(){   
    float ModulationIndex = (1.07 * modulator->getFrequency()) * 5; 

    std::cout << ModulationIndex << std::endl;

    WriteToFile file("1_fm_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        float frequency = carrier->getFrequency() + (modulator->getSample() * (1.07 * modulator->getFrequency()));
        samp = frequency;

        file.write(std::to_string(samp) + "\n");
        carrier->tick();
        modulator->tick();
    }
}



void Fmsynth::calculateCarrierFreq(){
  //modulation index = (ratio * oscFreq) * x   (1 <= x >= 0.0)
  //(mod * modulation index) + (carFreq)
}


// double Fmsynth::tick(){
//   calculateCarrierFreq();
//   return car->tick();
// }


// //heb zelf geen ADSR dr in maar een statische waarde _ experimenteer dr mee, kijk wat voor boventonen je krijgt ;) 
// ModulationIndex = (ratio * Frequency) * ADSR 
// modulatorFreq = Frequency * Ratio
// carrierFreq = Frequency + (outputModulator * Modulation Index)

