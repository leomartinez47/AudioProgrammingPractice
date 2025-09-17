// FOR TRIANGLE 
//sample = 4 |ft - [ft + 1/2]| - 1  f = frequency (htz) t = time (secs)
//but apparently this will be less cpu taxing
// double t = index / sampleRate;
// double phase = fmod(frequency * t, 1.0);
// sample = 4.0 * amplitude * fabs(phase - 0.5) - amplitude;


// FOR SAW
// 2(ft%(1/f))f - 1  f = frequency (htz) t = time (secs)
//
//or sample[sampleindex] = (ampltitude) * (2((f * sampleindex/samplerate) % 1) - 1) 



// FOR SQUARE also this is where i figured out the phase thing 
// sample = AMPLITUDE * sgn(sin(2pi*f*t)) f = frequency (htz) t = time (secs)

//this phase stuff is cool and i think it makes the most sense for square waves
//by my understanding the phase is just a fraction of a wavelenght, so like 1/frequency
//then you increment the phase by frequency/sample rate and just make the sample value
//either AMPLITUDE or -AMPLITUDE based on wethere youre in the first half of the phase
//or the second
//so basically its just a period of the wave
//or an index inside of a period, where 0 is the start and 1 is the end of the period.
//ohhhhhhh yeah this is exactly what I thought a square wave would be so I guess im a genius.

//double phase = 0.0;
// double delta = frequency / sampleRate;

// for (int n = 0; n < bufferSize; ++n) {
//     double sample = (phase < 0.5 ? 1.0 : -1.0);  // square wave in [-1,1]

//     phase += delta;
//     if (phase >= 1.0) phase -= 1.0;

//     buffer[n] = sample;
//}

//for now im doing my way but imma consider the phase way if i ever wanna be more efficient and also lowk functional



/*
Leo Martinez
*/
#include "Waveform.h"
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

Waveform::Waveform(const char* waveform, double amplitude, double frequency, double sampleRate, double duration) : 
  amplitude(amplitude),
  frequency(frequency),
  sampleRate(sampleRate),
  duration(duration),
  sampleIndex(0),
  totalSamples(sampleRate * duration),
  sampleIncrement(1) {
    // creates a map to set a c style string mapped to a type of the Form enum
    std::map<string, Form> formMap = {
      {"sine", SINE},
      {"square", SQUARE},
      {"saw", SAW},
      {"triangle", TRIANGLE}
    };
    // sets the form member appropriately, this is assuming confirming a correct waveform input in main
    form = formMap[string(waveform)];
  }

double Waveform::currentSampleIndex() {
  return sampleIndex;
}

/// RETURN THE RIGHT CALCULATION BASED OFF OF FORM MEMBER
double Waveform::currentSampleValue() { 
  switch(form) {
    case SINE: // SINE WAVE - SAMPLE[INDEX] = AMPLITUDE * sin(2π * FREQUENCY * INDEX / SAMPLERATE)
      return amplitude*sin(((2*M_PI*frequency*sampleIndex)/sampleRate)); 
      break;
    case SQUARE: 
      // sample = AMPLITUDE * sgn(sin(2pi*f*t)) f = frequency (htz) t = time (secs)
      return amplitude*sign(sin(2*M_PI*frequency*sampleIndex/sampleRate));
      break;
    case SAW: 
      // sample[sampleindex] = (ampltitude) * (2((f * sampleindex/samplerate) % 1) - 1)
      return amplitude * (2 * (fmod(frequency * sampleIndex / sampleRate, 1.0)) - 1);
      break;
    case TRIANGLE:
      // sample = 4 |ft - [ft + 1/2]| - 1  f = frequency (htz) t = time (secs)
      // only ever returning 4 so the fabs shit must always be 1 for some reason
      return 4 * fabs(frequency * sampleIndex/sampleRate - (frequency * sampleIndex/sampleRate + 1/2) - 1); 
      break;
  }
  return 0;
}

double Waveform::getTotalSamples() {
  return totalSamples;
}

double Waveform::getDuration() {
  return duration;
}

Waveform& Waveform::operator++() {
  sampleIndex += sampleIncrement; 
  return *this; 
} 

Waveform Waveform::operator++(int) {
  Waveform result(*this);   //make a copy for the result using a reference to this sine curve
  ++(*this);  //use the prefix ++ to increment the current Sine
  return result;  //return the old version
} 

ostream& operator<<(std::ostream& output, Waveform wave) {
  output << wave.currentSampleIndex()/wave.getTotalSamples() << ", " << wave.currentSampleValue();
  return output;
}

int Waveform::sign(double val) {
  if(val > 0)
    return 1;
  else if(val < 0)
    return -1;
  else return 0;
}