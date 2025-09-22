#include "Wav.h"
#include <iostream>
#include <fstream>
#include <string>


Wav::Wav(int numChannels): 
  numChannels(numChannels), 
  byteRate(sampleRate * numChannels * (subchunk1Size / 8)),
  blockAlign(numChannels * (subchunk1Size / 8)) 
  {}

void Wav::writeAsBytes(ofstream &file, int value, int byteSize) {
  file.write(reinterpret_cast<const char*>(&value), byteSize); // taken from tutorial https://www.youtube.com/watch?v=rHqkeLxAsTc
}

// right now this will take one sound wave and put it on one channel in a wav file
// this is fine because one wav should only really be on one channel anyway
// and this function will just write to one channel for now at least
void Wav::writeFile(string filename, double data[], double duration) {
  ofstream wav;
  filename += ".wav";
  wav.open(filename, ios::binary);

  if(wav.is_open()) {
    wav << chunkId;
    wav << chunkSize;
    wav << format;
    
    wav << subchunk1Id;
    writeAsBytes(wav, subchunk1Size, 4);
    writeAsBytes(wav, audioFormat, 2);
    writeAsBytes(wav, numChannels, 2);
    writeAsBytes(wav, sampleRate, 4);
    writeAsBytes(wav, byteRate, 4);
    writeAsBytes(wav, blockAlign, 2);
    writeAsBytes(wav, bitsPerSample, 2);

    wav << subchunk2Id;
    wav << subchunk2Size;

    int startAudio = wav.tellp();

    // write all of the sound data as 2 byte values
    for(int i = 0; i < sampleRate * duration; i++) {
      writeAsBytes(wav, data[i], 2);
    }

    int endAudio = wav.tellp();

    wav.seekp(startAudio - 4); // jump back to where we wrote subchuck2Size
    writeAsBytes(wav, endAudio - startAudio, 4); // subchunk2 size

    wav.seekp(4, ios::beg);
    writeAsBytes(wav, endAudio - 8, 4); // chunkSize
  }
  wav.close();
}