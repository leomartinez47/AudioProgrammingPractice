/* Leo Martinez */
#include "Waveform.h"
#include <iostream>

using namespace std;

int main() {
  // tests to see if each wave setting prints the right values
  // sqaure works
  // Waveform squareWave("square", 15000, 440, 441, 1);
  // saw works
  // Waveform sawWave("saw", 15000, 440, 441, 1);
  // Waveform triangleWave("triangle", 15000, 440, 441, 1); // doesnt work the sample value is only ever 4
  Waveform sineWave("sine", 15000, 440, 441, 1); // the wave is negative for some reason look into that
  int dataSize = sineWave.getTotalSamples();
  //just write data so we can check shapes
  for(int i = 0; i < dataSize; i++) {
    cout << sineWave << endl;
    sineWave++;
  }
}