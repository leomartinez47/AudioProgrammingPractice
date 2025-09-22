#include "Waveform.h"
#include "Wav.h"


int main() {
  Wav writeSquare(1);
  Wav writeSaw(1);
  Wav writeTriangle(1);
  Wav writeSine(1);

  Waveform squareWave("square", 15000, 440, 44100, 1);
  Waveform sawWave("saw", 15000, 440, 44100, 1);
  Waveform triangleWave("triangle", 15000, 440, 44100, 1);
  Waveform sineWave("sine", 15000, 440, 44100, 1); 

  int dataSize = squareWave.getTotalSamples(); //should be the same for all waves

  double squareWaveData[dataSize];
  double sawWaveData[dataSize];
  double triangleWaveData[dataSize];
  double sineWaveData[dataSize];

  for(int i = 0; i < dataSize; i++) {
    squareWaveData[i] = squareWave.currentSampleValue();
    sawWaveData[i] = sawWave.currentSampleValue();
    triangleWaveData[i] = triangleWave.currentSampleValue();
    sineWaveData[i] = sineWave.currentSampleValue();

    squareWave++;
    sawWave++;
    triangleWave++;
    sineWave++;
  }

  double duration = squareWave.getDuration(); // should also be the same for all waves
  writeSquare.writeFile("square", squareWaveData, duration);
  writeSaw.writeFile("saw", sawWaveData, duration);
  writeTriangle.writeFile("triangle", triangleWaveData, duration);
  writeSine.writeFile("sine", sineWaveData, duration);
}