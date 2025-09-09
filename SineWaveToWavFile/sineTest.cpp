
#include "Sine.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Sine wave(6, 440, 44100, 1);
  for(int i = 0; i < wave.getTotalSamples(); i++) {
    cout << wave << endl;
    wave++;
  }
}