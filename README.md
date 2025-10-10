I love music, music production, and music technology. So naturally I have an interest in audio programming.
This repository is my audio programming learning repo, designed to hold any small projects that I make related to audio/synthesis/dsp.

Taking an assignment from my Software Practice class where we represented a sine curve, I reworked it into
representing a synthesized sine wave. Then I wrote a class to write audio data to a wav file and using the Sine class
created a wav file containing a 10 second sine wave playing an A (440hz).

I expanded the Sine class into a general Waveform class that can represent any one of the four basic waveforms:
sine, square, sawtooth, and triangle waves.

Using the Waveform class and the portaudio library I built RealTimeBasicWaveforms, which can create a Waveform from
command-line input and play it back at runtime which in my head is real time.

In the future I want to build on these ideas even further and create a larger synthesizer application, but baby steps.
