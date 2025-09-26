/* Leo Martinez */
#include "Waveform.h"
#include "portaudio.h"

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

int main() {
  PaHostApiIndex apiIndex = Pa_HostApiTypeIdToHostApiIndex(paALSA);
  const PaHostApiInfo* hostApiInfo = Pa_GetHostApiInfo(apiIndex);

  PaStreamParameters outputParams;
  outputParams.device = hostApiInfo->defaultOutputDevice; // this is the correct index
  outputParams.channelCount = 1;
  outputParams.sampleFormat = paFloat32;
  outputParams.suggestedLatency = Pa_GetDeviceInfo(outputParams.device)->defaultLowOutputLatency;
  outputParams.hostApiSpecificStreamInfo = nullptr;



  Waveform waveData("sine", 0.5, 440, SAMPLE_RATE, 5);
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
