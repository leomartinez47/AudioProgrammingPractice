# Leo Martinez
CC = g++

playback: main.o Waveform.o
	$(CC) main.o Waveform.o -o playback -lportaudio

main.o: main.cpp Waveform.h
	$(CC) -c main.cpp

Waveform.o: Waveform.cpp Waveform.h
	$(CC) -c Waveform.cpp

clean:
	rm playback *.o