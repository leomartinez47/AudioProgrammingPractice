waveTest:	Sine.o sineTest.o
	g++ Sine.o sineTest.o -o waveTest

sineTest.o: sineTest.cpp Sine.h
	g++ -c sineTest.cpp

Sine.o:	Sine.cpp Sine.h
	g++ -c Sine.cpp

clean: 
	rm waveTest *.o