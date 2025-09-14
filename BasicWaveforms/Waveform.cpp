// FOR TRIANGLE 
//sample = 4 |ft - [ft + 1/2]| - 1  f = frequency (htz) t = time (secs)
//but apparently this will be less cpu taxing
// double t = index / sampleRate;
// double phase = fmod(frequency * t, 1.0);
// sample = 4.0 * amplitude * fabs(phase - 0.5) - amplitude;


// FOR SAW
// 2(ft%(1/f))f - 1  f = frequency (htz) t = time (secs)
//
//or sample[sampleindex] = (ampltitude) * (2((f * sampleindex/samplerate) % 1) - 1) 



// FOR SQUARE also this is where i figured out the phase thing 
// sample = AMPLITUDE * sgn(sin(2pi*f*t)) f = frequency (htz) t = time (secs)

//this phase stuff is cool and i think it makes the most sense for square waves
//by my understanding the phase is just a fraction of a wavelenght, so like 1/frequency
//then you increment the phase by frequency/sample rate and just make the sample value
//either AMPLITUDE or -AMPLITUDE based on wethere youre in the first half of the phase
//or the second
//so basically its just a period of the wave
//or an index inside of a period, where 0 is the start and 1 is the end of the period.
//ohhhhhhh yeah this is exactly what I thought a square wave would be so I guess im a genius.

//double phase = 0.0;
// double delta = frequency / sampleRate;

// for (int n = 0; n < bufferSize; ++n) {
//     double sample = (phase < 0.5 ? 1.0 : -1.0);  // square wave in [-1,1]

//     phase += delta;
//     if (phase >= 1.0) phase -= 1.0;

//     buffer[n] = sample;
//}
