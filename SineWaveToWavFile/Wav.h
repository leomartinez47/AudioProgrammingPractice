#ifndef WAV_H
#define WAV_H

#include <fstream>
using namespace std;

class Wav {
  // RIFF header
  const string chunkId = "RIFF";
  const string chunkSize = "----";
  const string format = "WAVE";
  // the "WAVE" format consists of two subchunks: "fmt " and "data":
  // fmt subchunk describes the sound data's format
  const string subchunk1Id = "fmt ";
  const int subchunk1Size = 16;
  const int audioFormat = 1;
  const int numChannels;
  const int sampleRate = 44100;
  const int byteRate;
  const int blockAlign;
  const int bitsPerSample = 16;
  // data subchunk contains the size of the data and the actual sound
  const string subchunk2Id = "data";
  const string subchunk2Size = "----";



public:

  Wav(int numChannels);

  /// @brief Writing a value to a file in by specifying a byte size,
  ///        used to write ints to a binary file.
  /// @param file 
  /// @param value 
  /// @param byteSize 
  void writeAsBytes(ofstream &file, int value, int byteSize);

  void writeFile(char* filename, double data[], double duration);
};

#endif