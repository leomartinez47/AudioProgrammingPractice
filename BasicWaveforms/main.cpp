/* Leo Martinez */
#include "Waveform.h"
#include <iostream>

using namespace std;

int main() {
  //test to see if the square wave setting prints the right values
  Waveform squareWave("square", 15000, 440, 441, 1);
  int dataSize = squareWave.getTotalSamples();
  //just write data so we can check shapes
  for(int i = 0; i < dataSize; i++) {
    cout << squareWave << endl;
    squareWave++;
  }
}