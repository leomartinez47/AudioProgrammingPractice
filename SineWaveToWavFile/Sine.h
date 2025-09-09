/*
Leo Martinez, 
CS3505, Assignment 2, Making a class.
*/
#ifndef SINE_H
#define SINE_H
#include <iostream>

/// @brief A Sine object represents a sine wave with an amplitude, a frequency, a sample rate
///        a duration in seconds, an index or current position, and a total samples value. 
//         Sine Objects begin at index 0 and the index is incremented by 1/totalSamples using the ++ operator
///        in either a prefix or postfix manner.



// rewrite to work in the format SAMPLE = AMPLITUDE * sin(2π * FREQUENCY * INDEX / SAMPLERATE)
// where the sample index = angle, wavelength = samples per cycle or samplerate/frequency
// height = audio sample value
class Sine {

  /// The amplitude, wavelength, angleIncrement, and angle variables for this sine curve.
  double amplitude, frequency, sampleRate, duration, sampleIndex, totalSamples, sampleIncrement;
  

public:
  /// @brief Constructs a Sine object with an angle of 0.
  /// @param amplitude the amplitude of this sine wave.
  /// @param frequency the frequency of this sine wave.
  /// @param sampleRate the number of sample per second of this sine wave.
  /// @param duration the duration of this sine wave in seconds
  Sine(double amplitude, double frequency, double sampleRate, double duration);

  /// @return The current sample index of this sine wave, essentially the x position if visualized.
  double currentSampleIndex();

  /// @return the current sample value of this sine wave at the current index.
  double currentSampleValue();

  /// @return the total number of samples of this sine wave
  double getTotalSamples();

  /// @brief Increments the sampleIndex of this sine curve by the sampleIncrement (1/totalSamples) in a prefix fashion.
  /// @return a reference to this sine curve after incrementing its angle.
  Sine& operator++();

  /// @brief Increments the angle of this sine curve by the sampleIncrement (1/totalSamples) in a postfix fashion.
  /// @param int a dummy int parameter.
  /// @return a copy to the current sine curve before incrementing its angle.
  Sine operator++(int); //postfix++, dummy parameter, returns a value

  /// @brief overloads the << operator for a Sine object,
  ///        outputs a string in the form: "currentSampleIndex, currentSampleValue".
  /// @param output a reference to the output stream.
  /// @param sineWave the sine wave whose information is to be outputted.
  /// @return a reference to the modified output stream.
  friend std::ostream& operator<<(std::ostream& output, Sine sineWave);
};
#endif