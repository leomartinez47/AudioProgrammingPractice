/* Leo Martinez */
#include "Waveform.h"
#include <iostream>

using namespace std;

int main() {
  // tests to see if each wave setting prints the right values
  // sqaure works
  Waveform squareWave("square", 15000, 440, 44100, 1);
  // saw works
  // Waveform sawWave("saw", 15000, 440, 441, 1);
  // Waveform triangleWave("triangle", 15000, 440, 441, 1); // doesnt work the sample value is only ever 4
  // sine works
  //Waveform sineWave("sine", 15000, 440, 44100, 1); 
  int dataSize = squareWave.getTotalSamples();
  //just write data so we can check shapes
  for(int i = 0; i < dataSize; i++) {
    cout << squareWave << endl;
    squareWave++;
  }
}