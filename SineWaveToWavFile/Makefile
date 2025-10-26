CC = g++

testWav: main.o Sine.o Wav.o
	$(CC) main.o Sine.o Wav.o -o testWav

waveTest:	Sine.o sineTest.o
	$(CC) Sine.o sineTest.o -o waveTest

main.o: main.cpp Sine.h Wav.h
	$(CC) -c main.cpp

Wav.o: Wav.cpp Wav.h
	$(CC) -c Wav.cpp

sineTest.o: sineTest.cpp Sine.h
	$(CC) -c sineTest.cpp

Sine.o:	Sine.cpp Sine.h
	$(CC) -c Sine.cpp

clean: 
	rm testWav *.o