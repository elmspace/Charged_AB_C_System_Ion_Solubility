LFLAGS = -lm -lfftw3 -lstdc++
LIBS = -lm -lstdc++ -lfftw3

main: main.cpp 
	g++ $(LFLAGS) -g -o $@ $(MOBLIB) $(SUBFILES) main.cpp $(LIBS)
