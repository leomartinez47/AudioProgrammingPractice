#ifndef WAV_H
#define WAV_H

#include <fstream>
using namespace std;

/// @brief Sets up encoding and writes some data to a wav file.
class Wav {
  // RIFF header
  const string chunkId = "RIFF";
  const string chunkSize = "----"; // 4 byte placeholder will get filled when size is known
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
  const string subchunk2Size = "----"; // 4 byte placeholder will get filled when size is known

public:
  /// @brief Constructs a Wav object and prepares encoding.
  /// @param numChannels Number of audio channels, either 1 (mono) or 2 (stereo).
  Wav(int numChannels);

  /// @brief Writing a value to a file in by specifying a byte size,
  ///        used to write ints to a binary file.
  /// @param file a reference to the filestream
  /// @param value The value to write.
  /// @param byteSize The size in bytes
  void writeAsBytes(ofstream &file, int value, int byteSize);

  /// @brief Writes all data to the file, writeAsBytes is called in here when needed.
  /// @param filename The name of the file to be saved.
  /// @param data An array of data to fill up the data chunk.
  /// @param duration The duration of the audio in this file, in seconds.
  void writeFile(char* filename, double data[], double duration);
};
#endif