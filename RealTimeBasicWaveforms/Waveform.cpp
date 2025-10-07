/* Leo Martinez */
#include "Waveform.h"
#include <iostream>
#include <map>
#define _USE_MATH_DEFINES
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
      // the wikipedia definition of a triangle wave, where period = samplerate/frequency
      double period = sampleRate / frequency;
      double phase = fmod(sampleIndex / period + 0.75, 1.0);
      return 4 * amplitude * fabs(phase - 0.5) - amplitude;
      //return (4 * amplitude / (sampleRate / frequency)) * fabs(fmod(sampleIndex - (sampleRate / frequency * 4), sampleRate / frequency) - sampleRate / 2 * frequency) - amplitude;
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

float Waveform::nextSample() {
  float value = currentSampleValue();
  ++(*this);
  return value;
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