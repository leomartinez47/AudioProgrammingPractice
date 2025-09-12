
#include "Sine.h"
#include <iostream>

using std::cout;
using std::endl;

/// @brief Creates a sine wav and writes out all of its values.
int main() {
  Sine wave(6, 440, 441, 10);
  for(int i = 0; i < wave.getTotalSamples(); i++) {
    cout << wave << endl;
    wave++;
  }
}