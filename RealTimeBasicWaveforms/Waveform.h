/* Leo Martinez */
#ifndef WAVEFORM_H
#define WAVEFORM_H
#include <iostream>

/// @brief This class represents a synthesized sound wave that represents any one of the 
///        four basic waveforms: sine, square, triangle, and sawtooth waves.
class Waveform{
  // an enum to represent the four possible waveforms this class will represent
  enum Form {
    SINE,
    SQUARE,
    SAW,
    TRIANGLE
  };

  double amplitude, frequency, sampleRate, duration, sampleIndex, totalSamples, sampleIncrement;
  Form form;

  int sign(double val);

public:

  /// @brief Constructs a Sine object with an angle of 0.
  /// @param amplitude the amplitude of this sine wave.
  /// @param frequency the frequency of this sine wave.
  /// @param sampleRate the number of sample per second of this sine wave.
  /// @param duration the duration of this sine wave in seconds.
  /// @param form the waveform that this object represents.
  Waveform(const char* waveform, double amplitude, double frequency, double sampleRate, double duration);

  /// @return The current sample index of this wave, essentially the x position if visualized.
  double currentSampleIndex();

  /// @return the current sample value of this wave at the current index.
  double currentSampleValue();

  /// @return the total number of samples of this wave.
  double getTotalSamples();

  /// @return the duration of this wave in seconds.
  double getDuration();

  /// @brief returns current sample and increments sampleIndex
  float nextSample();

  /// @brief Increments the sampleIndex of this wave by the sampleIncrement (1/totalSamples) in a prefix fashion.
  /// @return a reference to this sine curve after incrementing its angle.
  Waveform& operator++();

  /// @brief Increments the sampleIndex this wave by the sampleIncrement (1/totalSamples) in a postfix fashion.
  /// @param int a dummy int parameter.
  /// @return a copy to the current sine curve before incrementing its angle.
  Waveform operator++(int); //postfix++, dummy parameter, returns a value

  /// @brief overloads the << operator for a Waveform object,
  ///        outputs a string in the form: "currentSampleIndex, currentSampleValue".
  /// @param output a reference to the output stream.
  /// @param wave the wave whose information is to be outputted.
  /// @return a reference to the modified output stream.
  friend std::ostream& operator<<(std::ostream& output, Waveform wave);

};
#endif