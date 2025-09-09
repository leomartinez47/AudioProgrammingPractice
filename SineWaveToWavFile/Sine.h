/*
Leo Martinez, 
CS3505, Assignment 2, Making a class.
*/
#ifndef SINE_H
#define SINE_H
#include <iostream>

/// @brief A Sine object represents a sine curve with an amplitude, a wavlength,
///        a current angle position in degrees, and an angle increment value. Sine Objects begin
///        at angle 0 and the angle is incremented by the angleIncrement using the ++ operator
///        in either a prefix or postfix manner.
class Sine {

  /// The amplitude, wavelength, angleIncrement, and angle variables for this sine curve.
  double amplitude, wavelength, angleIncrement, angle;

public:
  /// @brief Constructs a Sine object with an angle of 0.
  /// @param amplitude the amplitude of this sine curve.
  /// @param wavelength the wavelenght of this sine curve
  /// @param angleIncrement used to increment the angle of this sine curve.
  Sine(double amplitude, double wavelength, double angleIncrement);

  /// @return The current angle of this sine curve in degrees.
  double currentAngle();

  ///@return the current y position of this curve using the
  ///        formula for the height of a sine curve.
  double currentHeight();

  /// @brief Increments the angle of this sine curve by its angleIncrement value in a prefix fashion.
  /// @return a reference to this sine curve after incrementing its angle.
  Sine& operator++();

  /// @brief Increments the angle of this sine curve its angleIncrement value in a postfix fashion.
  /// @param int a dummy int parameter.
  /// @return a copy to the current sine curve before incrementing its angle.
  Sine operator++(int); //postfix++, dummy parameter, returns a value

  /// @brief overloads the << operator for a Sine object,
  ///        outputs a string in the form: "currentAngle, currentHeight".
  /// @param output a reference to the output stream.
  /// @param sineCurve the sine curve whose information is to be outputted.
  /// @return a reference to the modified output stream.
  friend std::ostream& operator<<(std::ostream& output, Sine sineCurve);
};
#endif