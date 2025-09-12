
#include "Sine.h"
#include "Wav.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  Sine sineWave(15000, 440, 44100, 10);
  Wav wavFile(1);
  int dataSize = sineWave.getTotalSamples();
  double waveData[dataSize];
  for(int i = 0; i < dataSize; i++) {
    waveData[i] = sineWave.currentSampleValue();
    sineWave++;
  }
  wavFile.writeFile(argv[0], waveData, sineWave.getDuration());
}
