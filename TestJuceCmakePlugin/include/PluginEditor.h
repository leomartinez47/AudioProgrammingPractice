//
// Created by Leo Martinez on 11/1/2025.
// Code from The Audio Programmer on youtube
// https://www.youtube.com/watch?v=WZCX-RmJN1s&t=1201s
//

#ifndef AUDIOPROGRAMMINGPRACTICE_PLUGINEDITOR_H
#define AUDIOPROGRAMMINGPRACTICE_PLUGINEDITOR_H

#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
  explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
  ~AudioPluginAudioProcessorEditor() override;

  //==============================================================================
  void paint (juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  AudioPluginAudioProcessor& processorRef;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};

#endif //AUDIOPROGRAMMINGPRACTICE_PLUGINEDITOR_H