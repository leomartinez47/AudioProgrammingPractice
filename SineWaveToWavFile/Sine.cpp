/*
Leo Martinez, 
CS3505, Assignment 2, Making a class.
*/
#include "Sine.h"
#include <iostream>
#include <cmath>

using namespace std;

Sine::Sine(double amplitude, double wavelength, double angleIncrement) : 
  amplitude(amplitude),
  wavelength(wavelength),
  angleIncrement(angleIncrement),
  angle(0) {}

double Sine::currentAngle() {
  return angle;
}

double Sine::currentHeight() {
  return amplitude*sin(((2*M_PI*angle)/wavelength)); //HEIGHT = AMPLITUDE * sin((2piANGLE)/WAVELENGTH)

}

Sine& Sine::operator++() {
  angle += angleIncrement; 
  return *this; 
} 

Sine Sine::operator++(int) {
  Sine result(*this);   //make a copy for the result using a reference to this sine curve
  ++(*this);  //use the prefix ++ to increment the current Sine
  return result;  //return the old version
} 

ostream& operator<<(std::ostream& output, Sine sineCurve) {
  output << sineCurve.currentAngle() << ", " << sineCurve.currentHeight();
  return output;
}