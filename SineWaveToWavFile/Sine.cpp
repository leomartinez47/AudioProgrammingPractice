/*
Leo Martinez, 
CS3505, Assignment 2, Making a class.
*/
#include "Sine.h"
#include <iostream>
#include <cmath>

using namespace std;

Sine::Sine(double amplitude, double frequency, double sampleRate, double duration) : 
  amplitude(amplitude),
  frequency(frequency),
  sampleRate(sampleRate),
  duration(duration),
  sampleIndex(0),
  totalSamples(sampleRate * duration),
  sampleIncrement(1 / (sampleRate * duration)) {}

double Sine::currentSampleIndex() {
  return sampleIndex;
}

double Sine::currentSampleValue() {
  return amplitude*sin(((2*M_PI*frequency*sampleIndex)/sampleRate)); //SAMPLE = AMPLITUDE * sin(2π * FREQUENCY * INDEX / SAMPLERATE)
}

double Sine::getTotalSamples() {
  return totalSamples;
}

Sine& Sine::operator++() {
  sampleIndex += sampleIncrement; 
  return *this; 
} 

Sine Sine::operator++(int) {
  Sine result(*this);   //make a copy for the result using a reference to this sine curve
  ++(*this);  //use the prefix ++ to increment the current Sine
  return result;  //return the old version
} 

ostream& operator<<(std::ostream& output, Sine sineCurve) {
  output << sineCurve.currentSampleIndex() << ", " << sineCurve.currentSampleValue();
  return output;
}