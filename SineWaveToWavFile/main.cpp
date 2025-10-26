#include "Sine.h"
#include "Wav.h"
#include <iostream>
using std::cout;
using std::endl;

/// @brief Creates a Sine wav to represent a 10 second A 440 note and writes the
///        wave data to a wav file.
int main(int argc, char* argv[]) {
  Sine sineWave(15000, 660, 44100, 1);
  Wav wavFile(1);
  int dataSize = sineWave.getTotalSamples();
  double waveData[dataSize];
  for(int i = 0; i < dataSize; i++) {
    waveData[i] = sineWave.currentSampleValue();
    sineWave++;
  }
  wavFile.writeFile(argv[0], waveData, sineWave.getDuration());
}