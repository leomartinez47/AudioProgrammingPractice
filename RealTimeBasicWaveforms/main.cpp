/* Leo Martinez */
#include "Waveform.h"
#include "portaudio.h"
#include <iostream>

using std::cout;
using std::stod;

const int SAMPLE_RATE = 44100;

// a callback function needed by pa
static int callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                    const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,
                    void *waveData) {
  // cast data passed through stream to a Waveform
  Waveform *data = (Waveform*)waveData;
  float *out = (float*)outputBuffer;
  unsigned int i;
  (void) inputBuffer; // prevent unused variable warning
  for( i=0; i<framesPerBuffer; i++ ) {
    // add current sample value to out stream, and increment sample i guess
    *out++ = data->nextSample();
  }
  return 0;
}

/// @brief Takes in a waveform and a frequency as command line arguments and
/// synthesizes the appropriate waveform and plays it in real time.
int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "Error: please provide a waveform and a frequency at runtime";
    return 0;
  }

  Waveform waveData(argv[1], 0.5, stod(argv[2]), SAMPLE_RATE, 5);
  Pa_Initialize();
  PaStream *stream;
  Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, 256, callback, &waveData);

  Pa_StartStream(stream);
  // wait for the duration of the wave while the stream plays
  Pa_Sleep(waveData.getDuration()*1000);
  // stop stream and terminate once playback is done
  Pa_StopStream(stream);
  Pa_Terminate();
}
